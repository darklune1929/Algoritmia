#include <stdio.h>

int cuenta(int arr[],int ini,int fin,int cont){
	if(ini>fin)
		return cont;
	
	int med=(ini+fin)/2;
	
	if(arr[med]==0)
		return cuenta(arr,ini,med-1,cont+fin-med+1);
	else
		return cuenta(arr,med+1,fin,cont);	 
	

}

int main(){
	int n=7;
	int arr[]={1,1,1,1,0,0,0};
	
	printf("%d ",cuenta(arr,0,n-1,0));
}



