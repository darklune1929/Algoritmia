#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (((x)>(y))? (x) : (y))
int calcular_ganancia(int** tabla,int* cambios,int N,int K){
    int menor = INT_MAX;
    int maximo = 0;
    int contador = 0;
    for(int i=0;i<=N;i++){
        tabla[i][0] = 0;
    }
    for(int i=0;i<=K;i++){
        tabla[0][i] = 0;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            if((cambios[i-1]<menor) && 1){
            }
        }
    }
}
int main(){
    int N=6;
    int cambios[] = {315,322,385,375,365,380};
    int K=1;
    int** tabla = (int**)malloc((N+1)*sizeof(int*));
    for(int i=0;i<=N;i++){
        tabla[i] = (int*)malloc((K+1)*sizeof(int));
    }

    int ganancia = calcular_ganancia(tabla,cambios,N,K);
    for(int i=0;i<N;i++){
        printf("%d ",cambios[i]);
    }
    printf("\n");
    for(int i=0;i<N+1;i++){
        for(int j=0;j<K+1;j++){
            printf("%02d ",tabla[i][j]);
        }
        printf("\n");
    }    

    return 0;
}