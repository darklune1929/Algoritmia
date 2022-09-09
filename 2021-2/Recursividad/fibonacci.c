#include <stdio.h>
unsigned long long int fibonacci(int n){
    if(n==1) return 0;
    else if(n==2) return 1;
    else return fibonacci(n-2)+fibonacci(n-1);
}

int main(){
    int n;
    printf("Ingrese la posicion de la serie de Fibonacci que quiere calcular: ");
    scanf("%d",&n);
    printf("La posicion %d de la serie de Fibonacci es: %llu \n",n,fibonacci(n));
    return 0;
}