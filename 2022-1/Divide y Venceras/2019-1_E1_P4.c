#include <stdio.h>
#include <limits.h>
#include <string.h>
#define MAX 20
const char * max_word = "zzzzzzzzzzzzzzzzzzzz";

void merge(char array[][MAX], int ini, int mid, int end){
	int i, p=0, q=0;
	int l1 = mid - ini + 1;
	int l2 = end - mid;

	char left_array[l1+1][MAX];
	char right_array[l2+1][MAX];

	for (i = ini; i <= mid; i++)
		strcpy(left_array[i - ini], array[i]);
	strcpy(left_array[l1], max_word);

	for (i = mid+1; i<= end; i++)
		strcpy(right_array[i-mid-1], array[i]);
	strcpy(right_array[l2], max_word);

	for (i=ini; i <= end; i++)
		if (strcmp(left_array[p], right_array[q]) < 0 )
			strcpy(array[i], left_array[p++]);
		else
			strcpy(array[i], right_array[q++]);
}

void merge_sort(char array[][MAX], int ini, int end){
	int mid;
	if (ini == end) return;
	mid = (ini + end) / 2;
	merge_sort (array, ini, mid);
	merge_sort (array, mid + 1, end);
	merge(array, ini, mid, end);
}

int main(){
	int i, len=8;
	char words[][MAX] = {"atreverse", "atrevido", "atrevimiento", "atrevida", "atreve", "atrevete", "atrevio", "atrasado"};

	merge_sort(words, 0, len-1);
	for (i=0; i < len; i++)
		printf("%s\n", words[i]);
	return 0;
}