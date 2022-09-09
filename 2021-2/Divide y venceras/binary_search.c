/* 
 * Desarrollado por Johan Baldeón
 */

#include <stdio.h>

int binary_search(int arr[], int value, int ini, int end){
	if (ini > end)
		return -1;
	int med = (ini + end )/2;
	if (arr[med] == value)
		return med;
	else if (arr[med] < value)
		return binary_search(arr, value, med + 1, end);
	else
		return binary_search(arr, value, ini, med - 1);
}

int main(){
	int arr[] = {1, 5, 7, 12, 14, 18, 21, 31};
	int value;
	printf("Ingrese un valor a buscar: ");
	scanf("%d", &value);
	int res = binary_search(arr, value, 0, 7);
	if (res >= 0)
		printf("El número se encuentra en la posición %d\n", res);
	else
		printf("El número no se encuentra en el arreglo.\n");
	return 0;
}