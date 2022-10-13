/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Colas.c
 * Author: cueva
 * 
 * Created on 26 de mayo de 2020, 02:54 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Colas.h"

/*Solo para impresion esta permitido trabajar como lista*/
void imprimecola(TCola ptrcola)
{
	while(ptrcola!=NULL){
		printf("%d  %s\n",ptrcola->elem,ptrcola->nombre);
		ptrcola=ptrcola->sig;
	}
	
	printf("\n");
}

/*implementacion de las funciones para la cola*/
void crea_cola(TCola *ptrCola){
    *ptrCola = NULL;
}

int cola_vacia(TCola ptrCola){
    return ptrCola==NULL;
}

/*encolar, se inserta un elemento al final de la cola. Se representa como una 
 insercion al inicio.*/
void encolar(TCola *ptrCola, int valor,char *cad){
    TNodoCola *ptrNuevo = (TNodoCola*)malloc(sizeof(TNodoCola));
    char *nombre;
    nombre = (char*)malloc(sizeof(char)*(strlen(cad)+1));
    strcpy(nombre,cad);
    ptrNuevo->elem=valor;
    ptrNuevo->nombre = nombre;
    ptrNuevo->sig=*ptrCola;
    *ptrCola=ptrNuevo; 

}
/*Encolar cadenas con prioridad*/
void encolarp(TCola *ptrCola, int valor,char *cad){
    char *nombre;
    TCola ptraux,ptrrec;
    TNodoCola *ptrNuevo = (TNodoCola*)malloc(sizeof(TNodoCola));
    nombre = (char*)malloc(sizeof(char)*(strlen(cad)+1));
    strcpy(nombre,cad);
    ptrNuevo->elem=valor;
    ptrNuevo->nombre = nombre;
    ptrNuevo->sig=NULL;
    
    ptraux = *ptrCola;
    ptrrec = NULL;
    while(ptraux){
        if(valor>=ptraux->elem) break;
        ptrrec = ptraux;
        ptraux = ptraux->sig;
    }
    if(ptrrec==NULL){
        ptrNuevo->sig = ptraux;
        *ptrCola = ptrNuevo;
    }
    else{
        ptrrec->sig = ptrNuevo;
        ptrNuevo->sig = ptraux;
    }
}


/*Solo para el desencolar esta permitido trabajar como lista*/
int desencolar(TCola *ptrCola)
{   TNodoCola *ptrRecorrido, *ptrUltimo;
    int valor;    
    if (!cola_vacia(*ptrCola))
    {
        ptrUltimo = NULL;
        ptrRecorrido = *ptrCola;
        while (ptrRecorrido->sig)
        {
            ptrUltimo = ptrRecorrido;
            ptrRecorrido = ptrRecorrido->sig;
        }
        if (ptrUltimo == NULL)
            *ptrCola=NULL;
        else
            ptrUltimo->sig=NULL; 
            
        valor=ptrRecorrido->elem;
        free(ptrRecorrido);
        return(valor);
    }
    
}

void desencolarp(TCola *ptrCola,int *valor,char *cad)
{   TNodoCola *ptrRecorrido, *ptrUltimo;
    if (!cola_vacia(*ptrCola))
    {
        ptrUltimo = NULL;
        ptrRecorrido = *ptrCola;
        while (ptrRecorrido->sig)
        {
            ptrUltimo = ptrRecorrido;
            ptrRecorrido = ptrRecorrido->sig;
        }
        if (ptrUltimo == NULL)
            *ptrCola=NULL;
        else
            ptrUltimo->sig=NULL; 
            
        *valor=ptrRecorrido->elem;
        strcpy(cad,ptrRecorrido->nombre);
        free(ptrRecorrido);
    }
    
}

void ordenacolarecp(TCola *ptrcola,int n){
    int menor,i=1,aux;
    char cmenor[100],caux[100];
    
    if(cola_vacia(*ptrcola)) return;
    if(n==1) return;
    desencolarp(ptrcola,&menor,cmenor);
    while(i<n){
        desencolarp(ptrcola,&aux,caux);
        if(aux > menor){
            encolar(ptrcola,menor,cmenor);
            menor= aux;
            strcpy(cmenor,caux);
        }
        else
            encolar(ptrcola,aux,caux);
        i++;
    }
    ordenacolarecp(ptrcola,n-1);//la recursion usa una pila
    encolar(ptrcola,menor,cmenor);    // donde va guardando el menor 
}
