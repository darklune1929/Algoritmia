#include <stdio.h>

int buscapresupuesto(int arr[],int n,int sum){
	int i,j;
	int dp[n+1][sum+1];
	//Por favor ordenar el arreglo previamente para
	//obtener mejores resultados
	
	for(i=0;i<=n;i++)
		dp[i][0]=1;
		
	for(i=1;i<=sum;i++)
		dp[0][i]=0;
	
	
	for(i=1;i<=n;i++){
		for(j=1;j<=sum;j++){
			dp[i][j]=dp[i-1][j];
			
			if(j-arr[i-1]>=0 && dp[i][j]==0)
				dp[i][j]=dp[i-1][j-arr[i-1]];
		}
	}
	for(i=sum;i>0;i--)	
		if(dp[n][i]==1) return i;
	
}



int main(){
	int arr[]={2,3,3,5};
	int n=4,pre=12;
	
	
	printf("%d",8+buscapresupuesto(arr,n,pre));
	
	
	return 0;
}
