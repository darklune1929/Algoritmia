#include <stdio.h>

int cuenta(int A[],int ini,int fin,int cont){
	if(ini>fin)
		return cont;
	
	int med = (ini+fin)/2;
	
	if(A[med]==0)
		cuenta(A,ini,med-1,fin-med+cont+1);
	else
		cuenta(A,med+1,fin,cont);
		
}


int main(){
	int A[]={1,1,0,0,0,0,0,0};
	int n=8;
	
	printf("%d ",cuenta(A,0,n-1,0));
	
	return 0;
}
