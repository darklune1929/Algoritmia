#include <stdio.h>
#include <stdlib.h>
#define  max(a,b) ((a>b)? a:b)
/* 8
10 20 15 10 12 10 13 18 */
int mezcla(int ini,int medio,int fin,int* cantidades){
    int cizq=0,cder=0;

    for(int i=medio;i>ini;i--){
        if(cantidades[i]>cantidades[i-1]) cizq++;
        else
            break;
    }
    for(int i=medio;i<fin;i++){
        if(cantidades[i+1]>cantidades[i]) cder++;
        else
            break;
    }
    return cder+cizq+1;
}
int intervaloMaximo(int ini,int fin,int* cantidades){
    int medio,izq,der,centro;
    if(ini==fin) return 1;

    medio = (ini+fin)/2;
    izq = (intervaloMaximo(ini,medio,cantidades));
    der = (intervaloMaximo(medio+1,fin,cantidades));
    centro = mezcla(ini,medio,fin,cantidades);

    return max(max(izq,der),centro);
}
int main(){
    int dias,maximo;
    printf("Ingrese la cantidad de dias: ");
    scanf("%d",&dias);
    int cantidades[dias];
    for(int i=0;i<dias;i++){
        scanf("%d",&cantidades[i]);
    }
    for(int i=0;i<dias;i++){
        printf("%d ",cantidades[i]);
    }
    maximo = intervaloMaximo(0,dias-1,cantidades);
    double indice;
    indice = (double)maximo*100/dias;
    printf("\nEl maximo intervalo de contagios es %d dias con un indice de %0.3lf%%\n",maximo,indice);

}
