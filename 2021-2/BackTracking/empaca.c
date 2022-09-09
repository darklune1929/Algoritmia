#include <stdio.h>

int empaca(int i,int n,int peso,int paq[]){

	if(i==n || peso <0)
		return 0;
	if(paq[i]==peso){
		printf("%d ",paq[i]);
		return 1;
	}


	if(empaca(i+1,n,peso-paq[i],paq)){
		printf("%d ",paq[i]);
		return 1;
	}
		
	else
		return(empaca(i+1,n,peso,paq));
}


int main(){
	int paq[]={1,4,5,7};
	int n=4;
	int peso=12;
	
	if(empaca(0,n,peso,paq))
		printf("\nHay respuesta");
	else
		printf("\nNo hay respuesta");
	
}
