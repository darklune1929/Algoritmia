#include <stdio.h>
#include <stdlib.h>
#define mayor(x,y)  (x>y)? x : y

int calcularfila(int** almacen,int iteracion,int comienzo,int n){
    if(comienzo==n) return 0;
    return almacen[iteracion][comienzo] + calcularfila(almacen,iteracion,comienzo+1,n);
}
int calcularcolumna(int** almacen,int iteracion,int comienzo,int n){
    if(comienzo==n) return 0;
    return almacen[comienzo][n] + calcularcolumna(almacen,iteracion,comienzo+1,n);
}
int calcularAlmacen(int** almacen,int iteracion,int n){
    if(iteracion==n) return 0;
    int fila=0,columna=0;
    fila = calcularfila(almacen,iteracion,0,n-iteracion);
    columna = calcularcolumna(almacen,iteracion,iteracion+1,n);
    int total=0;
    total = fila + columna;
    return mayor(total,calcularAlmacen(almacen,iteracion+1,n));
}
int main(){
    int n;
    printf("Ingrese el numero n: ");
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

    int mayor=0;
    mayor = calcularAlmacen(almacen,0,n);
    printf("El mayor resultado es: %d",mayor);
    return 0;
}
