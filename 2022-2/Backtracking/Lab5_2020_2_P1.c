#include <stdio.h>
#include <stdlib.h>
int valido(int x,int y,int** solucion,int n){
    if(x<n && x>=0 && y<n && y>=0 && solucion[x][y]==0) return 1;
    return 0;
}
int resolverAlmacen(int** almacen,int** solucion,int* arreglo,int* mov_x,int* mov_y,int x,int y,int n,int c,int cont){
    int next_x,next_y;
    if(cont==0){
        return 1;
    }
    if(x==n && y==n) return 0;
    for(int i=0;i<2;i++){
        next_x = x + mov_x[i];
        next_y = y + mov_y[i];
        if(valido(next_x,next_y,solucion,n)){
            int j;
            for(j=0;j<c;j++){
                if(almacen[next_x][next_y]==arreglo[j] && solucion[next_x][next_y]==0){
                    solucion[next_x][next_y] = arreglo[j];
                    arreglo[j] = -1;
                    cont--;
                    break;
                }
            }
            if(resolverAlmacen(almacen,solucion,arreglo,mov_x,mov_y,next_x,next_y,n,c,cont))  return 1;
            arreglo[j] = solucion[next_x][next_y];
            solucion[next_x][next_y] = 0;
        }
    }
    return 0;
}
int main(){
    int n,c;
    printf("Ingrese los datos n y c: ");
    scanf("%d %d",&n,&c);
    printf("Ingrese los datos del almacen\n");
    int** almacen = (int**)malloc((n)*sizeof(int*));
    for(int i=0;i<n;i++){
        almacen[i] = (int*)malloc((n)*sizeof(int));
        printf("Ingrese los datos de la fila %d: ",i+1);
        for(int j=0;j<n;j++){
            scanf(" %d",&almacen[i][j]);
        }
    }
    int arreglo[c];
    printf("Ingrese los datos del pedido: ");
    for(int i=0;i<c;i++){
        scanf(" %d",&arreglo[i]);
    }
    int** solucion = (int**)malloc((n)*sizeof(int*));
    for(int i=0;i<n;i++){
        solucion[i] = (int*)malloc((n)*sizeof(int));
        for(int j=0;j<n;j++){
            solucion[i][j] = 0;
        }
    }
    int mov_x[2] = {1,0};
    int mov_y[2] = {0,1};
    int sol;
    sol = resolverAlmacen(almacen, solucion,arreglo, mov_x, mov_y,0,0,n,c,c);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%02d ",almacen[i][j]);
        }
        printf("\n");
    }
    printf("Lista de pedido: ");
    for(int i=0;i<c;i++){
        printf("%02d ",arreglo[i]);
    }
    printf("\n");
    if(sol){
        printf("La solucion es: \n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%02d ",solucion[i][j]);
            }
            printf("\n");
        }
    } else{
        printf("No hay solucion dada la lista de pedidos");
    }


    return 0;
}