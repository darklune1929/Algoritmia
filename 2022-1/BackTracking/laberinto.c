#include <stdio.h>
#include <stdlib.h>
void copiarLaberinto(int** laberinto,int** tablero,int m,int n){
    for(int i=0;i<m;i++){
        tablero[i] = (int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            tablero[i][j] = laberinto[i][j];
        }
    }

}
int is_safe(int** tablero,int n,int m,int x,int y){
    return (x>=0 && x<n && y>=0 && y<m && tablero[x][y] == 0);
}
int detectarCamino(int** tablero,int n,int m,int k,int x,int y,int* x_move,int* y_move){
    int next_x,next_y,bt_return;
    if(x==n-1 && y== m-1){
        return 1;
    } else{
		for (int t=0; t<4; t++){
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
int crearLaberinto(int** laberinto,int m,int n,int x,int y,int* x_move,int* y_move){
    int next_x,next_y,bt_return;
    int **tablero = (int**)malloc(m*sizeof(int*));
    if(x==n-1 && y== m-2){
        return 1;
    } else{
		for (int t=0; t<4; t++){
			next_x = x + x_move[t];
			next_y = y + y_move[t];
            copiarLaberinto(laberinto,tablero,m,n);
			if (detectarCamino(tablero,m,n,2,0,0,x_move,y_move)){
                laberinto[x][y] = 1;
				bt_return = crearLaberinto(laberinto,m,n,next_x,next_y,x_move,y_move);
				if (bt_return)
					return 1;
				else{
					laberinto[next_x][next_y] = 0; // backtracking
                }
			}
		}
		return 0;
    }    
}

int main(){
    int m,n;
	int x_move[4] = {1,0,-1,0};
	int y_move[4] = {0,-1,0,1};
    printf("Ingrese las dimensiones del laberinto m x n: ");
    scanf("%d %d",&m,&n);
    int **laberinto = (int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        laberinto[i] = (int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            laberinto[i][j] = 0;
        }
    }
    laberinto[1][0] = 1;
    if(crearLaberinto(laberinto,m,n,1,0,x_move,y_move)){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                printf("%02d ",laberinto[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No se pudo crear un laberinto\n");
    }
    return 0;
}