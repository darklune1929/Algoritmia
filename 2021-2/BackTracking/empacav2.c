#include <stdio.h>
int lista[10];
int x=0,y=0;


int empaca(int i,int n,int peso,int paq[]){

	if(i==n || peso <0)
		return 0;
	if(paq[i]==peso){
		int z;
		lista[y]=paq[i];
		printf("La respuesta es:");
		for(z=0;z<=y;z++)
			printf("%d ",lista[z]);
		printf("\n");

	}
	
	lista[y]=paq[i];
	y++;
	if(empaca(i+1,n,peso-paq[i],paq)){
		printf("%d ",paq[i]);
		//return 1;
	}
	else{
		y--;
		return(empaca(i+1,n,peso,paq));
	}
	
}


int main(){
	int paq[]={1,4,5,7};   
	int n=4;
	int peso=12;
	
	empaca(0,n,peso,paq);

	
}
