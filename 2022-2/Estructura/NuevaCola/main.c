/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: cueva.r
 *
 * Created on 3 de octubre de 2022, 10:27 AM
 */
#include "Colas.h"
#include <stdio.h>
#include <stdlib.h>

void ordenacolarec(Cola *cola1,int n){
    ElementoCola menor,aux;
    int i=1;
    //condicion base puede ser cola vacia o n =0 
    if(n==0 || es_cola_vacia(*cola1)) return;
    
    menor = desencola(cola1);
    while(i<n){
        aux = desencola(cola1);
        if(aux<menor){
            encola(cola1,menor);
            menor = aux;
        }
        else{
            encola(cola1,aux);
        }
        i++;
    }
    ordenacolarec(cola1,n-1);
    encola(cola1,menor);
    
}


int main(int argc, char** argv) {
    Cola cola1;
    
    construir_cola(&cola1);
    encola(&cola1,1);
    encola(&cola1,7);
    encola(&cola1,2);
    encola(&cola1,3);
    encola(&cola1,6);
    
    imprimecola(cola1);
    ordenacolarec(&cola1,cola1.contenido.longitud);
    imprimecola(cola1);
    
    return 0;
}

