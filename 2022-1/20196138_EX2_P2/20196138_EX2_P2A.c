#include <stdio.h>
#include <math.h>
#define N 4
#define M 4

int robot_dron(int alm[N][M],int n,int m){
	int sol[n][m];
	sol[0][0] = 0;
	
	int i,j;
	for(i=1;i<n;i++)
		sol[i][0] = sol[i-1][0]+fabs(alm[i-1][0]-alm[i][0]);
	for(i=1;i<m;i++)
		sol[0][i] = sol[0][i-1]+fabs(alm[0][i-1]-alm[0][i]);
	
	int di,iz,ar;
	for(i=1;i<n;i++)
		for(j=1;j<m;j++){
			di = sol[i-1][j-1]+fabs(alm[i-1][j-1]-alm[i][j]);
			iz = sol[i][j-1]+fabs(alm[i][j-1]-alm[i][j]);
			ar = sol[i-1][j]+fabs(alm[i-1][j]-alm[i][j]);
			if(di<=iz && di<=ar) sol[i][j] = di;
			if(iz<=di && iz<=ar) sol[i][j] = iz;
			if(ar<=di && ar<=iz) sol[i][j] = ar;
		}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			printf("%d ",sol[i][j]);
		printf("\n");
	}
	
	return sol[n-1][m-1];
}

int main(){
	int alm[N][M] = {{4,2,2,4},
					 {1,4,6,8},
					 {2,5,9,1},
					 {1,3,11,12}};
	
	printf("La minima distancia es %d ",robot_dron(alm,N,M));
	
	return 0;
}
