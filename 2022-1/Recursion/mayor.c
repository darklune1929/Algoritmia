#include <stdio.h>
/*Busca menor, busca numero*/
int mayor(int arreglo[],int n){
	int max,resto;
	
	if(n==1)
		return arreglo[n-1];
	
	max = arreglo[n-1];
	resto = mayor(arreglo,n-1);
	
	if(max<resto)
		return resto;
	else
		return max;	
	
}

int busca(int arreglo[],int n,int numero){
	
	if(n==0)
		return -1;

	if(arreglo[n-1]==numero)
		return n-1; 
		
	busca(arreglo,n-1,numero);	
	
}

int main(){
	
	int arreglo[]={5,4,2,7,2,1,9};
	int n=7;
	
	printf("%d \n",mayor(arreglo,n));
	printf("%d \n",busca(arreglo,n,2));

	
	return 0;
}
