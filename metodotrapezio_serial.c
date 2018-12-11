#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <omp.h>
#include "mede_time.h"


double f(double x);
double f(double x)
{
  return 1.0 / exp(x);
} 


double g(double x){

}

double h(double x){

}

int main(){
    int n; //numero de particoes
    double a, b; //intervalo de integracao
    double x; //valor de x onde a funcao e calculada
    double delta; //tamanho de cada particao
    double sum  = 0; //soma da integral
    printf("Digite o tamanho do step: ");
    fflush(stdout);
    scanf("%lf", &delta);
    printf("Digite o limite inferior: ");
    fflush(stdout);
    scanf("%lf", &a);
    printf("Digite o limite superior: ");
    fflush(stdout);
    scanf("%lf", &b);
    n = (int) (b-a)/delta;
    x=a;

    TIMER_CLEAR;  
    TIMER_START;
    for(int i = 1; i < n-1; i++){
        sum = sum + f(x) + f(x+delta);
        x = x + delta;
    }
    sum = sum * delta/2;
    TIMER_STOP;
    printf ("TEMPO EXECUCAO: %12.7f",TIMER_ELAPSED );
    printf("\nO resultado da integral e: %lf\n", sum);

    return 0;
}

   
