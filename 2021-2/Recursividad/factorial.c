#include <stdio.h>
unsigned long long int factorial(int n){
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}
int main(){
    int n;
    printf("Ingrese el numero: ");
    scanf("%d",&n);

    printf("El factorial de %d es %llu.\n",n,factorial(n));
    return 0;
}