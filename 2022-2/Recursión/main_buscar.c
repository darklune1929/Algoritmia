#include <stdio.h>

int buscar(int arreglo[6],int valor,int i, int N){
	if (arreglo[i]==valor){
		return 1;
	}
	else {
		if (i>=N){
			return 0;
		}
		else {
			return buscar(arreglo,valor,i+1,N);	
		}
	}
}

int main(){
	int arreglo[6] = {7,2,9,12,20,1};
	int valor=20, i=0, N=6;
	printf("El valor se encuentra: %d",buscar(arreglo,valor,i,N));
	return 0;
}
