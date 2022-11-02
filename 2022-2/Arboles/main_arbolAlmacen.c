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

typedef struct nodoLote {
    int lote;
    int cant;
} NLote;

typedef NLote ElementoArbol;

typedef struct nodoArbol {
    ElementoArbol elemento;    
    struct nodoArbol *hijo_izq;
    struct nodoArbol *hijo_der;
} NodoArbol;

typedef NodoArbol* ArbolBinario;

typedef ArbolBinario ABB;

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

void construir_arbol_binario(ArbolBinario *tad){
    *tad=NULL;
}

NodoArbol *crear_nuevo_nodo_arbol(ArbolBinario arbol_izq, ElementoArbol elemento, ArbolBinario arbol_der){
    NodoArbol* nuevo_nodo = (NodoArbol*)malloc(sizeof(NodoArbol));
    nuevo_nodo->elemento=elemento;
    nuevo_nodo->hijo_izq=arbol_izq;
    nuevo_nodo->hijo_der=arbol_der;
    return nuevo_nodo;
}

void plantar_arbol_binario(ArbolBinario *tad, ArbolBinario arbol_izq, ElementoArbol elemento, ArbolBinario arbol_der){
    NodoArbol *nuevo_nodo=crear_nuevo_nodo_arbol(arbol_izq, elemento, arbol_der);
    *tad=nuevo_nodo;
}

int es_arbol_vacio(ArbolBinario tad){
    return tad==NULL;
}

ElementoArbol raiz(ArbolBinario tad){
    if (es_arbol_vacio(tad)){
        printf("No se puede obtener la raíz de un árbol vacío.\n");
        exit(41);
    }
    return tad->elemento;
}

ArbolBinario hijo_der(ArbolBinario tad){
    if (es_arbol_vacio(tad)){
        printf("No se puede obtener el hijo derecho de un árbol vacío.\n");
        exit(42);
    }
    return tad->hijo_der;
}

ArbolBinario hijo_izq(ArbolBinario tad){
    if (es_arbol_vacio(tad)){
        printf("No se puede obtener el hijo izquierdo de un árbol vacío.\n");
        exit(43);
    }
    return tad->hijo_izq;
}

void imprime_raiz(ArbolBinario tad){
    printf("%d", tad->elemento);
}

int maximo(int a, int b){
    return a>=b?a:b;
}

int altura(ArbolBinario tad){
    if (es_arbol_vacio(tad))
        return 0;
    else
        return 1+maximo(altura(tad->hijo_izq), altura(tad->hijo_der));
}

int numero_nodos(ArbolBinario tad){
    if (es_arbol_vacio(tad))
        return 0;
    else
        return 1+numero_nodos(tad->hijo_izq)+numero_nodos(tad->hijo_der);    
}

int numero_hojas(ArbolBinario tad){
    if (es_arbol_vacio(tad))
        return 0;
    else if (es_arbol_vacio(tad->hijo_izq) && es_arbol_vacio(tad->hijo_der))
        return 1;
    else
        return numero_hojas(tad->hijo_izq)+numero_hojas(tad->hijo_der);
}

ArbolBinario especular(ArbolBinario tad){
    ArbolBinario arbol_retorno;
    if (es_arbol_vacio(tad)){
        construir_arbol_binario(&arbol_retorno);       
    }
    else{
        ArbolBinario hijo_izq=especular(tad->hijo_der);
        ArbolBinario hijo_der=especular(tad->hijo_izq);
        plantar_arbol_binario(&arbol_retorno, hijo_izq, tad->elemento, hijo_der);
    }
    return arbol_retorno;
}

ArbolBinario copia_arbol_binario(ArbolBinario tad){
    ArbolBinario arbol_retorno;
    if (es_arbol_vacio(tad)){
        construir_arbol_binario(&arbol_retorno);       
    }
    else{
        ArbolBinario hijo_izq=copia_arbol_binario(tad->hijo_izq);
        ArbolBinario hijo_der=copia_arbol_binario(tad->hijo_der);
        plantar_arbol_binario(&arbol_retorno, hijo_izq, tad->elemento, hijo_der);       
    }
    return arbol_retorno;
}

void destruir_arbol_binario(ArbolBinario *tad){
    if (!es_arbol_vacio(*tad)){
        destruir_arbol_binario(&(*tad)->hijo_izq);
        destruir_arbol_binario(&(*tad)->hijo_der);
        free(*tad);
        *tad=NULL;
    }
}

int es_equilibrado(ArbolBinario tad){
    if (es_arbol_vacio(tad))
        return 1;
    else{
        int altura_hijo_izq=altura(tad->hijo_izq);
        int altura_hijo_der=altura(tad->hijo_der);
        int diferencia=abs(altura_hijo_izq-altura_hijo_der);
        return diferencia<=1 && es_equilibrado(tad->hijo_izq) && es_equilibrado(tad->hijo_der);
    }        
}


int es_hoja(ArbolBinario tad){
    if (es_arbol_vacio(tad))
        return 0;
    else
        return es_arbol_vacio(tad->hijo_izq) && es_arbol_vacio(tad->hijo_der);
}

void es_zurdo(ArbolBinario tad, int *es_zurdo_arbol, int *numero_descendientes){
    if (es_arbol_vacio(tad)){
        *es_zurdo_arbol=1;
        *numero_descendientes=0;
    }   
    else if (es_hoja(tad)){
        *es_zurdo_arbol=1;
        *numero_descendientes=1;
    }     
    else{
        int es_zurdo_hijo_izq, numero_descendientes_izq;
        int es_zurdo_hijo_der, numero_descendientes_der;
        es_zurdo(tad->hijo_izq, &es_zurdo_hijo_izq, &numero_descendientes_izq);
        es_zurdo(tad->hijo_der, &es_zurdo_hijo_der, &numero_descendientes_der);
        *es_zurdo_arbol=es_zurdo_hijo_izq && es_zurdo_hijo_der && numero_descendientes_izq>numero_descendientes_der;
        *numero_descendientes=1+numero_descendientes_izq+numero_descendientes_der;
    }        
}

void pre_orden(ArbolBinario tad){
    if (!es_arbol_vacio(tad)){
        printf("(%d %d)   ", tad->elemento.cant,tad->elemento.lote);
        pre_orden(tad->hijo_izq);
        pre_orden(tad->hijo_der);
    }
}

void en_orden(ArbolBinario tad){
    if (!es_arbol_vacio(tad)){
        en_orden(tad->hijo_izq);
        printf("(%d %d)    ",tad->elemento.lote, tad->elemento.cant);     
        en_orden(tad->hijo_der);
    }
}

void post_orden(ArbolBinario tad){
    if (!es_arbol_vacio(tad)){        
        post_orden(tad->hijo_izq);
        post_orden(tad->hijo_der);
        printf("(%d %d)    ",tad->elemento.lote, tad->elemento.cant);
    }
}

void insertar(ABB *tad, ElementoArbol elemento){
	if (es_arbol_vacio(*tad))
		plantar_arbol_binario(tad, NULL, elemento, NULL);
	else{
		if ((*tad)->elemento.lote > elemento.lote)
			insertar(&(*tad)->hijo_izq, elemento);
		else
			insertar(&(*tad)->hijo_der, elemento);
	}
}

void insertard(ABB *tad, ElementoArbol elemento){
	if (es_arbol_vacio(*tad))
		plantar_arbol_binario(tad, NULL, elemento, NULL);
	else{
		if ((*tad)->elemento.cant >= elemento.cant)
			insertard(&(*tad)->hijo_izq, elemento);
		else
			insertard(&(*tad)->hijo_der, elemento);
	}
}

ElementoArbol buscarMenor(ABB tad){
/*	if (tad==NULL){
		return -1;
	}*/
	if (tad->hijo_izq==NULL){
		return tad->elemento;
	}
	else {
		buscarMenor(tad->hijo_izq);
	}
}

void eliminar(ABB *pABB, int lote)
{
    NodoArbol *p;
    ElementoArbol menorDerecha;
	if ( !es_arbol_vacio(*pABB) ){
        if ((*pABB)->elemento.lote == lote){
        // El nodo que eliminemos puede cumplir uno de los sgntes casos:
		// si es hoja
        // nodo tiene 1 solo hijo
        // nodo tiene 2 hijos
            if ( (*pABB)->hijo_der == NULL ){
	            p = *pABB;
	            *pABB = (*pABB)->hijo_izq;
	            free(p);
			}
			else
				if( (*pABB)->hijo_izq == NULL ){
		            p = *pABB;
		            *pABB = (*pABB)->hijo_der;
		            free(p);
				}
				else{
					// en este punto el elemento a eliminar esta en un nodo que tiene 2 hijos
					menorDerecha = buscarMenor((*pABB)->hijo_der);
					(*pABB)->elemento = menorDerecha;
					eliminar(&((*pABB)->hijo_der), menorDerecha.lote);
				}
    	}
        else
            if ( lote < (*pABB)->elemento.lote)
                eliminar(&((*pABB)->hijo_izq), lote);
            else
                eliminar(&((*pABB)->hijo_der), lote);
    }
}

void despacha(ABB *tad, int cantidad){
	int faltante;
	if (cantidad==0){
		return ;
	}
	else{
		ElementoArbol ptrMenor = buscarMenor(*tad);
		if (ptrMenor.cant <= cantidad){
			faltante = cantidad - ptrMenor.cant;
			eliminar(tad,ptrMenor.lote);
			despacha(tad,faltante);
		}
		else {
			ElementoArbol elemento;
			elemento.lote = ptrMenor.lote;
			elemento.cant = ptrMenor.cant - cantidad;
			eliminar(tad,ptrMenor.lote);
			insertar(tad,elemento);
		}
	}
}

int main(){
	ABB ptrArbol;
	ElementoArbol elemento;
	int cant;
	construir_arbol_binario(&ptrArbol);
	elemento.lote = 20170620;
	elemento.cant = 20;
	insertar(&ptrArbol,elemento);
	elemento.lote = 20170810;
	elemento.cant = 20;
	insertar(&ptrArbol,elemento);
	elemento.lote = 20180211;
	elemento.cant = 20;
	insertar(&ptrArbol,elemento);
	elemento.lote = 20180409;
	elemento.cant = 10;
	insertar(&ptrArbol,elemento);
	pre_orden(ptrArbol);
	printf("Ingrese cantidad a despachar: ");
	scanf("%d",&cant);
	despacha(&ptrArbol,cant);
	pre_orden(ptrArbol);
	return 0;
}
