#include <stdio.h>

int factorial(int n){
	
	if(n==0) return 1;
	
	return factorial(n-1)*n;

}

int fibonacci(int n){
	printf("%d\n",n);
	if(n==1) return 0;
	if(n==2) return 1;
	
	return fibonacci(n-2) + fibonacci(n-1);
	
	
}



int main(){
	
	printf("El factorial: %d\n",factorial(5));
	
	printf("El fibonaccio: %d",fibonacci(5));
	
	return 0;
}
