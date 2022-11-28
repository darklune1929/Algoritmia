#include <stdio.h>
#include <math.h>
#define col 4
#define fil 4

int calcula(int x,int y,int valor,int alma[][col]){
	if(x<=0 || y<=0) return 999999;
	return abs(valor-alma[x-1][y-1]);
}
int min(int a,int b,int c){
	int min;
	
	if(a<b)
		min=a;
	else
		min=b;
	if(min<c)			
		return min;
	else
		return c;	
}


int vuelodron(int alma[][col]){
	int i,j,dp[fil+1][col+1];
	int dia,izq,arr;
	
	for(i=0;i<=fil;i++)	
		dp[i][0]=9999999;

	for(i=0;i<=col;i++)	
		dp[0][i]=9999999;
		
	for(i=1;i<=fil;i++)
		for(j=1;j<=col;j++){
			if(i==1 && j==1)	dp[i][j]=0;
			else{
				dia=dp[i-1][j-1]+calcula(i-1,j-1,alma[i-1][j-1],alma); 
				arr=dp[i-1][j]+calcula(i-1,j,alma[i-1][j-1],alma);
				izq=dp[i][j-1]+calcula(i,j-1,alma[i-1][j-1],alma);
				dp[i][j]=min(dia,arr,izq);		
			}
		}
		return dp[fil][col];	
}

int main(){
	int pilas[][col]={{4,2,2,4},
					  {1,4,6,8},
					  {2,5,9,1}, 	
					  {1,3,11,12}}; 	
	
	printf("%d",vuelodron(pilas));
	
	return 0;	
}


