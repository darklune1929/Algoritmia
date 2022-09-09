#include <stdio.h>
#define max 100
            
int robot(int x,int y,int n,int m,int tablero[max][max]){
	int derecha=-999999,abajo=-999999;
	
	if(x==n-1 && y==m-1)
		return tablero[x][y];

	if(x+1<n)	      
		derecha=robot(x+1,y,n,m,tablero);
	if(y+1<m)
		abajo=robot(x,y+1,n,m,tablero);	
		
	if(derecha>abajo)
		return derecha+tablero[x][y];
	else
		return abajo+tablero[x][y];
}



int main(){
	int n,m,i,j;
	int tablero[max][max];
	scanf("%d %d",&n,&m);
	
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)		
			scanf("%d",&tablero[i][j]);
	
	printf("Maximo: %d",robot(0,0,n,m,tablero));
	
}
