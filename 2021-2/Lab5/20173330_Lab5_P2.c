#include <stdio.h>
#include <stdlib.h>
//empiezo en la columna 0 y fila 0 por eso paso el 0,0
int robot_cortador_BT(int n,int m,int c,int listones_max,int tablero[][m],int fila,int columna,int cantidad
                        int mov_x,int mov_y){
    int next_x,next_y;
    int bt_return;
    if(cantidad==listones_max)return 1;
    else{
            for(int i=0;i<4,i++){
                    next_x = fila + mov_x[i];
                    next_y = columna + mov_y[i];
            for(int k=fila;k<=next_x,k++)
                for(int l=columna;l<=next_y,l++)
                    tablero[k][l]=cantidad;
            if(is_valid(n,m,c,tablero,fila,columna,next_x,next_y)){
            bt_return = robot_cortador_BT( n, m, c, listones_max, tablero, fila, columna, cantidad+1,mov_x,mov_y);
            if(bt_return) return 1;
             else{

            }
            }
            }

    }
    
}
int main(){
    int  c,n,m;
    printf("Ingrese el valor de m:");
    scanf("%d",&m);
    printf("Ingrese el valor de n:");
    scanf("%d",&n);
    printf("Ingrese el valor de c:");
    scanf("%d",&c);
    int tablero[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            tablero[i][j]=-1;
    int r;
    int listones_max= n*m/c;
    int mov_x[4]={0,0,1,-1};
    int mov_y[4]={1,-1,0,0};
    r = robot_cortador_BT(n,m,c,listones_max,tablero,0,0,0,mov_x,mov_y);
    if(r){
        for (int i=0; i<n; i++) {
	        for (int j=0; j<m; j++){
		        printf(" %2d ", tablero[i][j]);
            }
            printf("\n");
        }
    } else{
        printf("No se encontro respuesta para el problema");
    }

    return 0;
}
