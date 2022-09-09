#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int main(){
    FILE *archivo =fopen("2022-1_E2_P3_data1.txt","r");
    ArbolBinarioBusqueda* arbol;
    ElementoArbol elemento;
    int N;
    fscanf(archivo,"%d",&N);
    char palabrainc[N];
    for(int i=0;i<N;i++){
        fscanf(archivo,"%d %c",&elemento.orden,&elemento.caracter);
        insertar(arbol,elemento);
    }
    printf("BIENVENIDO AL JUEGO DE BALWORD\n");
    printf("Descubre la palabra de 5 letras. Tiene maximo 5 intentos\n");
    for(int i=0;i<N;i++){
        printf(" - ");
    }
    for(int i=0;i<N;i++){
        
    }

    fclose(archivo);
    return 0;
}