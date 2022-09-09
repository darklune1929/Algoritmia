#include <stdio.h>
#define max 50

void remolino(int x,int y,int n,int m,int alma[][max]){
	int i,j;
	
	if(x>=n && y>=m)	
		return;
	
	//Si ya llegó al limite en algún lado, imprime lo que le falte al otro lado
	if(x==n-1){
		for(j=y; j<m; j++){
			printf("%d ",alma[x][j]);	
		}
		return;
	}
	
	//Si ya llegó al limite en algún lado, imprime lo que le falte al otro lado
	if(y==m-1){
		for(j=x; j<n; j++){
			printf("%d ",alma[j][y]);	
		}
		return;
	}
	//Reemplazar los for por recursiones
	if(x==n-1 && y==m-1)
		printf("%d ",alma[x][y]);		
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
int main(){
	int i,j,n=4,m=3,cont=1;	
	int alma[max][max];
	
	for(j=0;j<m;j++)
		for(i=0;i<n;i++)
			alma[i][j]=cont++;
	int x=0,y=0;
	remolino(x,y,n,m,alma);	
	
}
