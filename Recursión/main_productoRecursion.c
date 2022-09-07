#include <stdio.h>

int producto(int a, int b){
	if (a==1){ /*Caso base*/
		return b;
	}
	else {
		return b + producto(a-1,b);
	}
}

int main(){
	int a=3, b=4;
	printf("El resultado es: %d",producto(a,b));
	return 0;
}
