#include <stdio.h>
#include <assert.h>
#include "colas.h"

int main(){
    Cola cola;

    construir_cola(&cola);   
    assert(es_cola_vacia(cola));

    ElementoCola elemento;
    elemento.value = 'A';
    elemento.type = 2;
    enqueue_with_priority2(&cola, elemento);


    ElementoCola elemento2;
    elemento2.value = 'B';
    elemento2.type = 1;
    enqueue_with_priority2(&cola, elemento2);

    ElementoCola elemento3;
    elemento3.value = 'C';
    elemento3.type = 1;
    enqueue_with_priority2(&cola, elemento3);

    ElementoCola elemento4;
    elemento4.value = 'D';
    elemento4.type = 2;
    enqueue_with_priority2(&cola, elemento4);

    show_queue(cola);
    /*
    pide_vez(&cola, 1);
    assert(!es_cola_vacia(cola));    
    pide_vez(&cola, 2);
    assert(!es_cola_vacia(cola));
    pide_vez(&cola, 3);
    assert(!es_cola_vacia(cola));
    
    assert(avanzar(&cola)==1);
    assert(avanzar(&cola)==2);
    assert(avanzar(&cola)==3);
    assert(es_cola_vacia(cola));
    */
    destruir_cola(&cola);

    printf("Todas las pruebas se han ejecutado con éxito\n");
    return 0;
}