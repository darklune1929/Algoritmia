#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct QueueNode {
	int piso_destino;
    int direccion;
	struct QueueNode* next;
} TQueueNode;

typedef TQueueNode* MyQueue;

void create_queue(MyQueue *queue_ptr);
int is_empty(MyQueue queue);
void enqueue(MyQueue *, int,int);
int dequeue(MyQueue* queue_ptr);

void create_queue(MyQueue *queue_ptr){
	*queue_ptr = NULL;
}
int is_empty(MyQueue queue){
	return queue == NULL; 
}
void enqueue(MyQueue* queue_ptr, int pisod,int direc){
	TQueueNode * new_node_ptr = (TQueueNode *)malloc(sizeof(TQueueNode));
	new_node_ptr->piso_destino = pisod;
    new_node_ptr->direccion = direc;
	new_node_ptr->next = *queue_ptr;
	*queue_ptr = new_node_ptr;
}
int dequeue (MyQueue *queuePtr){
	TQueueNode * runner_ptr, *last_ptr;
	int destino = -1;
	if (!is_empty(*queuePtr)){
		runner_ptr = *queuePtr;
		last_ptr = NULL;
		while (runner_ptr->next){
			last_ptr = runner_ptr;
			runner_ptr = runner_ptr->next;
		}
		if (last_ptr == NULL) //Es verdadero cuando sólo había un elemento.
			*queuePtr = NULL;
		else
			last_ptr->next = NULL;
		destino = runner_ptr->piso_destino;
		free(runner_ptr);
	}
	return destino;
}
void imprimir_queue(MyQueue queue){
    printf("La cola de solicitudes del ascensor es: \n");
	if (is_empty(queue))
		printf("No hay solicitudes en la cola del ascensor\n");
	else {
		while (queue != NULL){
			printf("%d-%d -> ", queue->piso_destino,queue->direccion);
			queue = queue->next;
		}
	}
}
void ordenar_queue(MyQueue *queue){
    TQueueNode *runner_ptr,nodo_aux;
    runner_ptr=*queue;
    while(runner_ptr->next!=NULL){
        runner_ptr=runner_ptr->next;
    }
    if(runner_ptr->direccion==1){  //ordenar caso la cabeza sea de subida//
        runner_ptr=*queue;
        nodo_aux=runner_ptr;
        while(nodo_aux->direccion==0){ //Bubble sort// //Ordenar los que van de bajado//
            while(runner_ptr->direccion==0){
                if(runner_ptr->piso_destino>=runner_ptr->next->piso_destino){
                    cambiar_nodos(*queue); // me complique y sinceramente no se como intercambiarlos con las estructuras que hice//
                }
                runner_ptr=runner_ptr->next;
            }
            nodo_aux=nodo_aux->next;
        }
        while(nodo_aux!=NULL){ //ordenar los de subida//
            
            nodo_aux=nodo_aux->next;            
        }  
    } else{  // ordenar caso la cabeza sea de bajada

    }
}
void realizar_indicaciones(MyQueue *queue){

}
int main(){
    int p,s,piso_actual=1;
    MyQueue queue;
    printf("Ingrese la cantidad de pisos en el edificio: \n");
    scanf("%d",&p);
    printf("Movimientos del ascensor en un edificio de %d pisos\n",p);
    create_queue(&queue);
    enqueue(&queue,1,1);
    while(!is_empty(queue)){
        ordenar_queue(&queue); // va ordenar //
        imprimir_queue(queue);
        realizar_indicaciones(&queue,&piso_actual);      //me lleva al piso deseado despues del ordenamiento//
        printf("El ascensor esta en el piso %d: \n",piso_actual);
        printf("Ingrese la cantidad de solicitudes: \n");
        scanf("%d",&s);
        for(int i=0;i<s;i++){
            int piso,direccion;
            printf("Solicitud %d [numero_piso y direccion(1:sube,0:baja)]:\n",i+1);
            scanf("%d %d",&piso,&direccion);
            enqueue(&queue,piso,direccion);
        }
    }
}
