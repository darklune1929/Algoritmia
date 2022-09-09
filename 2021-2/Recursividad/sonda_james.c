#include <stdio.h>
#define max 50
/*derecha es +1 izq -1 abajo +1 arriba -1*/

int mapa[][6]={{ 0,0,0,1,0,1},
				{0,0,1,0,0,0},
				{0,1,0,0,0,1},				
				{1,0,0,0,0,0},
				{0,1,0,0,0,0},
				{0,0,0,0,1,0}};
/*int buscar_y(int y,int x,int z){
		if(y==z) return 0;
		int cont=0;
		if(mapa[x][y]==1) cont++;
		buscar_y(y+1,x,z);
        return cont;
}                
int buscar_x(int x,int y,int z){
		if(x==z) return 0;
		int cont=0;
		if(mapa[x][y]==1) cont++;
		buscar_x(x+1,y,z);
        return cont;
}*/
int busca(int x,int y,int x1,int y1,int x2,int y2,int n,int m){
	int i,cont=0;
	
	if (x==n || y==m || y<0 || x<0) return 0;
	if (mapa[x][y] == 1 && x2==0 && y2==0) 
			cont++;
	if(x2==0){
    //    cont+= buscar_x(0,y,x);
    //    cont+= buscar_x(x+1,y,n+1);
		for(i=x+1;i<n;i++)
			cont=cont+mapa[i][y];
		for(i=0;i<x;i++)
			cont=cont+mapa[i][y];
	}
	if(y2==0){
     //   cont+= buscar_y(0,x,y);
     //   cont+= buscar_y(y+1,x,m+1);
		for(i=y+1;i<m;i++)
			cont=cont+mapa[i][y];
		for(i=0;i<n;i++)
			cont=cont+mapa[i][y];
	}
		
	cont=cont+busca(x+x1,y+y1,x1,y1,x1,y1,n,m);

	return cont;
}

				
int main(){
	int n=6,m=6,cont=0;
	cont=busca(3,2,0,1,0,0,n,m);
	printf("%d",cont);
	
}				
				
