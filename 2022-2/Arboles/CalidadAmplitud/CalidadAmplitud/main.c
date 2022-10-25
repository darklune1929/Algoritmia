/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: cueva.r
 *
 * Created on 17 de octubre de 2022, 12:25 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Abb.h"
#include "Colas.h"


void imprime_amp(ArbolBB arbol){
    Cola pcola;
    ElementoCola temp;
    ArbolBB aux;
    
    aux = arbol;
    if(es_arbol_vacio(arbol)) return;
    construir_cola(&pcola);
    encola(&pcola,aux->elemento);
    
    while(!es_cola_vacia(pcola)){
        temp = desencola(&pcola);
        imprimirelemento(temp);
        aux = buscaarbol(arbol,temp);
        if(aux->hijo_izq!=NULL){
            encola(&pcola,aux->hijo_izq->elemento);
        }
        if(aux->hijo_der!=NULL){
            encola(&pcola,aux->hijo_der->elemento);            
        }
    }
}


int valida(ArbolBB  arbolcalidad,int cali){
    Cola auxcola;
    ElementoCola temp;
    int num;
    ArbolBB aux;
    int cont=0;
    
    num=pow(2,cali-1);
    if(es_arbol_vacio(arbolcalidad)) return 1;
    construir_cola(&auxcola);
    aux = arbolcalidad;
    encola(&auxcola,aux->elemento);

    while(!es_cola_vacia(auxcola)){
        temp = desencola(&auxcola);
        if(cali == temp.calidad) cont++;
        if(cali < temp.calidad ) break;
        aux = buscaarbol(arbolcalidad,temp);
        if(aux->hijo_izq!=NULL)
            encola(&auxcola,aux->hijo_izq->elemento);
        if(aux->hijo_der!=NULL)
            encola(&auxcola,aux->hijo_der->elemento);            
    }
    if(cont<num) return 1;
    return 0;
}

int main(int argc, char** argv) {
    ArbolBB arbolcalidad;
    ElementoArbol temp;
    
    construir_ab(&arbolcalidad);
    temp.calidad=1;
    temp.lote= 10;
    insertar_abb(&arbolcalidad,temp);
    temp.calidad=2;
    temp.lote= 5;
    insertar_abb(&arbolcalidad,temp);    
    temp.calidad=2;
    temp.lote= 20;
    insertar_abb(&arbolcalidad,temp);
    temp.calidad=3;
    temp.lote= 2;
    insertar_abb(&arbolcalidad,temp);
    temp.calidad=3;
    temp.lote= 6;
    insertar_abb(&arbolcalidad,temp);
    temp.calidad=3;
    temp.lote= 21;
    insertar_abb(&arbolcalidad,temp);    
    
    imprime_amp(arbolcalidad);
    printf("\n");
    printf("Se puede insertar:%d",valida(arbolcalidad,4));
    printf("\n");
    en_orden(arbolcalidad);
    
    
    return (EXIT_SUCCESS);
}

