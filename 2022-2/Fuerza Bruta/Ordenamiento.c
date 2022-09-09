#include <stdio.h>

void ordseleccion(int arr[],int n){
	int i,j,min,aux;
	
	for(i=0;i<=n-2;i++){
		min=i;
		for(j=i+1;j<=n-1;j++){
			if(arr[j]<arr[min])
				min = j;
		}
		aux = arr[i];
		arr[i] = arr[min];
		arr[min] = aux;
	}
}


void ordburbuja(int arr[],int n){
	int i,j,aux;
	
	for(i=0;i<=n-2;i++){
		for(j=0;j<=n-2-i;j++){
			if(arr[j+1]<arr[j]){
				aux = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = aux;
			}
		}

	}
}

int main(){
	int i,n=6;
	int lista[]={4,2,1,5,8,9};
	
	ordburbuja(lista,n);
	
	for(i=0;i<n;i++)
		printf("%d ",lista[i]);
		
	return 0;
}
