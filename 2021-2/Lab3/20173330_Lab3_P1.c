#include <stdio.h>
#include <stdlib.h>
/* funciones que use del programa colas.c del profesor Cueva de paideia adaptadas para este
createqueue,emptyqueue,tamano_cola,queue,imprime_cola,unqueue*/
typedef struct NodoCola{
    int piso;
    int direccion;
    struct NodoCola* sig;
} TNodoCola;
typedef TNodoCola* TCola;
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
void queue(TCola *ptrCola, int valor,int dir){
    TNodoCola *ptrNuevo = (TNodoCola*)malloc(sizeof(TNodoCola));
    ptrNuevo->piso=valor;
    ptrNuevo->direccion=dir;
    ptrNuevo->sig=*ptrCola;
    *ptrCola=ptrNuevo; 
}
int unqueue(TCola *ptrCola){   
    TNodoCola *ptrRecorrido, *ptrUltimo;
    int piso;    
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
        piso=ptrRecorrido->piso;
        free(ptrRecorrido);
        return(piso);
    }
}
void imprimecola(TCola ptrcola){
	while(ptrcola!=NULL){
		printf(" %d-%d ->",ptrcola->piso,ptrcola->direccion);
		ptrcola = ptrcola->sig;
	}
	printf("\n");
}
void pasar_colas(TCola* colag,TCola* cola1,TCola* cola2,int tamano){
    TNodoCola *ptrrec,*ptraux;
    ptrrec = *colag;
    int i=1;
    if(tamano==0) return;
    while(ptrrec!=NULL && i<=tamano){
        ptraux=ptrrec;
        ptrrec = ptrrec->sig;
        i++;
    }
    if(ptraux->direccion){
        queue(cola1,ptraux->piso,ptraux->direccion);
    } else{
        queue(cola2,ptraux->piso,ptraux->direccion);
    }
    pasar_colas(colag,cola1,cola2,tamano-1);
}
int main(){
    int pisos,pisoCola1,pisoCola2;
    TCola colag,cola1,cola2;
    printf("Ingrese la cantidad de pisos del edificio: \n");
    scanf("%d",&pisos);
    printf("Movimientos del ascensor en un edificio de %d pisos:\n",pisos);
    createqueue(&colag);
    createqueue(&cola1);
    createqueue(&cola2);
    queue(&colag,1,1);
    queue(&cola1,1,1);
    queue(&cola2,1,1);
    while(!emptyqueue(colag)){
        int solicitudes,n;
        TNodoCola *ptrrec;
        printf("La cola general de solicitudes tiene:\n");
        imprimecola(colag);
        printf("Luego de asignar las solicitudes del ascensor se tiene:\n");
        //ordenacola(&cola1,cola1->piso,cola1->direccion);
        //ordenacola(&cola2,cola2->piso,cola2->direccion);
        imprimecola(cola1);
        imprimecola(cola2);
        pisoCola1=unqueue(&cola1);
        pisoCola2=unqueue(&cola2);
        printf("El ascensor 1 esta en el piso: %d\n",pisoCola1);
        printf("El ascensor 2 esta en el piso: %d\n",pisoCola2);
        printf("Ingrese la cantidad de solicitudes: ");
        scanf("%d",&solicitudes);
        printf("\n");
        for(int i=1;i<=solicitudes;i++){
            int p,d; //piso direccion
            printf("Solicitud %d[numero_piso y direccion(1:sube,0:baja)]:",i);
            scanf("%d %d",&p,&d);
            queue(&colag,p,d);
        }
        n = tamano_Cola(colag);
        pasar_colas(&colag,&cola1,&cola2,n);
    }
    return 0;
}

