#include <stdio.h>

int busqueda(int A[],int k,int ini,int fin){
	if(ini>fin)
		return -1;
	int med=(ini+fin)/2;
	
	if(A[med]==k)
		return med+1;
	else
		if(A[med]>k)
			return busqueda(A,k,ini,med-1);
		else				
			return busqueda(A,k,med+1,fin);
}


int main(){
	int A[]={1,5,6,7,8,10};
	int n=6;
	
	printf("%d",busqueda(A,7,0,n-1));
	
	
}
