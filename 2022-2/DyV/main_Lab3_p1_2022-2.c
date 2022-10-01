#include <stdio.h>

int merge(int arreglo[],int ini,int medio,int fin){
	int i, consIzq, consDer;
	if (arreglo[medio]>arreglo[medio+1])
		return 1;
		
	consIzq = 1;
	for (i=medio; i>ini; i--){
		if (arreglo[i]>arreglo[i-1]){
			consIzq++;
		}
		else {
			break;
		}
	}
	
	consDer = 1;
	for (i=medio+1; i<fin; i++){
		if (arreglo[i]<arreglo[i+1]){
			consDer++;
		}
		else {
			break;
		}
	}
	return consIzq + consDer;
}

int maxContinuos(int arreglo[], int ini, int fin){
	int izq, der, bloque;
	if (ini==fin)
		return 1;
	
	int medio = (ini+fin)/2;
	izq = maxContinuos(arreglo,ini,medio);
	der = maxContinuos(arreglo,medio+1,fin);
	bloque = merge(arreglo,ini,medio,fin);
	printf("%d %d %d\n",izq,der,bloque);
	if (izq>=der && izq>=bloque)
		return izq;
	else{
		if (der>=izq && der>=bloque)
			return der;
		else
			return bloque;
	}
}

int main(){
	//int arreglo[] = {7,2,9,10,16,10,13,8,2,10};
	int arreglo[] = {10,20,15,10,12,10,13,18};
	int n=8;
	int max = maxContinuos(arreglo,0,n-1);
	printf("La cantidad maxima de consecutivos es: %d",max);
	return 0;
}
