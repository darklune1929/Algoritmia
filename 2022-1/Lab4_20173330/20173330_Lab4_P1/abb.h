#ifndef ABB_H
#define ABB_H
#include "ab.h"

typedef ArbolBinario ArbolBinarioBusqueda;

void insertar(ArbolBinarioBusqueda *, ElementoArbol);
void insertar_iterativo(ArbolBinarioBusqueda *, ElementoArbol);
int esta(ArbolBinarioBusqueda, ElementoArbol);
int esta_iterativo(ArbolBinarioBusqueda, ElementoArbol);
int minimo_valor(ArbolBinarioBusqueda);
int maximo_valor(ArbolBinarioBusqueda);
int minimo_iterativo(ArbolBinarioBusqueda);
int maximo_iterativo(ArbolBinarioBusqueda);
void eliminar(ArbolBinarioBusqueda *, ElementoArbol);
void eliminar_auxiliar(ArbolBinarioBusqueda *, ArbolBinarioBusqueda *);
void can_be_inserted(ArbolBinarioBusqueda *tad, ElementoArbol elemento);
void can_be_updated(ArbolBinarioBusqueda *tad, ElementoArbol elemento);
#endif