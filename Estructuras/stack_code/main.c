#include <stdio.h>
#include <assert.h>
#include "pilas.h"

int main(){
    Pila pila;

    construir_pila(&pila);    
    assert(es_pila_vacia(pila));

    ElementoPila elemento1;
    elemento1.value = 'A';
    elemento1.weight = 3;
    //apilar(&pila, elemento1);
    push_with_criteria(&pila, elemento1);
    assert(!es_pila_vacia(pila));

    ElementoPila elemento2;
    elemento2.value = 'B';
    elemento2.weight = 1;
    //apilar(&pila, elemento2);
    push_with_criteria(&pila, elemento2);
    assert(!es_pila_vacia(pila));

    ElementoPila elemento3;
    elemento3.value = 'C';
    elemento3.weight = 2;    
    //apilar(&pila, elemento3);
    push_with_criteria(&pila, elemento3);
    assert(!es_pila_vacia(pila));

    ElementoPila elemento4;
    elemento4.value = 'D';
    elemento4.weight = 5;    
    //apilar(&pila, elemento3);
    push_with_criteria(&pila, elemento4);
    assert(!es_pila_vacia(pila));

    ElementoPila elemento5;
    elemento5.value = 'E';
    elemento5.weight = 4;    
    //apilar(&pila, elemento3);
    push_with_criteria(&pila, elemento5);
    assert(!es_pila_vacia(pila));

    /*
    assert(desapilar(&pila).value=='C');
    assert(!es_pila_vacia(pila));
    assert(desapilar(&pila).value=='B');
    assert(!es_pila_vacia(pila));
    assert(desapilar(&pila).value=='A');
    assert(es_pila_vacia(pila));

    apilar(&pila, elemento1);
    assert(!es_pila_vacia(pila));
    assert(cima(pila).weight==1);
    apilar(&pila, elemento2);
    assert(!es_pila_vacia(pila));
    assert(cima(pila).weight==2);
    apilar(&pila, elemento3);
    assert(!es_pila_vacia(pila));
    assert(cima(pila).weight==3);
    */
    show_stack(pila);

    destruir_pila(&pila);
    assert(es_pila_vacia(pila));

    printf("Todas las pruebas se han ejecutado con éxito\n");
    return 0;
}