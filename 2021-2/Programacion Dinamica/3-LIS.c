#include <stdio.h>
#define N 8

int LIS[N];

int solveLIS(int x[]){
	int i, j, maxLIS = 1;
	
	for (i=0; i < N; i++){
		LIS[i] = 1;
		for (j=0; j<i; j++){
			if (x[i] > x[j] && LIS[j]+1 > LIS[i]) 
				LIS[i] = LIS[j] + 1;
		}
		if (LIS[i] > maxLIS) maxLIS = LIS[i];
	}
	
	return maxLIS;	
}

int main(){
	int x [N] = {-7, 10, 9, 2, 3, 8, 8, 1};
	
	int lis = solveLIS(x);
	
	printf("LIS: %d\n", lis);
	
	int i;
	for (i=0; i<N; i++)
		printf("%d ", LIS[i]);
	 
	return 0;
}
