#include <stdio.h>

int cuenta(int arreglo[9],int inicio,int fin, int contador){
	if (inicio>fin){
		return contador;
	}
	int	medio = (inicio+fin)/2;
	if (arreglo[medio]==1){
		return cuenta(arreglo,inicio,medio-1,contador);
	}
	else {
		return cuenta(arreglo,medio+1,fin,fin-medio+1+contador);
	}
}

int main(){
	int arreglo[9] = {0,0,1,1,1,1,1,1,1};
	int n=9;
	printf("Existen %d ceros en el arreglo",cuenta(arreglo,0,n-1,0));
	return 0;
}
