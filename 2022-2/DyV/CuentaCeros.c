#include <stdio.h>

int cuentaceros(int arr[],int ini,int fin,int cont){
	int med;
	
	if(ini>fin) return cont;
	
	med = (ini+fin)/2;
	
	if(arr[med]==0) 
		cuentaceros(arr,ini,med-1,cont+fin-med+1);
	else
		cuentaceros(arr,med+1,fin,cont);
	
		
}




int main(){
	int n=7;
	int arreglo[]={1,1,1,0,0,0,0};	
	printf("%d",cuentaceros(arreglo,0,n-1,0));
}



