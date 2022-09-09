#include <stdio.h>
/*

* * *
* * * *
* * * * *
* * * * *
* * * *
* * *

*/

void triangulo(int a,int b){
	int i;
	
	if(a>b) return;	
	
	for(i=0;i<a;i++)
		printf(" * ");
	printf("\n");	
	triangulo(a+1,b);
	for(i=0;i<a;i++)
		printf(" * ");
	printf("\n");
	
}


void imprimir_fila(int num)
{   //R.Melendez
    // caso base
    if (num == 0) return;
    printf(" * ");
    imprimir_fila(num-1);
}

void triangulo2(int a,int b){
	int i;
	
	if(a>b) return;	
	
	imprimir_fila(a);
	printf("\n");	
	triangulo(a+1,b);
	imprimir_fila(a);
	printf("\n");
	
}

int main(){
	
	triangulo(3,5);
	printf("\n");
	triangulo2(2,5);
	
}
