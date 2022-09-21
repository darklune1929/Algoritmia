#include <stdio.h>

int busqueda(int A[],int K,int ini,int fin){
	if(ini>fin)
		return -1;
	
	int med = (ini+fin)/2;
	
	if(A[med]==K)
		return med;
	if(A[med]>K)	
		 busqueda(A,K,ini,med-1);
	else
		 busqueda(A,K,med+1,fin);	
		
}


int main(){
	int A[]={2,4,5,7,8,10,12,16};
	int n=8,K=5;
	
	printf("%d ",busqueda(A,K,0,n-1));
	
	return 0;
}
