#include <stdio.h>

int maximo(int arr[],int ini,int fin){

	int medio;
	
	medio = (ini+fin)/2;
	
	if(ini==fin)
		return arr[ini];
		
	if(fin-ini==1){
		if(arr[fin]>arr[ini])	
			return arr[fin];
		else	
			return arr[ini];
	}	
	if(arr[medio]>arr[medio+1] && medio+1<=fin)
		return maximo(arr,ini,medio);
	else
		return maximo(arr,medio+1,fin);
	
}

int main(){
	int arreglo[]={1,8,1000,200,100,50,30,6};
	int n=8;
	/*Puede ser el valor maximo o el indice del maximo*/
	
	printf("%d ",maximo(arreglo,0,n-1));
	
	
}
