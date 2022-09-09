
#include <stdio.h>

int coinrow(int A[],int n){
	int i,max,pos;
	int F[n+1];
//	0 1 2 3 4 5 6
//	0 5,1,2,10,6,2
	F[0] = 0;
	F[1] = A[0];
	
	for(i=2;i<=n;i++){
		max = F[i-1];
		pos = A[i-1]+F[i-2];
		if(pos>max) max = pos;
		F[i]=max;
		
	}	
	
	return F[n];
}


int main(){
	
	int A[]={5,1,2,10,6,2};
	int n=6;
	
	printf("Maximo valor: %d",coinrow(A,n));
	
	
	return 0;
}
