#include <stdio.h>
#include <stdlib.h>
#include "ab.h"
#include "abb.h"

void insertar(ArbolBinarioBusqueda *tad, ElementoArbol elemento){
	if (es_arbol_vacio(*tad)){
		plantar_arbol_binario(tad, NULL, elemento, NULL);
	}
	else{
		if ((*tad)->elemento.campo1>elemento.campo1){
			insertar(&(*tad)->hijo_izq, elemento);
		}else if((*tad)->elemento.campo1<elemento.campo1){
			insertar(&(*tad)->hijo_der, elemento);
		}else {
			if((*tad)->elemento.campo2>elemento.campo2){
				insertar(&(*tad)->hijo_izq, elemento);
			}else if((*tad)->elemento.campo2<elemento.campo2){
				insertar(&(*tad)->hijo_der, elemento);
			}else{
				printf("Cannot insert duplicate key");
			}
		}			
	}
}

void insertar_iterativo(ArbolBinarioBusqueda *tad, ElementoArbol elemento){
	if (es_arbol_vacio(*tad)){
		plantar_arbol_binario(tad, NULL, elemento, NULL);
	}
	else{
		ArbolBinarioBusqueda recorrido=*tad, padre=NULL;
		while(!es_arbol_vacio(recorrido)){
			padre=recorrido;
			if (recorrido->elemento.campo1>elemento.campo1)
				recorrido=recorrido->hijo_izq;
			else
				recorrido=recorrido->hijo_der;
		}
		if (padre->elemento.campo1>elemento.campo1)
			plantar_arbol_binario(&padre->hijo_izq, NULL, elemento, NULL);
		else
			plantar_arbol_binario(&padre->hijo_der, NULL, elemento, NULL);		
	}
}

int esta(ArbolBinarioBusqueda tad, ElementoArbol llave){
	if (es_arbol_vacio(tad))
		return 0;
	else{
		if (tad->elemento.campo1==llave.campo1)
			return 1;
		else if (tad->elemento.campo1>llave.campo1)
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
			if (tad->elemento.campo1==llave.campo1)
				return 1;
			if (tad->elemento.campo1>llave.campo1)
				tad=tad->hijo_izq;
			else
				tad=tad->hijo_der;	
		}
	}
	return 0;
}

int minimo_valor(ArbolBinarioBusqueda tad){
	if (es_arbol_vacio(tad)){
		printf("No se puede obtener el menor valor pues el árbol está vacío.\n");
		exit(51);
	}
	if (es_arbol_vacio(tad->hijo_izq))
		return tad->elemento.campo1;
	else
		return minimo_valor(tad->hijo_izq);
}

int maximo_valor(ArbolBinarioBusqueda tad){
	if (es_arbol_vacio(tad)){
		printf("No se puede obtener el mayor valor pues el árbol está vacío.\n");
		exit(52);
	}
	if (es_arbol_vacio(tad->hijo_der))
		return tad->elemento.campo1;
	else
		return maximo_valor(tad->hijo_der);
}

/* int minimo_iterativo(ArbolBinarioBusqueda tad){
	if (es_arbol_vacio(tad)){
		printf("No se puede obtener el menor valor pues el árbol está vacío.\n");
		exit(53);
	}
	while(!es_arbol_vacio(tad->hijo_izq))
		tad=tad->hijo_izq;
	return tad->elemento;
}

int maximo_iterativo(ArbolBinarioBusqueda tad){
	if (es_arbol_vacio(tad)){
		printf("No se puede obtener el mayor valor pues el árbol está vacío.\n");
		exit(54);
	}
	while(!es_arbol_vacio(tad->hijo_der))
		tad=tad->hijo_der;
	return tad->elemento;
} */

void eliminar(ArbolBinarioBusqueda *tad, ElementoArbol elemento){
	if (!es_arbol_vacio(*tad)){
		//CD: se ha encontrado el nodo que se desea eliminar
		if ((*tad)->elemento.campo1==elemento.campo1){
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
		else if ((*tad)->elemento.campo1>elemento.campo1)
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

//Pregunta a)
void can_be_inserted(ArbolBinarioBusqueda *tad, ElementoArbol elemento){
	//parecido a la función insertar pero sin los inserts solo imprimiendo un mensaje
	//caso se pueda lograr la inserción
	if (es_arbol_vacio(*tad)){
		plantar_arbol_binario(tad, NULL, elemento, NULL);
	}
	else{
		if ((*tad)->elemento.campo1>elemento.campo1){
			printf("Ok");
		}else if((*tad)->elemento.campo1<elemento.campo1){
			printf("Ok");
		}else {
			if((*tad)->elemento.campo2>elemento.campo2){
				printf("Ok");
			}else if((*tad)->elemento.campo2<elemento.campo2){
				printf("Ok");
			}else{
				printf("Cannot insert duplicate key");
			}
		}			
	}
}
//Pregunta b
void can_be_updated(ArbolBinarioBusqueda *tad, ElementoArbol elemento){
	//planeo hacerlo con la función "esta" para poder buscar el elemento.campo1 y campo2 actualizado
	//entonces se podria saber si este se encuentre en el arbol
}
//Preugnta c
//Pregunta d