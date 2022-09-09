#include <stdio.h>
#include <stdlib.h>
// estructuras de cola y pila hechas por el profesor  Cueva//
typedef struct NodoCola{
    int peso;
    struct NodoCola* sig;
} TNodoCola;
typedef TNodoCola* TCola;
typedef struct NodoPila{
    int valor;
    struct NodoPila *ptrSig; /*estructura auto-referenciada*/
}TNodoPila;
typedef TNodoPila* Tpila ;
void createqueue(TCola *ptrCola){
    *ptrCola = NULL;
}
int emptyqueue(TCola ptrCola){
    return ptrCola==NULL;
}
int tamano_Cola(TCola ptrCola){   
    TCola ptrrec;
    int cont=0;
    ptrrec = ptrCola;
    while(ptrrec)
    {
        ptrrec=ptrrec->sig;
        cont++;
    }
    return cont;
}
void queue(TCola *ptrCola, int valor){
    TNodoCola *ptrNuevo = (TNodoCola*)malloc(sizeof(TNodoCola));
    ptrNuevo->peso=valor;
    ptrNuevo->sig=*ptrCola;
    *ptrCola=ptrNuevo; 
}
int unqueue(TCola *ptrCola){   
    TNodoCola *ptrRecorrido, *ptrUltimo;
    int peso;    
    if (!emptyqueue(*ptrCola))
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
        peso=ptrRecorrido->peso;
        free(ptrRecorrido);
        return(peso);
    }
}
void crearpila(Tpila *ptrpila) {
    *ptrpila=NULL;
}
void push(Tpila *Pila, int valor) {
    TNodoPila *ptrNuevo;
    
    ptrNuevo = (TNodoPila *) malloc(sizeof (TNodoPila));
    ptrNuevo->valor = valor;
    ptrNuevo->ptrSig = *Pila;
    *Pila = ptrNuevo;
    
}

int pila_vacia(Tpila *ptrPila){
    return *ptrPila==NULL;
}

int top(Tpila *ptrPila)
{   TNodoPila *ptrrec;
    
    ptrrec=*ptrPila;
    if(pila_vacia(ptrPila))
        printf("Pila vacia\n");
        return 99999999999;
    else
        return ptrrec->valor;

}

int pop(Tpila *Pila) {    
    TNodoPila *ptrEliminar;
    int valor;
    
    if (!pila_vacia(Pila)) { 
        ptrEliminar=*Pila;
        valor = ptrEliminar->valor; 
        *Pila = ptrEliminar->ptrSig; 
        free(ptrEliminar);
    }
    return valor;
}
int tamanopila(Tpila ptrPila)
{	Tpila  ptraux;
    
    if(ptrPila==NULL)
    	return 0;
    	
	ptraux=ptrPila;
	ptrPila=ptrPila->ptrSig;
	return(tamanopila(ptrPila)+1);
	

}
void insertar_Producto(&pilaP,&pila1,&pila2,pesosalida){

}
int main(){
    int peso,pesosalida,izq,der,cont=0;
    int memoria[500];
    TNodoCola Banda;
    TNodoPila pila1,pila2,pilaP;
    createqueue(&Banda);
    crearpila(&pila1);
    crearpila(&pila2);
    crearpila(&pilaP);
    while(peso!=0){
        printf("Ingrese los datos del peso a agregar a la faja transportadora(ingrese 0 para terminar de ingresar datos):");
        scanf("%d",&peso);
        if(peso!=0)
            queue(&Banda,peso);
    }
    while(!emptyqueue(Banda)){
        pesosalida=unqueue(&Banda);
        if(pesosalida<=top(pilaP)){
            push(&pilaP,pesosalida);
            memoria[cont]=pesosalida; // voy agregando en orden los pesos de los productos que ingresan a la pila
            cont++;
        } else{
            insertar_Producto(&pilaP,&pila1,&pila2,pesosalida);
        } 
    }


}