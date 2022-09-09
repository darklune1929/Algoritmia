#include<stdio.h>

int max(int v1, int v2){
	return v1 > v2 ? v1 : v2;
}

void solve_knapsackDP(int n, int W, int w[], double v[], double V[n+1][W+1]){
	for (int i=0; i<=n; i++) V[i][0] = 0;
	for (int i=0; i<=W; i++) V[0][i] = 0;

	for (int j=1; j<=W; j++)
		for (int i=1; i<=n; i++)
			if (j - w[i-1] >= 0)
				V[i][j] = max(V[i-1][j], v[i-1] + V[i-1][j-w[i-1]]);	
			else
				V[i][j] = V[i-1][j];
}

int main(){
	int n=4,W=5;
	int w[] = {2,1,3,2};
	double v[] = {12,10,20,15};

	double V[n+1][W+1];

	solve_knapsackDP(n,W, w, v, V);

	for (int i=0; i<n+1; i++){
		for (int j=0; j< W+1; j++)
			printf("%.2lf ", V[i][j]);
		printf("\n");
	}
	return 0;
}