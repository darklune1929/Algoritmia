#include <stdio.h>
#include <stdlib.h>
int is_safe(int** tablero,int n,int m,int x,int y){
    return (x>=0 && x<n && y>=0 && y<m && tablero[x][y] == 0);
}
int detectarCamino(int** tablero,int n,int m,int k,int x,int y,int* x_move,int* y_move){
    int next_x,next_y,bt_return;
    if(x==n-1 && y== m-1){
        return 1;
    } else{
		for (int t=0; t<8; t++){
			next_x = x + x_move[t];
			next_y = y + y_move[t];
			if (is_safe(tablero,n,m,next_x,next_y)){
				tablero[next_x][next_y] = k;
				bt_return = detectarCamino(tablero,n,m,k+1,next_x,next_y,x_move,y_move);
				if (bt_return)
					return 1;
				else{
					tablero[next_x][next_y] = 0; // backtracking
                }
			}
		}
		return 0;
    }
}
void mostrar_tablero(int** tablero,int n,int m){
	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++){
            // * para las minas y - para los espacios vacios mientras que los lugares que recorri tienen
            // un numero que va creciendo empezando por el 2 en el tablero[0][0]
            if(tablero[i][j]==1){
                printf(" * ");
            } else if(tablero[i][j] == 0){
                printf(" - ");
            } else{
                printf(" %c ",'A' + tablero[i][j]-2);
            }
        }
		printf("\n");
	}    
}
int main() {
    int n,m;
    printf("Ingresar dimensiones del tablero n x m: ");
    scanf("%d %d",&n,&m);
    int** tablero = (int**)malloc(n*sizeof(int*));    
    printf("Ingrese los datos del tablero minas(1) y zonas seguras(0):");
    for(int i=0;i<n;i++) {
        tablero[i] = (int*)malloc(m*sizeof(int));
        for (int j=0;j<m;j++) {
            scanf("%d",&(tablero[i][j]));
        }
    }
    //movimientos disponibles en el campo
	int x_move[8] = { 1, 1, 0,-1, -1,-1, 0, 1};
	int y_move[8] = { 0, 1, 1, 1, 0,-1,-1,-1};
    int x=0,y=0;
    tablero[0][0] = 2;
    if(detectarCamino(tablero,n,m,3,x,y,x_move,y_move)){
        printf("\n");
        mostrar_tablero(tablero,n,m);
    } else{
        printf("No se encontro solución para el campo dado\n");
    }
    return 0;
}