//En el archivo lse.h se declararán las estructuras de la lista simplemente enlazada
//así como el prototipo de sus operaciones
#ifndef LSE_H
#define LSE_H

//Se define un TIPO DE DATO que va a ser almacenado en cada nodo.
//En este se está usado como tipo un int, lo que supone que tendremos una lista de 
//números enteros, pero podría haber usado char, double, char*, struct, etc.
typedef struct ElementoLista{
	int num_proc;
	int duracion;
}ElementoLista;

//Se define el tipo de dato Nodo como una estructura autoreferenciada. 
//El primer campo es un ElementoListo y el segundo campo es un puntero que 
//apunta a su sucesor, conforme definición de Lista Simplemente Enlazada (LSE)
typedef struct nodo{
	ElementoLista elemento;
	struct nodo *sig; 
} Nodo;

//Defino el tipo de dato que describe la Lista Simplemente Enlazada.
typedef struct{
	Nodo *cabeza;
	int longitud;
} Lista;

void construir_lista(Lista *);
int es_lista_vacia(Lista);
Nodo *crear_nuevo_nodo(ElementoLista, Nodo *);
Nodo *obtener_ultimo_nodo(Lista);
Nodo *obtener_nodo_anterior(Lista, ElementoLista);
void insertar_al_inicio(Lista *, ElementoLista);
void insertar_al_final(Lista *, ElementoLista);
void insertar_en_orden(Lista *, ElementoLista);
void imprime(Lista);
int longitud(Lista);
void destruir_lista(Lista *);
void reverse(Lista *tad);
void elimina_nodo(Lista *, ElementoLista);

#endif