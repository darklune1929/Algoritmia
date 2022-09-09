#include <stdio.h>

int obtenerMayor(int arreglo[6],int mayor,int i, int N){
	if (i>=N){
		return mayor;
	}
	else {
		if (arreglo[i]>mayor){
			mayor = arreglo[i];
		}
		return obtenerMayor(arreglo,mayor,i+1,N);
	}
}

int main(){
	int arreglo[6] = {7,2,9,12,20,1};
	int mayor=0, i=0, N=6;
	printf("El mayor es: %d",obtenerMayor(arreglo,mayor,i,N));
	return 0;
}
