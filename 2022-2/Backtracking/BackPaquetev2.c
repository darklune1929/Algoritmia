#include <stdio.h>

int lista[10];
int x=0,y=0,flag=0;

int empaca(int i,int n,int peso,int paq[]){
	
	if(i==n||peso<0)
		return 0;
	if(paq[i]==peso){
		lista[y]=paq[i];
		for(x=0;x<=y;x++)
			printf("%d ",lista[x]);
		printf("\n");
		flag=1;
		//return 0;
	}	
	lista[y++]=paq[i];	
	if( empaca(i+1,n,peso-paq[i],paq) )	
		return 1;
	else{
		y--;
		return empaca(i+1,n,peso,paq);
	}
		
}



int main(){
	
	int paq[]={13,4,1,5,2,8};
	int peso=13;
	int n=6;
	empaca(0,n,peso,paq);
	if(flag) printf("Se encontro");
	else
		printf("No se encontro");
	
	return 0;
}
