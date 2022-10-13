
/* 
 * File:   main.c
 * Author: cueva
 *
 * Created on 2 de mayo de 2022, 12:02 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"
#include "lse.h"


void pasar(Pila *pila1,Pila *pila2){
    int valor,aux,n;
    
    while(!es_pila_vacia(*pila1)){
        valor = desapilar(pila1);
        
        n=0;
        while(!es_pila_vacia(*pila1)){
            apilar(pila2,valor);
            valor = desapilar(pila1); /*el ultimo no se apila*/
            n++;
        }
        while(!es_pila_vacia(*pila2) && n>0 ){
            aux = desapilar(pila2);
            apilar(pila1,aux);
            n--;
        }
        apilar(pila2,valor);
        
    }

}

void ordena(Pila *pila1){
    int n,max,valor;
    Pila pila2;
    
    n = pila1->contenido.longitud;
    
    construir_pila(&pila2);
    
    while(n>0){
        max=desapilar(pila1);
        n--;
        while(!es_pila_vacia(*pila1) && n>0){
            valor=desapilar(pila1);
            if(max<valor){
                apilar(&pila2,max);
                max=valor;
            }
            else
                apilar(&pila2,valor);
            n--;
        }
        apilar(pila1,max);
        n=0;
        while(!es_pila_vacia(pila2)){
            n++;
            apilar(pila1,desapilar(&pila2));
        }
    }

}


int main(int argc, char** argv) {
    Pila ptrpila,ptrpila2;
    
    construir_pila(&ptrpila);
    apilar(&ptrpila,11);
    apilar(&ptrpila,18);
    apilar(&ptrpila,10);
    apilar(&ptrpila,17);
    printf("Pila1:");
    imprime(ptrpila.contenido); //Solo para imprimir
    construir_pila(&ptrpila2);
    pasar(&ptrpila,&ptrpila2);
    printf("Pila2:");
    imprime(ptrpila2.contenido);//Solo para imprimir
    ordena(&ptrpila2);
    imprime(ptrpila2.contenido);
    return (EXIT_SUCCESS);
}

