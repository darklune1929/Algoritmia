#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// aca es traba no se porque pero deberia comparar la palabra con las letras de las galletas y va aumentando el indice en la palabra para poder comparar con toda las letras
// mientras el i va creciendo y si coinciden letraPalabra con la cantidad significa que se llego a completar la palabra
void cargabin(int num,int n,int cromosoma[]){
	int res,i;
	for(i=0;i<n;i++) cromosoma[i]=0;
	i=0;
	while(num>0){
		res = num%2;
		num = num/2;
		cromosoma[i]=res;
		i++;
	}
}
int buscarPalabra(char* galletas,char* palabra,int cantidad,int* cromosoma,int n,int* numSoluciones){
    int letras=0;
    for(int i=0;i<n;i++){
        letras +=cromosoma[i];
        if(letras!=cantidad) return 0;
    }
    int cant= 0;
    for(int i=0;i<n;i++){
        if(cromosoma[i]){
            if(galletas[i] != palabra[cant]){
                return 0;
            }
            cant++;
        }
    }
    return 1;
}
int main(){
    int n=10;
    char* galletas = malloc(sizeof(char)*n);
    printf("Ingrese las letras de las galletas: ");
    for(int i=0; i<n; i++) scanf(" %c",galletas+i);
    for(int i=0; i<n; i++) printf("%c ", galletas[i]);
    int cantidad;
    char palabra[10];
    printf("Ingrese la palabra a buscar:");
    scanf("%s", palabra);
    cantidad = strlen(palabra);
    for(int i=0; i<cantidad; i++) printf("%c ", palabra[i]);
    printf("%d",cantidad);
    printf("\nLa solucion esta en las posiciones: \n");
    int numSoluciones = 0;
    printf("Todas las soluciones son: \n");
    int limite = pow(2,n);
    int cromosoma[10] = {0};
    for(int i=0; i<limite; i++){
            cargabin(i,n,cromosoma);
            if(buscarPalabra(galletas,palabra,cantidad,cromosoma,n,&numSoluciones)){
                for(int j=0; j<n; j++){
                    if(cromosoma[j]) printf("%d ",j+1);
                }
            }
    }
    return 0;
}