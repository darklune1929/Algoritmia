#include <stdio.h>

int mayorGanancia(int ganancias[12], int n){
	int soluciones[n+1], i, j;
	soluciones[0] = 0;
	soluciones[1] = ganancias[0];
	if (ganancias[1]>ganancias[0]){
		soluciones[2] = ganancias[1];
	}
	else {
		soluciones[2] = ganancias[0];
	}
	
	for (i=3; i<n+1; i++){
		int suma = ganancias[i-1] + soluciones[i-3];
		if (suma>soluciones[i-1]){
			soluciones[i] = suma;
		}
		else {
			soluciones[i] = soluciones[i-1];
		}
	}
	
	/*Imprimimos la solucion*/
	printf("Soluciones: ");
	for (i=0;i<n+1;i++){
		printf("%d ",soluciones[i]);
	}
	printf("\n");
	
	int maximo = soluciones[n];
	
	/*Imprimimos la solucion*/
	printf("Los proyectos seleccionados son: ");
	/*Esta solucion lo imprime al reves los proyectos, no estoy de acuerdo pero bueno*/
	while (maximo>0){
		int k;
		for (k=1;k<n+1;k++){
			if (soluciones[k]==maximo){
				printf("%d ",ganancias[k-1]);
				break;
			}
		}
		maximo = maximo - ganancias[k-1];
	}
	printf("\n");
	return soluciones[n];
}

int main(){
	int ganancias[12] = {3,6,1,2,4,5,8,10,13,7,15,2};
	int gananciaMax;
	int n=12;
	gananciaMax = mayorGanancia(ganancias,n);
	printf("La mayor ganancia es: %d",gananciaMax);
	return 0;
}
