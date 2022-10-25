
#include <stdio.h>

int empaca(int i,int n,int peso,int paq[]){
	
	if(i==n||peso<0)
		return 0;
	if(paq[i]==peso)	
		return 1;
		
	if( empaca(i+1,n,peso-paq[i],paq) )	
		return 1;
	else
		return empaca(i+1,n,peso,paq);
}



int main(){
	
	int paq[]={11,4,5,2,8};
	int peso=12;
	int n=5;
	
	if(empaca(0,n,peso,paq)) printf("Se encontro");
	else
		printf("No se encontro");
	
	return 0;
}
