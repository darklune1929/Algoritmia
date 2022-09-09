#include <stdio.h>
#define MAX 9
int LIS[MAX];

int solLIS(int A[],int n){
	int i,j,mayor=1;
	
	
	for(i=0;i<n;i++){
		LIS[i]=1;
		//      0   1   2   3
		//  	3 	2 	8 	9
		//LIS:  1   1   2   3
		for(j=0;j<i;j++){
			if(A[i]>A[j] && LIS[j]+1 > LIS[i] )
				LIS[i]=LIS[j]+1;
		}
		if(LIS[i]>mayor) mayor = LIS[i];
	}
	return mayor;
	
}



int main(){
	
	int A[]={-3,7,8,9,0,1,2,3,4};
	int n=MAX;
	
	printf("Maximo valor: %d",solLIS(A,n));
	
	
	return 0;
}
