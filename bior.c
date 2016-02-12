/**
 * Autor: AndreFRocha
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define DELTA 0.000001
#define DIM 31 /* dimensao maxima para um vector mes */

/* prototipos de funcoes */

int menu( void );

int numDias( int diaN, int mesN, int anoN, int mes, int ano );
int diasDoAno( int ano );
int diasDoMes( int ano, int mes );
int anoInic( int diaN, int mesN, int anoN );
int somaAnos( int anoN, int ano );
int anoLim( int mes, int ano );
int anoUnic ( int diaN, int mesN, int mes, int ano );

void tabela( int mes, int ano, int t, int lim );
double fisico( int t );
double emocional( int t );
double mental( int t );

void diasPos( int t, int lim );
int zeroComp( double n );

void diasMax( int t, int lim );

void diasNull( int t, int lim );

void apresentaGrafico( double bio[], int dias, char c );
void inicVector( double v[], int t, int qRitmo, int lim );

int main( void ){ /* inicio da main */

  int diaN, mesN, anoN, mes, ano, t, dDMes, opcao = 1;
  double bio[DIM];

  printf( "Bem vindo ao calculador de biorritmos\n"
          "Introduza a data de nascimento e o mes a analisar:\n" );
  scanf( "%d%d%d%d%d", &diaN, &mesN, &anoN, &mes, &ano );
  t = numDias( diaN, mesN, anoN, mes, ano );
  dDMes = diasDoMes( ano, mes );
  printf( "\n" );
  while( opcao != 0 ){ /* inicio do ciclo */
    opcao = menu(); 
    switch( opcao ){ /* inicio do switch */
    case 1:
      printf( "\n%d\n\n", t );
      break;
    case 2:
      printf( "\n" );
      tabela ( mes, ano, t, dDMes );
      printf( "\n" );
      break;
    case 3:
      printf( "\n" );
      diasPos( t, dDMes );
      printf( "\n\n" );
      break;
    case 4:
      printf( "\n" );
      diasMax( t, dDMes );
      printf( "\n\n" );
      break;
    case 5:
      printf( "\n" );
      diasNull( t, dDMes );
      printf( "\n\n" );
      break;
    case 6:
      printf( "\nGrafico do biorritmo fisico:\n" );
      inicVector( bio, t, 1, dDMes );
      apresentaGrafico( bio, dDMes, '.' );
      printf( "\n" );
      break;
    case 7:
      printf( "\nGrafico do biorritmo emocional:\n" );
      inicVector( bio, t, 0, dDMes );
      apresentaGrafico( bio, dDMes, '+' );
      printf( "\n" );
      break;
    case 8:
      printf( "\nGrafico do biorritmo mental\n" );
      inicVector( bio, t, -1, dDMes );
      apresentaGrafico( bio, dDMes, '*' );
      printf( "\n" );
      break;
    case 9:
      printf( "Introduza a data de nascimento e o mes a analisar:\n" );
      scanf( "%d%d%d%d%d", &diaN, &mesN, &anoN, &mes, &ano );
      t = numDias( diaN, mesN, anoN, mes, ano );
      dDMes = diasDoMes( ano, mes );
      printf( "\n" );
      break;
    case 0:
      break;
    default:
      opcao = 0;
    } /* fim do switch */
  } /* fim do while */
    printf( "\nTerminou a execucao!\n" );

    return 0;
} /* fim da main */

/**
 * funcao que imprime menu e recolhe o valor da opcao
 */

int menu( void ){

  int numOp;

  printf( "Menu:\n"
          "1 - Numero de dias decorridos desde a data de nascimento\n"
          "2 - Tabela de biorritmos para o mes\n"
          "3 - Dias positivos no mes\n"
          "4 - Dias maximos no mes\n"
          "5 - Dias nulos no mes\n"
          "6 - Grafico do biorritmo fisico ao longo do mes\n"
          "7 - Grafico do biorritmo emocional ao longo do mes\n"
          "8 - Grafico do biorritmo mental ao longo do mes\n"
          "9 - Introduzir novos dados\n"
          "0 - Sair\n"
          "Opcao: " );
  scanf( "%d", &numOp );

  return numOp;
} /* fim da funcao */

/**
 * funcao que calcula os dias desde o nascimento ate o primeiro dia do mes
 */

int numDias( int diaN, int mesN, int anoN, int mes, int ano ){

  int somatorioDias = 0;

  if( anoN == ano )
    somatorioDias = anoUnic( diaN, mesN, mes, ano ) + 1;
  else
    somatorioDias = anoInic( diaN, mesN, anoN ) + somaAnos( anoN, ano ) + anoLim( mes, ano ) + 1;

  return somatorioDias;
} /* fim da funcao */

/**
 * funcao que calcula o numero de dias num ano
 */

  int diasDoAno (int ano){

    int dias = 365;

    if (ano%4 == 0)
      dias++;

    return dias;
  }  /* fim da funcao */

/**
 * funcao que calcula o numero de dias num mes
 */

 int diasDoMes (int ano, int mes){

    int dias;

    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
      dias = 31;
    else if ( mes == 2 ){ /* inicio do if */
      if ( ano % 4 == 0)
	dias = 29 ;
      else dias = 28 ;
    } /* fim do if */
    else dias = 30;

    return dias;
 } /* fim da funcao */

/**
 * funcao que calcula o numero de dias desde
 * o nascimento ate ao fim do proprio ano
 */
  
int anoInic ( int diaN, int mesN, int anoN ){
  
  int m, soma = 0;

    soma = diasDoMes(anoN, mesN) - diaN;
    m = mesN + 1;
    while( m <= 12 ){ /* inicio do ciclo */
      soma += diasDoMes(anoN, m);
      m++;
    } /* fim do while */

  return soma; 
} /* fim da funcao */

/**
 * funcao que calcula o total de dias entre
 * o ano de nascimento e o ano a avaliar
 */

int somaAnos ( int anoN, int ano ){

  int conta, soma = 0;

  conta = anoN + 1;
  while( conta < ano ){ /* inicio do ciclo */
    soma += diasDoAno(conta);
    conta++;
  } /* fim do while */

  return soma;
} /* fim da funcao */

/**
 * funcao que calcula os dias ja ocorridos do ano a avaliar
 */

int anoLim ( int mes, int ano ){

  int m = 1, soma = 0;

  while( m < mes ){ /* inicio do ciclo */
    soma += diasDoMes(ano, m);
    m++;
  } /* fim do while */

  return soma;
} /* fim da funcao */

/**
 * funcao que calcula, no caso extraordinario do ano de nascimento ser
 * tambem o ano a avaliar, os dias ocorridos entre ambos os eventos
 */

int anoUnic ( int diaN, int mesN, int mes, int ano ){

  int m, soma = 0;

  soma = diasDoMes(ano, mesN) - diaN;
  m = mesN + 1;
  while( m < mes ){ /* inicio do ciclo */
    soma += diasDoMes(ano, m);
    m++;
  } /* fim do while */

  return soma;
} /* fim da funcao */

/**
 * funcao que calcula o biorritmo fisico para um dia t
 */

double fisico( int t ){

  return sin( 2 * PI * t / 23 ) * 10;
} /* fim da funcao */

/**
 * funcao que calcula o biorritmo emocional para um dia t
 */

double emocional( int t ){

  return sin( 2 * PI * t / 28 ) * 10;
} /* fim da funcao */

/**
 * funcao que calcula o biorritmo mental para um dia t
 */

double mental( int t ){

  return sin( 2 * PI * t / 33 ) * 10;
} /* fim da funcao */

/**
 * funcao que imprime tabela dos biorritmos ao longo do mes
 */

void tabela( int mes, int ano, int t, int lim ){

  int dias, contador = 1;

  dias = t;
  printf( "biorritmos do mes %d %d:\n", mes, ano );
  printf( "         dia      fisico   emocional      mental\n" );
  while ( contador <= lim ){ /* inicio do ciclo */
    printf( "%12d%12.6f%12.6f%12.6f\n", contador, fisico( dias ), emocional( dias ), mental( dias ) );
    contador++;
    dias++;
  } /* fim do while */
} /* fim da funcao */

/**
 * funcao que calcula e imprime os dias positivos
 */

void diasPos( int t, int lim ){

  int dias, contador = 1;

  dias = t;
  while ( contador <= lim ){ /* inicio do ciclo */
    if( !zeroComp( fisico( dias ) ) && ( fisico( dias ) > 0 ) &&
( ( fisico( dias + 1 ) > 0 ) || zeroComp( fisico( dias + 1 ) ) ) && !zeroComp( emocional( dias ) ) &&
( emocional( dias ) > 0 ) && ( ( emocional( dias + 1 ) > 0 ) || zeroComp( emocional( dias + 1 ) ) ) )
      printf( "%d ", contador );
    else if( !zeroComp( emocional( dias ) ) && ( emocional( dias ) > 0 ) &&
( ( emocional( dias + 1 ) > 0 ) || zeroComp( emocional( dias + 1 ) ) ) && !zeroComp( mental( dias ) ) &&
( mental( dias ) > 0 ) && ( ( mental( dias + 1 ) > 0 ) || zeroComp( mental( dias + 1 ) ) ) )
      printf( "%d ", contador );
    else if( !zeroComp( fisico( dias ) ) && ( fisico( dias ) > 0 ) &&
( ( fisico( dias + 1 ) > 0 ) || zeroComp( fisico( dias + 1 ) ) ) && !zeroComp( mental( dias ) ) &&
( mental( dias ) > 0 ) && ( ( mental( dias + 1 ) > 0 ) || zeroComp( mental( dias + 1 ) ) ) )
      printf( "%d ", contador );
    contador++;
    dias++;
  } /* fim do while */
} /* fim da funcao */

/**
 * funcao que compara um double a zero
 */

int zeroComp( double n ){

  double z = 0;

  return ( ( n < ( z + DELTA ) ) && ( n > ( z - DELTA ) ) );
} /* fim da funcao */

/**
 * funcao que calcula e imprime os dias maximos
 */

void diasMax( int t, int lim ){

  int dias, contador = 1;

  dias = t;
  while( contador <= lim ){ /* inicio do ciclo */
    if( ( fisico( dias - 1 ) < fisico( dias ) ) && ( fisico( dias ) > fisico( dias + 1 ) ) )
      printf( "%d ", contador );
    else if( ( emocional( dias - 1 ) < emocional( dias ) ) && ( emocional( dias ) > emocional( dias + 1 ) ) )
      printf( "%d ", contador );
    else if( ( mental( dias - 1 ) < mental( dias ) ) && ( mental( dias ) > mental( dias + 1 ) ) )
      printf( "%d ", contador );
    contador++;
    dias++;
  } /* fim do while */
} /* fim da funcao */

/**
 * funcao que calcula e imprime os dias nulos
 */

void diasNull( int t, int lim ){

  int dias, contador = 1;

  dias = t;
  while( contador <= lim ){ /* inicio do ciclo */
    if( zeroComp( fisico( dias ) ) || ( ( ( fisico( dias ) < 0 ) &&
( fisico( dias + 1 ) > 0 ) && !zeroComp( fisico( dias + 1 ) ) ) ||
( ( fisico( dias ) > 0 ) && ( fisico( dias + 1 ) < 0 ) && !zeroComp( fisico( dias + 1 ) ) ) ) )
      printf( "%d ", contador );
    else if( zeroComp( emocional( dias ) ) || ( ( ( emocional( dias ) < 0 ) &&
( emocional( dias + 1 ) > 0 ) && !zeroComp( emocional( dias + 1 ) ) ) ||
( ( emocional( dias ) > 0 ) && ( emocional( dias + 1 ) < 0 ) && !zeroComp( emocional( dias + 1 ) ) ) ) )
      printf( "%d ", contador );
    else if( zeroComp( mental( dias ) ) || ( ( ( mental( dias ) < 0 ) &&
( mental( dias + 1 ) > 0 ) && !zeroComp( mental( dias + 1 ) ) ) ||
( ( mental( dias ) > 0 ) && ( mental( dias + 1 ) < 0 ) && !zeroComp( mental( dias + 1 ) ) ) ) )
      printf( "%d ", contador );
    contador++;
    dias++;
  } /* fim do while */
} /* fim da funcao */

/**
 * funcao que ilustra o grafico de um biorritmo durante um mes
 */

void apresentaGrafico( double bio[], int dias, char c ){

  int i, contaLinhas = 0;

  while( contaLinhas <= 20 ){ /* inicio do ciclo */
    printf( "%3d|", 10 - contaLinhas );
    if( contaLinhas == 10 ){ /* inicio do if */
      for( i = 0; i < dias; i++ ){ /* inicio do ciclo */
        if( floor( bio[i] + 0.5 ) == 0 )
	  printf( "-%c", c );
        else
          printf( "-%d", ( i + 1 ) % 10 );
      } /* fim do for */
      printf( "dias" );
    } /* fim do if */
    else
      for( i = 0; i < dias; i++ ){ /* inicio do ciclo */
        if( floor( bio[i] + 0.5 ) == ( 10 - contaLinhas ) )
          printf( "%c%c", c, c );
        else
          printf( "  " );
      } /* fim do for */
    printf( "\n" );
    contaLinhas++;
  } /* fim do while */
} /* fim da funcao */

/**
 * funcao que atribui os valores de um biorritmo de cada
 * dia aos elementos de um vector mes
 */

void inicVector( double v[], int t, int qRitmo, int lim ){

  int contador, dias;

  dias = t;
  if( qRitmo == 1 )
    for( contador = 0; contador < lim; contador++ )
      v[contador] = fisico( dias + contador );
  else if( qRitmo == 0 )
    for( contador = 0; contador < lim; contador++ )
      v[contador] = emocional( dias + contador );
  else
    for( contador = 0; contador < lim; contador++ )
      v[contador] = mental( dias + contador );
} /* fim da funcao */

/**
 * fim do codigo
 */
