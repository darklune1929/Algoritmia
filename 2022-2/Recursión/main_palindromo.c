#include <stdio.h>

int palindromo(char arreglo[5],int i, int j){
	if (i>j){
		return 1;
	}
	else {
		if (arreglo[i]!=arreglo[j]){
			return 0;
		}
		else {
			return palindromo(arreglo,i+1,j-1);	
		}
	}
}

int main(){
	char arreglo[5] = {'L','E','V','E','L'};
	int i=0, N=5, j=N-1;
	printf("La palabra es palindroma: %d",palindromo(arreglo,i,j));
	return 0;
}
