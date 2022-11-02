#include <stdio.h>
#include <stdlib.h>

typedef int ElementoLista;

typedef struct nodoLista {
    ElementoLista elemento;    
    struct nodoLista *sig;
} NodoLista;

typedef struct {
    int longitud;
    NodoLista *cabeza;
} Lista;

typedef ElementoLista ElementoCola;

typedef struct {
	Lista contenido;    
} Cola;

typedef ElementoLista ElementoPila;

typedef struct {
	Lista contenido;    
} Pila;

void construir_lista(Lista *tad){
    tad->cabeza=NULL;
    tad->longitud=0;
}

int es_lista_vacia(Lista tad){
    return tad.cabeza==NULL;
}

NodoLista *crear_nuevo_nodo(ElementoLista elemento, NodoLista* sig){
    NodoLista* nuevo_nodo = (NodoLista*)malloc(sizeof(NodoLista));
    if (nuevo_nodo==NULL){
        printf("No ha sido posible asignar memoria dinámica.\n");
        exit(1);
    }
    nuevo_nodo->elemento=elemento;
    nuevo_nodo->sig=sig;
    return nuevo_nodo;
}

void insertar_al_inicio(Lista *tad, ElementoLista elemento){
    NodoLista *nuevo_nodo = crear_nuevo_nodo(elemento, tad->cabeza);
    tad->cabeza=nuevo_nodo;
    tad->longitud++;
}

int longitud(Lista tad){
    return tad.longitud;
}

void imprime(Lista tad){
    NodoLista* recorrido = tad.cabeza;
    int esta_imprimiendo_la_cabeza=1;
    printf("[");
    while(recorrido != NULL){
        if (!esta_imprimiendo_la_cabeza)
            printf(", ");
        esta_imprimiendo_la_cabeza=0;
        printf("%d", recorrido->elemento);        
        recorrido = recorrido->sig;
    }
    printf("]\n");
}

NodoLista *obtener_ultimo_nodo(Lista tad){
    NodoLista* ultimo=NULL;
    NodoLista* recorrido = tad.cabeza;
    while(recorrido != NULL){
        ultimo = recorrido;        
        recorrido = recorrido->sig;
    }
    return ultimo;
}

void insertar_al_final(Lista *tad, ElementoLista elemento){
    NodoLista *nuevo_nodo = crear_nuevo_nodo(elemento, NULL);
    NodoLista *ultimo_nodo = obtener_ultimo_nodo(*tad);    
    if (ultimo_nodo==NULL)
        tad->cabeza=nuevo_nodo;
    else    
        ultimo_nodo->sig=nuevo_nodo;
    tad->longitud++; 
}

NodoLista *obtener_nodo_anterior(Lista tad, ElementoLista elemento){
    NodoLista* anterior=NULL;
    NodoLista* recorrido = tad.cabeza;
    while(recorrido != NULL && recorrido->elemento<elemento){
        anterior = recorrido;        
        recorrido = recorrido->sig;
    }
    return anterior;    
}

void insertar_en_orden(Lista *tad, ElementoLista elemento){
    NodoLista *nuevo_nodo = crear_nuevo_nodo(elemento, NULL);
    NodoLista *nodo_anterior = obtener_nodo_anterior(*tad, elemento);    
    if (nodo_anterior==NULL){
        nuevo_nodo->sig=tad->cabeza;
        tad->cabeza=nuevo_nodo;
    }else{    
        nuevo_nodo->sig=nodo_anterior->sig;
        nodo_anterior->sig=nuevo_nodo;
    }
    tad->longitud++;     
}

NodoLista* se_encuentra(Lista tad, ElementoLista llave){
    NodoLista* recorrido = tad.cabeza;
    while(recorrido != NULL && recorrido->elemento!=llave){        
        recorrido = recorrido->sig;
    }
    return recorrido;        
}

void destruir_lista(Lista *tad){    
    NodoLista* recorrido = tad->cabeza;
    while(recorrido != NULL){
        NodoLista *nodo_a_eliminar=recorrido;        
        recorrido = recorrido->sig;
        free(nodo_a_eliminar);
    }
    tad->cabeza=NULL;
    tad->longitud=0;
}

ElementoLista retorna_cabeza(Lista tad){
    if (es_lista_vacia(tad)){
        printf("No existe la cabeza por que la lista está vacía.\n");
        exit(4);
    }
    return tad.cabeza->elemento;
}

void elimina_cabeza(Lista *tad){
    if (es_lista_vacia(*tad)){
        printf("No se puede eliminar la cabeza pues la lista está vacía.\n");
        exit(2);
    }
    NodoLista *nodo_a_eliminar=tad->cabeza;    
    tad->cabeza=tad->cabeza->sig;
    free(nodo_a_eliminar); 
    tad->longitud--;          
}

void elimina_cola(Lista *tad){
    if (es_lista_vacia(*tad)){
        printf("No se puede eliminar la cola pues la lista está vacía.\n");
        exit(3);
    }
    NodoLista *ultimo=NULL, *penultimo=NULL;
    NodoLista *recorrido = tad->cabeza;
    while(recorrido != NULL){
        if (ultimo!=NULL)
            penultimo=ultimo;
        ultimo = recorrido;        
        recorrido = recorrido->sig;
    }    
    if (penultimo==NULL)
        tad->cabeza=NULL;            
    else
        penultimo->sig=NULL;
    free(ultimo);
    tad->longitud--;                  
}

void elimina_nodo(Lista *tad, ElementoLista elemento){
    NodoLista *ultimo=NULL;
    NodoLista *recorrido = tad->cabeza;
    while(recorrido != NULL && recorrido->elemento!=elemento){
        ultimo = recorrido;        
        recorrido = recorrido->sig;
    }
    if (recorrido != NULL){
        if (ultimo==NULL)
            tad->cabeza=recorrido->sig;
        else    
            ultimo->sig=recorrido->sig;
        free(recorrido);
        tad->longitud--;
    }
}

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

void construir_pila(Pila *tad){
	//El constructor de la lista espera como parámetro Lista *tad
	//El párametro de esta función es Pila *tad
	//	typedef struct {
	//		Lista contenido;    
	//	} Pila;
	//
	//como a partir de Pila *tad se llega a la lista
	//	tad->contenido es del tipo de dato Lista
	//la dirección de la lista sería (Lista *)
	//	&tad->contenido
	construir_lista(&tad->contenido);
}

void destruir_pila(Pila *tad){
	destruir_lista(&tad->contenido);
}

int es_pila_vacia(Pila tad){
	return es_lista_vacia(tad.contenido);
}

void apilar(Pila *tad, ElementoPila elemento){
	insertar_al_inicio(&tad->contenido, elemento);
}

ElementoPila desapilar(Pila *tad){	
    if (es_pila_vacia(*tad)){
    	printf("La pila está vacía, por lo tanto no se puede desapilar.\n");
    	exit(11);
    }
    ElementoPila elemento=cima(*tad);
    elimina_cabeza(&tad->contenido);
    return elemento;
}

ElementoPila cima(Pila tad){
	if (es_pila_vacia(tad)){
    	printf("La pila está vacía, por lo tanto no posee cima.\n");
    	exit(12);
    }
    //return tad.contenido.cabeza->elemento; //NO SE DEBE HACER	
    return retorna_cabeza(tad.contenido);
}

void inicializarLista(int n,Lista *ptrLista){
	int i;
	for (i=2; i<=n; i++){
		insertar_al_final(ptrLista,i);
	}
}

void limpiaCola(Cola *ptrCola){
	if (!es_cola_vacia(*ptrCola)){
		int elemento = avanzar(ptrCola);
		limpiaCola(ptrCola);
	}
}

void tachaNodos(NodoLista *ptrRecorrido,Lista *ptrLista,int elemento,Cola *ptrCola){
	if (ptrRecorrido!=NULL){
		if (ptrRecorrido->sig!=NULL){
			if (ptrRecorrido->sig->elemento % elemento==0){
				pide_vez(ptrCola,ptrRecorrido->sig->elemento);
				elimina_nodo(ptrLista,ptrRecorrido->sig->elemento);
			}
			tachaNodos(ptrRecorrido->sig,ptrLista,elemento,ptrCola);
		}
	}
}

void procesoCribaEratostenes(NodoLista *ptrRecorrido,Lista *ptrLista,int elemento,Cola *ptrCola){
	if (ptrRecorrido!=NULL){
		tachaNodos(ptrRecorrido,ptrLista,elemento,ptrCola);
		printf("Número Procesado: %d\n",elemento);
		printf("Números Tachados para el %d: ",elemento);
		imprime(ptrCola->contenido);
		limpiaCola(ptrCola);
		ptrRecorrido = ptrRecorrido->sig;
		procesoCribaEratostenes(ptrRecorrido,ptrLista,ptrRecorrido->elemento,ptrCola);
	}
}

int main(){
	int n;
	Lista ptrLista;
	Cola ptrCola;
	NodoLista *ptrRecorrido;
	printf("Ingrese el n: ");
	scanf("%d",&n);
	construir_lista(&ptrLista);
	construir_cola(&ptrCola);
	/*Parte b*/
	inicializarLista(n,&ptrLista);
	/*Parte c*/
	ptrRecorrido = ptrLista.cabeza;
	procesoCribaEratostenes(ptrRecorrido,&ptrLista,ptrRecorrido->elemento,&ptrCola);
	imprime(ptrLista);
	destruir_lista(&ptrLista);
	destruir_cola(&ptrCola);
	return 0;
}

