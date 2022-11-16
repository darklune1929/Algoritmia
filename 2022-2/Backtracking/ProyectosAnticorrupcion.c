#include <stdio.h>
#include <stdlib.h>

int lista[12];
int x=0,y=0,flag=0;
int max=0;
int resultado[12]={0};
int solucion[12]={0};


//peso es ganancia, no queria cambiarlo
int proyectos(int i,int n,int peso,int paq[]){
	int k;
	if(i>=n){
		if(max<=peso){
			for(k=0;k<n;k++){
				solucion[k]=resultado[k];
			}
			max=peso;
			x=y;
		}
                return 0;
	}

	lista[y++]=paq[i];	
	resultado[i]=1;
	if( proyectos(i+3,n,peso+paq[i],paq) )	
		return 1;
	else{
		y--;
		resultado[i]=0;
		return proyectos(i+1,n,peso,paq);
	}
		
}



int main(){
	int i;
	int paq[]={3,6,1,2,4,5,18,10,13,7,15,2};
	int n=12;
	int peso=0;
	proyectos(0,n,peso,paq);
	printf("Ganancia es:%d\n",max);
	for(i=0;i<n;i++){
		if(solucion[i]==1)
			printf("%d %d\n",i+1,paq[i]);
	
	}
		
	
	return 0;
}

