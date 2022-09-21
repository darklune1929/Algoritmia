#include <stdio.h>

int tablero[6][6] = {{0,0,0,1,0,1},
					 {0,0,1,0,0,0},
					 {0,1,0,0,0,1},
					 {1,0,1,0,0,0},
					 {0,1,0,0,0,0},
					 {0,0,0,0,1,0}};

int cuenta(int posRx,int posRy,int dirX,int dirY,int n, int m, int indBH, int indBV){
	/*Caso base principal, cuando nos salimos del rango de la matriz*/
	int cont=0, i;
	if (posRx<0 || posRx>= n || posRy<0 || posRy>=m){
		return 0;
	}
	if (tablero[posRx][posRy] && indBH==0 && indBV==0){
		cont++;
	}
	if (indBH==0){
		/*Voy a contar los que estan a la derecha desde la posicion del Robot*/
		for (i=posRy+1; i<m; i++){
			cont = cont + tablero[posRx][i];
		}
		/*Voy a contar los que estan a la izquierda desde la posicion del Robot*/
		for (i=posRy-1; i>=0; i--){
			cont = cont + tablero[posRx][i];
		}
	}
	if (indBV==0){
		/*Voy a contar los que estan arriba desde la posicion del Robot*/
		for (i=posRx-1; i>=0; i--){
			cont = cont + tablero[i][posRy];
		}
		/*Voy a contar los que estan abajo desde la posicion del Robot*/
		for (i=posRx+1; i<n; i++){
			cont = cont + tablero[i][posRy];
		}
	}
	cont = cont + cuenta(posRx+dirX, posRy+dirY, dirX, dirY, n, m, dirY, dirX);
	return cont;
}
 
int main(){
	int n=6, m=6,cantidad;
	cantidad = cuenta(3,2,0,1,n,m,0,0);
	printf("La cantidad de unidades encontradas es de: %d",cantidad);
	return 0;
}
