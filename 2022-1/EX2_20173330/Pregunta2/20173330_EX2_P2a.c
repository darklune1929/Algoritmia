#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max(x,y) (((x)>(y))? (x) : (y))
#define min(x,y) (((x)>(y))? (y) : (x))
int calcular_tiempo(int* solucion,int tiempos[5],int N,int R){
    for(int i=0;i<R;i++){
        solucion[i] =  tiempos[i];
    }
    for(int i=R;i<N;i++){
        int minimo= solucion[i-R];
        for(int j=i-R;j<i;j++){
            minimo = min(solucion[j],minimo);
        }
        solucion[i] = tiempos[i] + minimo;
    }
    int mayor = 0;
    for(int i=N-1;i>=N-R;i--){
        mayor = max(solucion[i],mayor);
    }
    return mayor;
}
int main(){
    int N=5;
    int tiempos[] = {15,30,60,45,10};
    int R=2;
    int* solucion = (int*)malloc((N)*sizeof(int));


    int tiempo = calcular_tiempo(solucion,tiempos,N,R);
    printf("El tiempo maximo que utilizarian %d robots es %d min\n",R,tiempo);
    for(int i=0;i<N;i++){
        printf("%d ",tiempos[i]);
    }
    printf("\n");
    for(int i=0;i<N;i++){
            printf("%02d ",solucion[i]);
    }    

    return 0;
}
