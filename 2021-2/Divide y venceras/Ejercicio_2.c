/*
 * Ejercicio 2 de Divide y Vencerás con punteros
 * Desarrollado por Johan Baldeón
*/ 
#include <stdio.h>
#include <limits.h>

int count_zeros(int *ptr, int ini, int end){
	if (ini == end) {
		if (*(ptr+ini) == 0)
			return 1;
		else if (*(ptr+ini) == 1)
			return 0;		
	} else if (end < ini)
		return 0;
	int mid = (ini + end) /2;	

	if ( *(ptr+mid) == 0)	
		return 1 + end - mid + count_zeros(ptr, ini, mid-1);
	else
		return count_zeros(ptr, mid+1, end);	
}

int main(){
	int arr[] = {1,0,0,0};
	int *ptr = arr;
	int elem = count_zeros(ptr,0,3);
	printf("Cantidad de ceros: %d\n", elem);
	return 0;
}