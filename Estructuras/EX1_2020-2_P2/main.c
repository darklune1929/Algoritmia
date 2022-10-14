

/* 
 * File:   main.c
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 5 de octubre de 2022, 05:53 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"
#include "lse.h"

int contador = 0; 

//8
//10 20 15 10 12 10 13 18

void solucion(Pila *pila, int rpta[], int arr[], int n){
    ElementoPila aux; 
    int i = n;
    int indice = i; 
    int max = arr[i]; 
    
    while(1){
        
        if(i == 0 && indice == 0){
            rpta[indice] = 0;
            break; 
        }
        
        if(i<0){
            aux = pop(pila); 
            rpta[indice] = aux; 
            i = indice; 
            indice = indice - 1; 
            max = arr[indice]; 
        }else{
            if(i == indice){
                push(pila, 0);  
            }else{
                if(arr[i] < max){
                    aux = pop(pila); 
                    push(pila, aux + 1);
                }else{
                    aux = pop(pila); 
                    rpta[indice] = aux; 
                    i = indice; 
                    indice = indice - 1; 
                    max = arr[indice]; 
                }
            } 
        }
        i--; 
    }
}

int main(int argc, char** argv) {
    int n, aux, i=0; 
    Pila pila;
    construir_pila(&pila); 
    
    printf ("Insertar la cantidad de dias a evaluar: \n");
    scanf ("%d", &n);
    
    int respuesta[n]; 
    int contagios[n]; 
    
    printf ("Insertar los contagiados de cada dia: \n");
    while(i<n){
        scanf ("%d", &aux);
        contagios[i] = aux;
        i++;
    }
    
    solucion(&pila, respuesta, contagios, n - 1); 
    for(i=0;i<n;i++) printf ("%d ", respuesta[i]);
    printf ("\n"); 
    return (EXIT_SUCCESS);
}

