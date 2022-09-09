#include <stdio.h>

int calcularGanancia(int tablero[10][10], int n, int m, int i, int j){
	int derecha = -9999, abajo=-9999;
	int total;
	if (i==n-1 && j==m-1){
		return tablero[i][j];
	}
	if (i<n-1){
		derecha = calcularGanancia(tablero,n,m,i+1,j);
	}
	if (j<m-1){
		abajo = calcularGanancia(tablero,n,m,i,j+1);
	}
	if (derecha<abajo){
		total = tablero[i][j] + abajo;
	}
	else {
		total = tablero[i][j] + derecha;
	}
	return total;
}

int main(){
	int tablero[10][10];
	int n, m, i, j;
	printf("Ingrese n y m: ");
	scanf("%d %d",&n,&m);
	printf("Ingrese datos: ");
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			scanf("%d",&tablero[i][j]);
		}
	}
	printf("Ganancia: %d",calcularGanancia(tablero,n,m,0,0));
	return 0;
}
