#include <stdio.h>
#define max 50

void remolino(int x,int y,int n,int m,int alma[][max]){
	int i;
	
	if(x>=n || y>=m)	
		return;
	
	if(x==n-1 && y==m-1)
		printf("%d ",alma[x][y]);
	else	
	if(x==n-1)
		for(i=y; i<m; i++)
			printf("%d ",alma[x][i]);	
	else
	if(y==m-1)
		for(i=x; i<n; i++)
			printf("%d ",alma[i][y]);	
	else{
		for(i=x;i<n-1;i++)
			printf("%d ",alma[i][y]);
		for(i=y;i<m-1;i++)
			printf("%d ",alma[n-1][i]);	
		for(i=n-1;i>x;i--)
			printf("%d ",alma[i][m-1]);		
		for(i=m-1;i>y;i--)
			printf("%d ",alma[x][i]);	
		remolino(x+1,y+1,n-1,m-1,alma);
	}
	return;
}

int main(){
	int i,j,n=3,m=5,cont=1;	
	int alma[max][max];
	
	for(j=0;j<m;j++)
		for(i=0;i<n;i++)
			alma[i][j]=cont++;
	for(j=0;j<m;j++){
		for(i=0;i<n;i++)
			printf("%d ",alma[i][j]);
		printf("\n");
	}

	int x=0,y=0;
	remolino(x,y,n,m,alma);	
	
}
