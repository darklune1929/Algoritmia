#include <stdio.h>
#include <stdlib.h>
#include "colas.c"
//tenia planeado hacer 3 colas y luego hacer un joint pero al final lei que solo se podia usar una :c
//en el lse.h esta la estructura que permite ingresar los nodos de la cola con un caracter y un entero
int main(){
    ElementoCola elemento;
    Cola cola;
    while(1){
        scanf("%c %d",&elemento.type,&elemento.turno);
        //-1 para parar la lectura
        if(elemento.type ==-1) break;
    }
    printf("[");
    while(!es_cola_vacia(cola)){
        elemento = avanzar(&cola);
        printf("%c %d, ",elemento.type,elemento.turno);
    }
    printf("]");
    destruir_cola(&cola);
    return 0;
}