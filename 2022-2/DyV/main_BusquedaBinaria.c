#include <stdio.h>

int busquedaBinaria(int arreglo[7],int elemento, int inicio, int fin){
	int medio = (inicio+fin)/2;
	if (arreglo[medio]==elemento){
		return 1;
	}
	if (inicio>fin){
		return -1;
	}
	if (arreglo[medio]<elemento){
		return busquedaBinaria(arreglo,elemento,medio+1,fin);
	}
	else {
		return busquedaBinaria(arreglo,elemento,inicio,medio-1);
	}
}

int main(){
	int arreglo[7]={1,2,5,8,10,12,15};
	int n=7, elemento=9;
	printf("El elemento %d se encuentra en el arreglo %d",elemento,busquedaBinaria(arreglo,elemento,0,n-1));	
	return 0;
}
