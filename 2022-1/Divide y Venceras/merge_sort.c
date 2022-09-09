#include <stdio.h>
#include <limits.h>

void merge(int arr[], int ini, int mid, int end){
	int p=0, q=0, m, i;
	int left_array[mid-ini+1 + 1];
	int right_array[end-mid  + 1];

	for (i=ini; i<=mid; i++)
		left_array[i-ini] = arr[i];
	left_array[mid-ini+1] = INT_MAX;

	for (i=mid+1; i<=end; i++)
		right_array[i-mid-1] = arr[i];
	right_array[end - mid] = INT_MAX;

	for (m=ini; m <= end; m++)
		if (left_array[p] < right_array[q])
			arr[m] = left_array[p++];
		else
			arr[m] = right_array[q++];  

}

void merge_sort(int arr[], int ini, int end){
	if (ini == end) return;
	int mid = (end + ini) / 2;
	merge_sort(arr, ini, mid);
	merge_sort(arr, mid + 1, end);
	merge(arr, ini, mid, end);
}

int main(){
	int arr[] = {5, 8, 2, 1, 666, 999, 4, 3, 696, 969};
	int n=10;

	merge_sort(arr, 0, n-1);

	for (int i=0; i<n; i++)
		printf("%d ", arr[i]);
	return 0;
}