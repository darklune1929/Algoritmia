#include <stdio.h>
#include <stdlib.h>
#include "lse.h"
//adjunte el .txt con los datos para copiar y pegarlos
//además ajuste la estructura de elementolista para que tuviera numero de proceso y duración de este
//reemplazandolo en las funciones de lse.c correspondientes pero finalmente solo use
// las funciones construirlista,insertaralfinal,crearnodo y eliminanodo del lse.c
int main(){
    //declaración de variables y creación de lista
    Lista list;
    ElementoLista elemento;
    construir_lista(&list);
    int proc_ini,T,contador_proc=0;
    //cargar datos iniciales
    printf("Ingrese la cantidad de procesos iniciales e intervalo de tiempo: ");
    scanf("%d %d",&proc_ini,&T);
    contador_proc += proc_ini;
    printf("Duraciones iniciales de procesos (en minutos, respectivamente) = ");
    for(int i=0;i<proc_ini;i++){
        scanf("%d",&elemento.duracion);
        elemento.num_proc = i+1;
        //para la primera inserción de datos los pongo en orden que entran
        insertar_al_final(&list,elemento);
    }
    int nuevo_proc;
    Nodo* recorrido = list.cabeza;
    Nodo* aux = NULL;
    //recorro la lista hasta que no quede ningun nodo en ella
    while(recorrido!=NULL){
        //ejecuta un intervalo de tiempo indicando en que proceso se encuentra el recorrido
        printf("Se ejecuto proceso #%d\n",recorrido->elemento.num_proc);
        recorrido->elemento.duracion =recorrido->elemento.duracion-T;
        //le resto T a la duración del nodo si es 0 o menor entonces se completo el proceso y se imprime
        if(recorrido->elemento.duracion<=0){
            printf("Se completo proceso #%d\n",recorrido->elemento.num_proc);
            //se elimina el nodo que ya no tenga duración por procesar
            elimina_nodo(&list,recorrido->elemento);
            recorrido = aux;
        }
        printf("Desea insertar un nuevo proceso? ");
        scanf("%d",&nuevo_proc);
        //si inserto un nodo nuevo incrementa el contador de procesos para enumerarlo
        // además de crear el nodo nuevo e insertarlo despues del nodo actual del recorrido
        if(nuevo_proc){
            contador_proc++;
            printf("Indicar duracion del proceso #%d:",contador_proc);
            scanf("%d",&elemento.duracion);
            elemento.num_proc = contador_proc;
            if(recorrido==NULL){
                Nodo* nuevo_nodo = crear_nuevo_nodo(elemento,list.cabeza);
                list.cabeza = nuevo_nodo;
            } else{
                Nodo* nuevo_nodo = crear_nuevo_nodo(elemento,recorrido->sig);
                recorrido->sig = nuevo_nodo;
            }
        }
        //si estoy al final de la lista vuelvo a la cabeza para seguir recorriendo la lista
        //si no paso al siguiente nodo
        if(recorrido->sig==NULL){
            aux=recorrido;
            recorrido = list.cabeza;
        }else{
            aux = recorrido;
            recorrido = recorrido->sig;
        }
    }
    destruir_lista(&list);
    return 0;
}
