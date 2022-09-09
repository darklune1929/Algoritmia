/*
 * Ejercicio 1 de Divide y Vencerás con punteros
 * Desarrollado por Johan Baldeón
*/ 
#include <stdio.h>
#include <limits.h>

int find_unique_element(int *ptr, int ini, int end){
	int res, mid =  (ini + end) /2;
	if (*(ptr + mid) == *(ptr + mid+1))
		mid--;
	if (mid < ini)
		return INT_MIN;
	if (ini == end)
		return *(ptr + ini);
	res = find_unique_element(ptr, ini, mid);
	if (res == INT_MIN)
		res = find_unique_element(ptr, mid+1, end);
	return res;
}

int main(){
	int arr[] = {1,1,3,3,4,5,5,7,7,8,8};
	int *ptr = arr;
	int elem = find_unique_element(ptr,0,10);
	printf("Elemento: %d\n", elem);
	return 0;
}