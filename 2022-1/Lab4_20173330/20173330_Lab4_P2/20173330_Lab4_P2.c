#include <stdio.h>
#include <stdlib.h>
#include "ab.h"
#include "abb.h"

void readData(ArbolBinarioBusqueda *tree);
void removefromMinimum(ArbolBinarioBusqueda *tad,int stocks,ArbolBinarioBusqueda *tadpadre);
// voy a buscar el nodo minimo y dependiendo de su stock se elegira que hacer si eliminarlo,actualizarlo o eliminarlo
// y volver a buscarel minimo del arbol actualizado
//usar los datos de ingreso del archivo P2_data.txt son los mismos que en la hoja de preguntas
int main() {
    ArbolBinarioBusqueda tree;
    construir_arbol_binario(&tree);
    readData(&tree);

    printf("El contenido del arbol en preorden:\n");
    pre_orden(tree);

    int stockToRemove;
    printf("\nIngresar la cantidad de solicitudes de despacho: ");
    scanf("%d",&stockToRemove);
    int stocks;
    for(int i=0;i<stockToRemove;i++){
        printf("\nIngresar la cantidad de unidades para el despacho %d: ",i+1);
        scanf("%d",&stocks);
        removefromMinimum(&tree,stocks,&tree);
        printf("El contenido del arbol en preorden, luego de extraer stock:\n");
        pre_orden(tree);

    }
    destruir_arbol_binario(&tree);

    return 0;
}

void readData(ArbolBinarioBusqueda *tree) {
    int fecha;
    int stock;
    while(1) {
        printf("Insertar fecha de caducidad y stock del producto. Ingresar -1 para terminar. ");
        scanf("%d %d",&fecha,&stock);
        if ((fecha==-1)||(stock==-1)) {
            break;
        }
        insertar(tree,fecha,stock);
    }
}

void removefromMinimum(ArbolBinarioBusqueda *tad,int stocks,ArbolBinarioBusqueda *tadpadre) {
	if (es_arbol_vacio(*tad)){
		printf("No se ha logrado despachar %d unidades.\n",stocks);
		exit(51);
	}
	if (es_arbol_vacio((*tad)->hijo_izq) && es_arbol_vacio((*tad)->hijo_der)) {
        if((*tad)->stock>stocks){
            // caso sea mayor el stock que se tiene, se actualiza el nodo con la nueva cantidad disponible
            (*tad)->stock = (*tad)->stock-stocks;
        } else if((*tad)->stock==stocks){
            //caso sean iguales se elimina el nodo
            *tad = NULL;
        } else {
            int new_stocks =  stocks - (*tad)->stock;
            *tad = NULL;
            //en el tercer caso el stock pedido sea mayor al stock que se tiene se elimina el nodo
            // y se vuelve a buscar al que tenga menor fecha de caducidad para volver a pedir
            // por eso le he pasado como parametro el tadpadre para que guarde el primer nodo del arbol
            removefromMinimum(tadpadre,new_stocks,tadpadre);
            
        }
        // se procede a buscar en el resto de nodos
    } else if (!es_arbol_vacio((*tad)->hijo_izq)) {
        removefromMinimum(&(*tad)->hijo_izq,stocks,tadpadre);
    } else if (!es_arbol_vacio((*tad)->hijo_der)) {
        //para el caso en que el nodo izquiero este vacio pero el derecho no significa que me encuentro en el menor nodo
        //entonces voy usar un eliminar especial para los casos donde se tenga que eliminar el nodo
        if((*tad)->stock>stocks){
            (*tad)->stock = (*tad)->stock-stocks;
        } else if((*tad)->stock==stocks){
            eliminar(tad,(*tad)->elemento);
        } else {
            int new_stocks =  stocks - (*tad)->stock;
            eliminar(tad,(*tad)->elemento);
            removefromMinimum(tadpadre,new_stocks,tadpadre);
            
        }
    }
}