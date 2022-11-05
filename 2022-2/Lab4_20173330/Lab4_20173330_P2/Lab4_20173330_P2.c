#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int esta(ArbolBB arbol, ElementoArbol dato){
    //busca si el dato de fecha esta en el arbol receptor para asi saber si aumentar o insertar en el arbol
	if (es_arbol_vacio(arbol))
		return 0;
	else{
		if (arbol->elemento.fecha==dato.fecha)
			return 1;
		else if(arbol->elemento.fecha>dato.fecha)
			return esta(arbol->hijo_izq, dato);
		else
			return esta(arbol->hijo_der, dato);
	}
}
void buscar_aumentar(ArbolBB* arbol, ElementoArbol dato){
    //al igual que la función anterior va a buscar el dato y aumentarlo dado que este es el caso en 
    // el que si esta dentro del arbol
	if (es_arbol_vacio(*arbol))
		return;
	else{
		if ((*arbol)->elemento.fecha==dato.fecha){
			(*arbol)->elemento.cantidad += dato.cantidad;
            return;
        }
		else if((*arbol)->elemento.fecha>dato.fecha)
			buscar_aumentar(&(*arbol)->hijo_izq, dato);
		else
			buscar_aumentar(&(*arbol)->hijo_der, dato);
	}
    return;
}
void fusionarArboles(ArbolBB* arbolDestino,ArbolBB* arbolFuente){
    // mientras el arbol fuente tenga productos va a seguir pasandolos
    while(!es_arbol_vacio((*arbolFuente))){
        fusionarArboles(arbolDestino,&(*arbolFuente)->hijo_izq);
        fusionarArboles(arbolDestino,&(*arbolFuente)->hijo_der);
        // chequea si el dato del arbol fuente esta en el otro para saber si insertar o aumentar en el arboldestino
        if(!esta((*arbolDestino),(*arbolFuente)->elemento)){
            insertar_abb(arbolDestino,(*arbolFuente)->elemento);
        } else{
            buscar_aumentar(arbolDestino,(*arbolFuente)->elemento);
        }
        //finalmente nullea el espacio del arbol fuente
        *arbolFuente = NULL;
    }
}
int main(){
    ArbolBB arbol1;
    ArbolBB arbol2;
    ElementoArbol aux;
    construir_ab(&arbol1);
    construir_ab(&arbol2);
    int n1,n2;
    // el ingreso de datos esta al inicio de este archivo por favor
    // ingresar los datos 1 por 1 , intente arreglar el poner varios seguidos pero 
    // queria acabar la pregunta
    /* Datos para el ingreso de estos 
    4
    20170620 20 20170810 20 20180211 20 20180409 10
    3
    20170811 5 20180211 10 20180410 15
    */
    printf("Ingrese la cantidad de productos del primer almacen:");
    scanf(" %d",&n1);
    for(int i=0;i<n1;i++){
        printf("Ingrese los datos del primer arbol (fecha) y (cantidad): ");
        scanf(" %d %d",&(aux.fecha),&(aux.cantidad));
        insertar_abb(&arbol1,aux);
    }

    printf("Ingrese la cantidad de productos del segundo almacen:");
    scanf(" %d",&n2);
    for(int i=0;i<n2;i++){
        printf("Ingrese los datos del segundo arbol (fecha) y (cantidad): ");
        scanf(" %d %d",&(aux.fecha),&(aux.cantidad));
        insertar_abb(&arbol2,aux);
    }
    printf("Antes de la fusion:\n");
    printf("Arbol 1 en preorden: ");
    pre_orden(arbol1);
    printf("\n");
    printf("Arbol 1 en enorden: ");
    en_orden(arbol1);
    printf("\n");
    printf("Arbol 2 en preorden: ");
    pre_orden(arbol2);
    printf("\n");
    printf("Arbol 2 en enorden: ");
    en_orden(arbol2);
    printf("\n");
    if(n1>n2) {
        fusionarArboles(&arbol1,&arbol2);
    } else{
        fusionarArboles(&arbol2,&arbol1);
    }
    printf("Despues de la fusion:\n");
    printf("Arbol 1 en preorden: ");
    pre_orden(arbol1);
    printf("\n");
    printf("Arbol 1 en enorden: ");
    en_orden(arbol1);
    printf("\n");
    printf("Arbol 2 en preorden: ");
    pre_orden(arbol2);
    printf("\n");
    printf("Arbol 2 en enorden: ");
    en_orden(arbol2);
    printf("\n");
    return 0;
}
