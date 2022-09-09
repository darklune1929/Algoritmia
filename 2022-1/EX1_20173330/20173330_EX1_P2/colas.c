#include <stdio.h>
#include <stdlib.h>
#include "colas.h"

void construir_cola(Cola *tad){
	construir_lista(&tad->contenido);
}

void destruir_cola(Cola *tad){
	destruir_lista(&tad->contenido);	
}

int es_cola_vacia(Cola tad){
	return es_lista_vacia(tad.contenido);
}

void pide_vez(Cola *tad, ElementoCola elemento){
	insertar_al_final(&tad->contenido, elemento);
}

ElementoCola avanzar(Cola *tad){
	if (es_cola_vacia(*tad)){
		printf("La cola está vacía, no se puede avanzar en ella.\n");
		exit(11);
	}	
    ElementoCola elemento = retorna_cabeza(tad->contenido);	
    elimina_cabeza(&tad->contenido);
    return elemento;
}

void enqueue_with_priority(Cola *tad, ElementoCola elemento) {
	if (elemento.type == 'V')
		insertar_al_inicio(&tad->contenido, elemento);
	else {
		if (es_lista_vacia(tad->contenido))
			insertar_al_inicio(&tad->contenido, elemento);	
		else {
			NodoLista* prevListNode = tad->contenido.cabeza; 
			NodoLista* listNode = tad->contenido.cabeza;
			
			while (listNode != NULL && listNode->elemento.type != 'C' && listNode->elemento.type != 'N'){
				prevListNode = listNode;
				listNode = listNode->sig;
			}
			
			NodoLista* nuevo_nodo = (NodoLista*)malloc(sizeof(NodoLista));
			nuevo_nodo->elemento.type = elemento.type;
			nuevo_nodo->elemento.turno = elemento.turno;
			nuevo_nodo->sig = listNode;
			prevListNode->sig = nuevo_nodo;
			
		}
	}
}

void show_queue(Cola tad){
	imprime(tad.contenido);	
}