#include <stdio.h>
	int mapa[][6]={{0,0,0,1,0,1},
				   {0,0,1,0,0,0},
				   {0,1,0,0,0,1},
				   {1,0,0,0,0,0},
				   {0,1,0,0,0,0},
				   {0,0,0,0,1,0}};
/*2020-02 P2*/
int busca(int x,int y,int x1,int y1,int x2,int y2,int n,int m)
{ 	int i,cont=0;
	if(x>=n || y>=m || x<0 || y<0)
		return 0;
	if(mapa[x][y] && x2==0 && y2==0)
			cont++;	
	if(x2==0){
		for(i=x+1;i<n;i++)	
			cont=cont+mapa[i][y];
		for(i=0;i<x;i++)	
			cont=cont+mapa[i][y];
	}
	if(y2==0){
		for(i=y+1;i<m;i++)	
			cont=cont+mapa[x][i];
		for(i=0;i<y;i++)	
			cont=cont+mapa[x][i];
	}	
	cont=cont+busca(x+x1,y+y1,x1,y1,x1,y1,n,m);		
	return cont;	
}
/*derecha: 0,1
izquierda: 0,-1
abajo    : 1,0
arriba   :-1,0 
*/
int main(){
	int cont,n=6,m=6;
	cont=busca(3,2,0,1,0,0,n,m);
	printf("%d",cont);
}

