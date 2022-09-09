#include <stdio.h>

void mat_addition(int row_count, int col_count, int arr1[][col_count], int arr2[][col_count], 
					int res[][col_count]){
	int i,j;
	for (i=0; i<row_count; i++){
		for (j=0; j<col_count; j++)
			res[i][j] = arr1[i][j] + arr2[i][j];
	}
}

void mat_addition_ptr(int row_count, int col_count, int *arr1, int *arr2, 
					int *res){
	int i,j;
	for (i=0; i<row_count; i++){
		for (j=0; j<col_count; j++)
			(res + i*col_count)[j] = (arr1 + i*col_count)[j] + (arr2 + i*col_count)[j];
	}
}

int main(){
	int rows = 3;
	int cols = 2; 
	int arr1[3][2] = {{3, 4}, { 5, 7}, {1,2}};
	int arr2[6] = { 3, 4, 
					5, 7, 
					6, 9};
	int res[rows][cols];
	//mat_addition(rows, cols, arr1, arr2, res);
	mat_addition_ptr(rows, cols, arr1, arr2, res);

	for (int i=0; i<rows; i++){
		for (int j=0; j< cols; j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}
	return 0;
}