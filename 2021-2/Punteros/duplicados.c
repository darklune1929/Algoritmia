#include <stdio.h>

void busca(int arr[],int ini,int fin){
	if(ini>fin)
		return;
	if(ini==fin){
		printf("%d ",arr[ini]);
		return;
	}	
	int med=(ini+fin)/2;
	if(med%2==0){
		if (arr[med]==arr[med+1]) 
			busca(arr,med+2,fin);
		else	
			busca(arr,ini,med);	
	}
	else
	if (arr[med]==arr[med-1]) 
		busca(arr,med+1,fin);
	else	
		busca(arr,ini,med-1);
		
}
int main(){
	int n=7; //medio=4  medio=3 medio=2 medio=1
	//int arr[]={4,4,5,5,7,7,6,8,8};
	int arr[]={4,4,5,5,7,7,6};
	busca(arr,0,n-1);
}



