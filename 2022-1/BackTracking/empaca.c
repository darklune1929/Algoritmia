#include <stdio.h>

int empaca(int i,int n,int peso,int paq[]){
	
	if(n==i || peso<0) return 0;
	if(peso==paq[i]){
		printf("\n%d ",paq[i]);
		return 1;
	} 
	
	if(empaca(i+1,n,peso-paq[i],paq)){
				printf("\n%d ",paq[i]);
				return 1;
	}

	else{
		printf("\nback:%d ",paq[i]);
		return empaca(i+1,n,peso,paq);
	}	

	
}


int main(){  // 9 5
	int paq[]={2,4,6,6,3};
	int n=5;
	int peso=11;
	
	if(empaca(0,n,peso,paq)) printf("Hay solucion");	
	else printf("No hay solucion");
	return 0;
	
}
