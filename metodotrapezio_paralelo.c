#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

double f(double x){
    return 1/exp(x);
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
    printf("Digite o número de particoes\n");
    fflush(stdout);
    scanf("%d", &n);
    printf("Digite o limite inferior\n");
    fflush(stdout);
    scanf("%lf", &a);
    printf("Digite o limite superior\n");
    fflush(stdout);
    scanf("%lf", &b);
    delta = (b-a)/(n-1);
    x=a;


    for(int i = 1; i < n-1; i++){
        sum = sum + f(x) + f(x+h);
        x = x + h;
    }
    sum = sum * h/2;

    printf("O resultado da integral e: %lf", sum);

    return 0;
}
