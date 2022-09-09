/*
 * Selection sort
 * Desarrollado por Johan Baldeón
 */
#include <stdio.h>

void swap(int *e1, int *e2){
	int aux = *e1;
	*e1 = *e2;
	*e2 = aux;
}

void selection_sort (int arr[], int n) {
	int i, j, min;
	for (i=0; i <= n-2; i++){
		min = i;
		for (j=i+1; j<=n-1; j++)
			if (arr[j] < arr[min])
				min = j;
		swap(&arr[min], &arr[i]);		
	}
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

	selection_sort(arr, n);

	printf("Arreglo ordenado con selection sort: \n");
	print_array(arr, n);

	return 0;
}