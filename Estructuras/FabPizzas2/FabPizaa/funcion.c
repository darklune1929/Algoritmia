/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcion.c
 * Author: cueva
 * 
 * Created on 9 de mayo de 2022, 12:16 PM
 */
#include <stdlib.h>
#include "lse.h"
#include "funcion.h"
#include "pilas.h"
#include "Colas.h"


void cargalista(int arr[],int prod[],int n,Lista *lista){
    construir_lista(lista);
    
    for(int i=0;i<n;i++)
        if(arr[i])
            insertar_al_final(lista,prod[i]);
    
}

void unifica(Lista *list1,Lista *list2){
    list1->cola->sig = list2->cabeza;
    list1->cola = list2->cola;
    list1->longitud = list1->longitud + list2->longitud;
}

void clasifica(Lista *list1,Pila *pil1,Pila *pil2,Pila *pil3){
    Nodo *ptraux;
    
    while(list1->cabeza){
        ptraux = list1->cabeza;
        if(ptraux->elemento==1)
            apilar(pil1,ptraux->elemento);
        if(ptraux->elemento==2)
            apilar(pil2,ptraux->elemento);        
        if(ptraux->elemento==3)
            apilar(pil3,ptraux->elemento);        
        
        list1->cabeza = ptraux->sig;
        free(ptraux);
    }    
    
}

int cargacola(Pila *pil1,Pila *pil2,Pila *pil3,Cola *cola1){
    int n=0;
    while(!es_pila_vacia(*pil1) && !es_pila_vacia(*pil2) 
            && !es_pila_vacia(*pil3)){
        pide_vez(cola1,desapilar(pil1));
        pide_vez(cola1,desapilar(pil2));
        pide_vez(cola1,desapilar(pil3));
        n++;
    }
    return n;
    
}