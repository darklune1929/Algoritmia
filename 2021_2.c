#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Ingrese el numero n: ");6
    scanf("%d",&n);
    int **almacen = (int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        almacen[i] = (int*)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            scanf("%d",&(almacen[i][j]));
        }
    }
    printf("\nDatos del almacen:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",almacen[i][j]);
        }
        printf("\n");
    }
    return 0;
}