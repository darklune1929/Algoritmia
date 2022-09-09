#include<stdio.h>

int solve_LIS(int N, int x[], int LIS[]){
	int maxLIS = 1;
	for (int i=0; i<N; i++){
		LIS[i] = 1;
		for (int j=0; j<i; j++){
			if (x[j] < x[i] && LIS[j] + 1 > LIS[i])
				LIS[i] = LIS[j] + 1;
		}
		if (LIS[i] > maxLIS) maxLIS = LIS[i];
	}
	return maxLIS;
}

int main(){
	int N=8, LIS[N];
	int x[] = {-7, 10, 9, 2, 3, 8, 8, 1};

	int lis = solve_LIS(N, x, LIS);
	printf("LIS: %d.\n", lis);

	for (int i=0; i<N; i++){
		printf("%d ", LIS[i]);
	}
	return 0;
}