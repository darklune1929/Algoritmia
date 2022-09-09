#include <stdio.h>
#include <stdlib.h>
#include "ab.h"
#include "abb.h"

void insertar(ArbolBinarioBusqueda *tad, ElementoArbol elemento, StockArbol stock){
	if (es_arbol_vacio(*tad))
		plantar_arbol_binario(tad, NULL, elemento, stock, NULL);
	else{
		if ((*tad)->elemento>elemento)
			insertar(&(*tad)->hijo_izq, elemento, stock);
		else
			insertar(&(*tad)->hijo_der, elemento, stock);
	}
}

void insertar_iterativo(ArbolBinarioBusqueda *tad, ElementoArbol elemento, StockArbol stock){
	if (es_arbol_vacio(*tad))
		plantar_arbol_binario(tad, NULL, elemento, stock, NULL);
	else{
		//parte 1. Se busca el padre de la hoja que se va a colocar
		ArbolBinarioBusqueda recorrido=*tad, padre=NULL;
		while(!es_arbol_vacio(recorrido)){
			padre=recorrido;
			if (recorrido->elemento>elemento)
				recorrido=recorrido->hijo_izq;
			else
				recorrido=recorrido->hijo_der;
		}

		//parte 2. Se planta la hoja en el árbol
		if (padre->elemento>elemento)
			plantar_arbol_binario(&padre->hijo_izq, NULL, elemento, stock, NULL);
		else
			plantar_arbol_binario(&padre->hijo_der, NULL, elemento, stock, NULL);
	}
}

int esta(ArbolBinarioBusqueda tad, ElementoArbol llave){
	if (es_arbol_vacio(tad))
		return 0;
	else{
		if (tad->elemento==llave)
			return 1;
		else if(tad->elemento>llave)
			return esta(tad->hijo_izq, llave);
		else
			return esta(tad->hijo_der, llave);
	}
}

int esta_iterativo(ArbolBinarioBusqueda tad, ElementoArbol llave){
	if (es_arbol_vacio(tad))
		return 0;
	else{
		while(!es_arbol_vacio(tad)){
			if (tad->elemento==llave)
				return 1;
			if(tad->elemento>llave)
				tad=tad->hijo_izq;
			else
				tad=tad->hijo_der;
		}
	}
	return 0;
}

int minimo_valor(ArbolBinarioBusqueda tad){
	if (es_arbol_vacio(tad)){
		printf("No se puede obtener el menor pues el árbol está vacío.\n");
		exit(51);
	}
	if (es_arbol_vacio(tad->hijo_izq))
		return tad->elemento;
	else
		return minimo_valor(tad->hijo_izq);
}

int maximo_valor(ArbolBinarioBusqueda tad){
	if (es_arbol_vacio(tad)){
		printf("No se puede obtener el mayor pues el árbol está vacío.\n");
		exit(52);
	}
	if (es_arbol_vacio(tad->hijo_der))
		return tad->elemento;
	else
		return maximo_valor(tad->hijo_der);
}

int minimo_iterativo(ArbolBinarioBusqueda tad){
	if (es_arbol_vacio(tad)){
		printf("No se puede obtener el menor pues el árbol está vacío.\n");
		exit(53);
	}
	while(!es_arbol_vacio(tad->hijo_izq))
		tad=tad->hijo_izq;
	return tad->elemento;
}

int maximo_iterativo(ArbolBinarioBusqueda tad){
	if (es_arbol_vacio(tad)){
		printf("No se puede obtener el mayor pues el árbol está vacío.\n");
		exit(54);
	}
	while(!es_arbol_vacio(tad->hijo_der))
		tad=tad->hijo_der;
	return tad->elemento;
}
void eliminar(ArbolBinarioBusqueda *tad, ElementoArbol elemento){
	if (!es_arbol_vacio(*tad)){
		//CD: se ha encontrado el nodo que se desea eliminar
		if ((*tad)->elemento==elemento){
			ArbolBinarioBusqueda nodo_a_eliminar;
			if (es_arbol_vacio((*tad)->hijo_der)){
				nodo_a_eliminar=*tad;
				*tad=(*tad)->hijo_izq;
				free(nodo_a_eliminar);
			}
			else if (es_arbol_vacio((*tad)->hijo_izq)){
				nodo_a_eliminar=*tad;
				*tad=(*tad)->hijo_der;
				free(nodo_a_eliminar);
			}
			else			
				eliminar_auxiliar(tad, &(*tad)->hijo_der);
		}
		//CR1: el nodo que se quiere eliminar es menor que la raíz del árbol pasado como parámetro
		else if ((*tad)->elemento>elemento)
			eliminar(&(*tad)->hijo_izq, elemento);
		//CR2: el nodo que se quiere eliminar es mayor que la raíz del árbol pasado como parámetro
		else
			eliminar(&(*tad)->hijo_der, elemento);
	}	
}

//elimina el nodo que está más a la izquierda del arbol_derecha.
//y copia el valor del elemento a la raíz del árbol tad.
void eliminar_auxiliar(ArbolBinarioBusqueda *tad, ArbolBinarioBusqueda *arbol_derecha){
	if (!es_arbol_vacio((*arbol_derecha)->hijo_izq))
		eliminar_auxiliar(tad, &(*arbol_derecha)->hijo_izq);
	else{
		(*tad)->elemento=(*arbol_derecha)->elemento;
		ArbolBinarioBusqueda nodo_a_eliminar=*arbol_derecha;
		*arbol_derecha=(*arbol_derecha)->hijo_der;
		free(nodo_a_eliminar);
	}
}