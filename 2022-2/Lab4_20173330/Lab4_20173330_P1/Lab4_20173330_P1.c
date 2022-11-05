#include <stdio.h>
#include <stdlib.h>
#include "ab.h"
void insertarArreglo(ArbolB* Arbol,int* datos,int indice,int max){
    ElementoArbol aux;
    if(indice == max ) return;
    aux.bin = 0;
    aux.numero = datos[indice];
    NodoArbol* nuevo_izq = crear_nodoab(aux,NULL,NULL);
    aux.bin = 1;
    NodoArbol* nuevo_der = crear_nodoab(aux,NULL,NULL);
    (*Arbol)->hijo_izq = nuevo_izq;
    (*Arbol)->hijo_der = nuevo_der;
    insertarArreglo(&(*Arbol)->hijo_izq,datos,indice+1,max);
    insertarArreglo(&(*Arbol)->hijo_der,datos,indice+1,max);
}
void recorrerArbol(ArbolB Arbol,int peso,int* contador){
    if(Arbol==NULL) return;
    int resto=peso;
    if(Arbol->elemento.bin==1){
        resto = peso-Arbol->elemento.numero;
    }
    if(resto==0){
        (*contador)++;
        return;
    }
    recorrerArbol(Arbol->hijo_izq,resto,contador);
    recorrerArbol(Arbol->hijo_der,resto,contador);
    return;
}
int main(){
    ArbolB Arbol;
    ElementoArbol elemento;
    construir_ab(&Arbol);
    //primer nodo es 0,0
    elemento.bin = 0;
    elemento.numero = 0;
    insertar_ab(&Arbol,elemento,NULL,NULL);
    //ingreso de datos
    int n;
    printf("Ingrese la cantidad de datos que se desea combinar: ");
    scanf("%d",&n);
    int* datos = (int*)malloc(n*sizeof(int));
    printf("Ingrese los datos a combinar: ");
    for(int i=0;i<n;i++){
        scanf(" %d",&(datos[i]));
    }
    printf("Arreglo: ");
    for(int i=0;i<n;i++){
        printf("%d ",datos[i]);
    }
    printf("\n");
    int indice=0;
    //creación del arbol a partir del arreglo
    //parte a
    insertarArreglo(&Arbol,datos,indice,n);
    printf("Arbol en pre orden:");
    printf("\n");  
    pre_orden(Arbol);
    //parte b
    // no llegue a acabar la parte b :¨v
    int peso;
    printf("\n");
    printf("Ingrese el peso total deseado: ");
    scanf(" %d",&peso);
    int contador=0;
    recorrerArbol(Arbol,peso,&contador);
    printf("La cantidad de combinaciones posibles es : %d ",contador);
    return 0;
}
