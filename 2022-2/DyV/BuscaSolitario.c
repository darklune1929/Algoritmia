#include <stdio.h>

void sinpareja(int arr[],int ini,int fin){
	int med;
	
	if(ini>fin) return;
	
	med = (ini+fin)/2;
	
	if(ini==fin){
		printf("El valor es:%d\n",arr[ini]);
		return;
	}
		
	if(med%2==0){
		if(arr[med]==arr[med+1])
			sinpareja(arr,med+2,fin);
		else
			sinpareja(arr,ini,med);
	}
	else{
		if(arr[med]==arr[med-1])
			sinpareja(arr,med+1,fin);
		else
			sinpareja(arr,ini,med-1);
	}
		
}

int main(){
	int n=13;
	int arreglo[]={1,1,3,3,4,5,5,7,7,8,8,9,9};	
	sinpareja(arreglo,0,n-1);
}



