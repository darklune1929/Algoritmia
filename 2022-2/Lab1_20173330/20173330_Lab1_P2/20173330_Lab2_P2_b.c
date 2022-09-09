#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// aca es traba no se porque pero deberia comparar la palabra con las letras de las galletas y va aumentando el indice en la palabra para poder comparar con toda las letras
// mientras el i va creciendo y si coinciden letraPalabra con la cantidad significa que se llego a completar la palabra
int buscarPalabra(char* galletas,char* palabra,int cantidad,int* cromosoma,int pos,int n,int* numSoluciones){
    if(galletas[pos] != palabra[0]) return 0;
    cromosoma[pos] = 1;
    int letraPalabra = 1;
    for(int i=pos+1;i<n;i++){
        if(galletas[i]==palabra[letraPalabra]) {
            letraPalabra++;
            cromosoma[i]=1;
        }
        if(letraPalabra==cantidad) {
            (*numSoluciones)++;
            printf("Solucion numero %d: ",(*numSoluciones));
            for(int j=0;j<n;j++){
                if(cromosoma[j]) printf("%d ",j+1);
            }
            printf("\n");
        }
    }
    return 0;
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
    for(int i=0; i<n; i++){
            int cromosoma[10] = {0};
            if(buscarPalabra(galletas,palabra,cantidad,cromosoma,i,n,&numSoluciones)){
                for(int j=0;j<n;j++){
                    if(cromosoma[j]) printf("%d ",j+1);
                }
            }
    }
    return 0;
}