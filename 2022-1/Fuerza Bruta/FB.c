
#include <stdio.h>

void ord_seleccion(int arr[],int n){
	int i,j,min,aux;
	
	for(i=0;i<=n-2;i++){
		min=i;
		for(j=i+1;j<=n-1;j++)
			if(arr[j]<arr[min])
				min=j;
		aux = arr[i];
		arr[i] = arr[min];
		arr[min] = aux;
	}
}

void ord_burbuja(int arr[],int n){
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
/*{8,9,1,4,5,7}  k=4*/
int bus_secuencial(int arr[],int n,int k){
	int i;
	i=0;
	while(i<n && arr[i]!=k){
		i++;
	}
	if(i<n)
		return i;
	else	
		return -1;
}


int main(){
	int i,n=6;
	int arreglo[]={8,9,1,4,5,7};
	
	printf("Indice:%d \n",bus_secuencial(arreglo,n,14));
	
	ord_burbuja(arreglo,n);
	
	for(i=0;i<n;i++)
		printf("%d ",arreglo[i]);
	
	
	return 0;
}

