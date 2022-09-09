#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max(x,y) (((x)>(y))? (x) : (y))
#define min(x,y) (((x)>(y))? (y) : (x))
int calcular_tiempo(int** tabla,int* tiempos,int N,int R){
    int sum = 0;
    for(int i=0;i<=N;i++){
        tabla[i][0] = 0;
    }
    for(int i=1;i<=N;i++){
        sum += tiempos[i-1];
        tabla[i][1] = sum;
    }
    for(int i=0;i<=R;i++){
        tabla[0][i] = 0;
    }
    for(int i=2;i<=R;i++){
        int sum_max_tareas=0;
        for(int j=1;j<=N;j++){
            sum_max_tareas = max(max(tabla[j][i-1]-tabla[j-1][i],tabla[j-1][i]),tiempos[j-1]);
            tabla[j][i] = sum_max_tareas;
        }
    }
    return tabla[N-1][R-1];
}
int main(){
    int N=5;
    int tiempos[] = {15,30,60,45,10};
    int R=2;
    int** tabla = (int**)malloc((N+1)*sizeof(int*));
    for(int i=0;i<=N;i++){
        tabla[i] = (int*)malloc((R+1)*sizeof(int));
        for(int j=0;j<R;j++){
        }
    }

    int tiempo = calcular_tiempo(tabla,tiempos,N,R);
    printf("El tiempo máximo que utilizarian %d robots es %d min\n",R,tiempo);
    for(int i=0;i<N;i++){
        printf("%d ",tiempos[i]);
    }
    printf("\n");
    for(int i=0;i<N+1;i++){
        for(int j=0;j<R+1;j++){
            printf("%02d ",tabla[i][j]);
        }
        printf("\n");
    }    

    return 0;
}