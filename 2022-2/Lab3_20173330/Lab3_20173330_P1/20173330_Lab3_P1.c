#include <stdio.h>
#include <stdlib.h>
void merge(int* A, int ini, int med, int fin){	
    int l1,l2,i;
    int p = 0,q = 0;
    
	l1 = med - ini + 1;
    l2 = fin -med;

    int P[l1 + 1];
    int Q[l2 + 1];

    for(i = ini; i <=med; i++)
        P[i-ini] = A[i];

    P[l1] = 1000000;

    for(i = med+1; i <= fin; i++)
        Q[i-med-1] = A[i];

    Q[l2] = 1000000;

    for(i = ini; i <= fin; i++){
        if(P[p] < Q[q])
            A[i] = P[p++];
        else
            A[i] = Q[q++];
    }
}
void mergesort(int* A, int ini, int fin){
    if(ini == fin)
        return;

    int med = (ini + fin)/2;
    mergesort(A, ini, med);
    mergesort(A, med+1, fin);
    merge(A, ini, med, fin);
}
int hallarAlrededor(int* arr,int ini,int medio,int fin,int menor_numero){
	int i, consIzq, consDer;
	if (arr[medio]!=arr[medio+1])
		return 1;
		
	consIzq = 1;
	for (i=medio; i>ini; i--){
		if (arr[i]==arr[i-1] && arr[i]==menor_numero){
			consIzq++;
		}
		else {
			break;
		}
	}
	
	consDer = 1;
	for (i=medio+1; i<fin; i++){
		if (arr[i]==arr[i+1] && arr[i]==menor_numero){
			consDer++;
		}
		else {
			break;
		}
	}
	return consIzq + consDer;
}

int diasConsecutivos(int* arr, int ini, int fin,int menor_numero){
	int izq, der, centro;
	if (ini==fin)
		return 1;
	
	int medio = (ini+fin)/2;
	izq = diasConsecutivos(arr,ini,medio,menor_numero);
	der = diasConsecutivos(arr,medio+1,fin,menor_numero);
	centro = hallarAlrededor(arr,ini,medio,fin,menor_numero);
	if (izq>=der && izq>=centro)
		return izq;
	else{
		if (der>=izq && der>=centro)
			return der;
		else
			return centro;
	}
}
int main(){
    int dias=30;
    //arreglo de los pesos de los 30 dias dados
    //parte a
    int* arr = (int*)malloc(sizeof(int)*dias);
    printf("Ingrese los pesos de los 30 dias:");
    for(int i=0;i<dias;i++){
        scanf("%d",&(arr[i]));
    }
    int* copia_menor = (int*)malloc(sizeof(int)*dias);

    //parte b
    //copio los valores del arreglo al arreglo auxiliar
    for(int i=0;i<dias;i++){
        copia_menor[i] = arr[i];
    }
    //ordeno el arreglo copia_menor que servira para hallar el menor peso de los 30 dias 
    mergesort(copia_menor,0,dias-1);
/*     printf("\n");
    for(int i=0;i<dias;i++) printf("%d ",copia_menor[i]);
    printf("\n"); */

    //parte c
    int indice;
    //busca con divide y venceras en cada numero los consecutivos a la izquierda y derecha buscando al final mayor cantidad de numeros igual al menor y que sean
    //consecutivos
    int max_continuos = diasConsecutivos(arr,0,dias-1,copia_menor[0]);
    //encontrar el indice donde empieza la racha de dias consecutivos comparandola con el indice + cantidad de dias salidos de la anterior funcion -1 para 
    // hallar los 2 dias durante los que se mantuvo este peso.
    for(int i=0;i<dias;i++){
        if(arr[i]==copia_menor[0] && arr[i]==arr[i+(max_continuos-1)]) indice=i;
    }
    printf("El menor peso fue de %d. El rango de dias que lo obtuvo fue del %d al %d",copia_menor[0],indice+1,indice+max_continuos);
    return 0;
}