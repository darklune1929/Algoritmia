#include <stdio.h>
#include <stdlib.h>

int min_index(int arr[],int ini,int end){
	int min,val;
	if(ini==end) return ini;
	min=ini;
	val=min_index(arr,ini+1,end);
	if(arr[min]<arr[val]) return min;
	else return val;
}
void asc_sort(int arr[],int ini,int end){
	int min;
	int aux;
	if(ini>=end) return;
	min=min_index(arr,ini,end);
	aux=arr[ini];
	arr[ini]=arr[min];
	arr[min]=aux;
	asc_sort(arr,ini+1,end);
}
int Max_index(int arr[],int ini,int end){
	int max,val;
	if(ini==end) return ini;
	max=ini;
	val=Max_index(arr,ini+1,end);
	if(arr[max]>arr[val]) return max;
	else return val;
}
void desc_sort(int arr[],int ini,int end ){
	int max_index; //, aux, aux_char;
	int aux;
	if (ini >= end) return;
	max_index = Max_index(arr,ini,end);
	aux=arr[ini];
	arr[ini] = arr[max_index];
	arr[max_index] = aux;
	desc_sort(arr, ini+1, end);
}
int main(){
	int arr[7]={8,2,3,5,6,7,10};
	int maximo;
	maximo=Max_index(arr,0,6);
	printf("%d\n",maximo);
	desc_sort(arr,0,6);
	for(int i=0;i<7;i++)
		printf("%d ",arr[i]);
	printf("\n");
	asc_sort(arr,0,6);
	for(int i=0;i<7;i++)
		printf("%d ",arr[i]);	
    return 0;
}