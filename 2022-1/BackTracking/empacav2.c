#include <stdio.h>
int lista[10];
int y=0,x=0;

int empaca(int i,int n,int peso,int paq[]){
	
	if(n==i || peso<0) return 0;
	if(peso==paq[i]){
		int j;
		lista[y] = paq[i];
		for(j=0;j<=y;j++)
			printf("%d ",lista[j]);
		printf("\n");
		x=1;
	} 
	lista[y]=paq[i];
	y++;
	if(empaca(i+1,n,peso-paq[i],paq)){
				return 1;
	}

	else{
		y--;
		return empaca(i+1,n,peso,paq);
	}	

	
}


int main(){  // 9 5
	int paq[]={2,4,6,8,3};
	int n=5;
	int peso=11;
	empaca(0,n,peso,paq);
	if(x) printf("Hay solucion");	
	else printf("No hay solucion");
	return 0;
	
}
