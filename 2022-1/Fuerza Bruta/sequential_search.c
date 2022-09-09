/*
 * Secuential search
 * Desarrollado por Johan Baldeón
 */

#include <stdio.h>

void swap(int *e1, int *e2){
	int aux = *e1;
	*e1 = *e2;
	*e2 = aux;
}

void bubble_sort (int arr[], int n){
	int i, j;
	for (i=0; i <= n-2; i++)
		for (j=0; j <= n-2-i; j++)
			if (arr[j+1] < arr[j])
				swap(&arr[j], & arr[j+1]);
}

int sequential_search(int arr[], int size, int value){
	int i=0;
	while (i<size && arr[i] != value)
		i++;
	if (i < size) return i;
	else return -1;
}

void print_array(int arr[], int size) {
	int i;
	for (i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(){
	int arr[] = {666, 699, 999, 333, 123, 6, 9, 96};
	int n = sizeof(arr) / sizeof(arr[0]);

	int pos = sequential_search(arr, n, 999);
	printf("La posición del valor 999 en el arreglo original es %d.\n", pos);
	bubble_sort(arr, n);

	printf("Arreglo ordenado con bubble sort: \n");
	print_array(arr, n);

	pos = sequential_search(arr, n, 999);
	printf("La posición del valor 999 en el arreglo ordenado es %d.\n", pos);

	return 0;
}