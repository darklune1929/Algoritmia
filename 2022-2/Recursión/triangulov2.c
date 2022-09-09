#include <stdio.h>


void imprime(int a,int b){
	
	if(a>=b)
		return;
	printf(" * ");
	imprime(a+1,b);
}

void triangulo(int a,int b){
	int i;
	
	if(a>b) return;
	
	imprime(0,a);
	printf("\n");	
	triangulo(a+1,b);	
	imprime(0,a);
	printf("\n");
}
	
int main(){

	triangulo(3,5);
	return 0;	
}
