#include <stdio.h>
#include <stdlib.h>
//8
//10 20 15 10 12 10 13 18
double calcular_indice_de_incremento(int ini,int fin,double* cantidades,int cont,int contmax){
    int med = (ini+fin)/2;

}
int main(){
    int dias,cont=0,contmax=0;
    printf("Ingrese la cantidad de dias: ");
    scanf("%d",&dias);
    double cantidades[dias];
    for(int i=0;i<dias;i++){
        scanf("%lf",&cantidades[i]);
    }
    for(int i=0;i<dias;i++){
        printf("%.2lf ",cantidades[i]);
    }
    double indice = calcular_indice_de_incremento(0,dias-1,cantidades,cont,contmax);

}
