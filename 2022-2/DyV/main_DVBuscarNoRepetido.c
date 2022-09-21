#include <stdio.h>

void buscar(int arreglo[11],int inicio,int fin){
	int medio = (inicio+fin)/2;
	if (medio%2==0){
		if (arreglo[medio]==arreglo[medio+1]){
			buscar(arreglo,medio+2,fin);
		}
		else{
			buscar(arreglo,inicio,medio);
		}
	}
	else {
		if (arreglo[medio]==arreglo[medio-1]){
			buscar(arreglo,medio+1,fin);
		}
		else {
			buscar(arreglo,inicio,medio-1);
		}
	}
	if (inicio>fin){
		return ;
	}
	if (inicio==fin){
		printf("El elemento que no se repite es %d",arreglo[inicio]);
	}
}

int main(){
	int arreglo[11] = {1,1,3,3,4,5,5,7,7,8,8};
	buscar(arreglo,0,10);
	return 0;
}
