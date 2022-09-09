/*
 * Ejercicio 3 de Divide y vencerás con punteros
 * Desarrollado por Johan Baldeón
Un arreglo está rotado en algún punto desconocido. Encontrar el elemento mínimo del arreglo. 
Asumir que todos los elementos son distintos.
Ejemplo:
Entrada: {5, 6, 1, 2, 3, 4}
Salida: 1

*/ 
#include <stdio.h>
#include <limits.h>

int find_min(int *ptr, int ini, int end){
	if (ini >= end) return *(ptr+ini);

	int mid = (ini + end) /2;	
	if (*(ptr+ini) <= *(ptr+mid) && *(ptr+mid+1) <= *(ptr+end)) {
		if (*(ptr+ini) < *(ptr+mid+1)) 
			return *(ptr+ini);
		else 
			return *(ptr+mid+1);
	}
	
	if (*(ptr+ini) > *(ptr+mid))
		return find_min(ptr, ini, mid);
	else
		return find_min(ptr, mid+1, end);
}

int main(){
	int arr[] = {5, 6, 1, 2, 3, 4};
	int *ptr = arr;
	printf("El mínimo elemento del arreglo rotado es: %d\n", find_min(ptr,0,5));
	return 0;
}