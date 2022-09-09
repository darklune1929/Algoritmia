/*
 * Definición de funciones para el manejo de una cola.
 * Desarrollado por Johan Baldeón
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void create_queue(TQueue *queue_ptr){
	if (queue_ptr != NULL){
		queue_ptr->size = 0;
		queue_ptr->top = NULL;
		queue_ptr->bottom = NULL;
	}	
}

int is_queue_empty(TQueue *queue){
	return queue == NULL || queue->size == 0 ; 
}

TInfo* peek(TQueue queue){
	return &(queue.top->elem->info);
}

//void enqueue(TQueue* queue_ptr, TInfo value){
void enqueue(TQueue* queue_ptr, TNode * value){
	TQueueNode* new_node_ptr = (TQueueNode *)malloc(sizeof(TQueueNode));
	new_node_ptr->elem = value;
	new_node_ptr->next = queue_ptr->bottom;
	new_node_ptr->previous = NULL;
	
	if (queue_ptr->size == 0){
		queue_ptr->top = new_node_ptr;		
	} else {
		queue_ptr->bottom->previous = new_node_ptr;
	}
	queue_ptr->bottom = new_node_ptr;
	queue_ptr->size++;
}

//TInfo* dequeue (TQueue *queue_ptr){
TNode* dequeue (TQueue *queue_ptr){
	//TInfo* elem_ptr = NULL;
	TNode* elem_ptr = NULL;	

	if (queue_ptr->size > 0) {
		TQueueNode* aux_node = queue_ptr->top;
		//elem_ptr = &(queue_ptr->top->elem);
		elem_ptr = queue_ptr->top->elem;
		
		if (queue_ptr->size > 1){
			aux_node->previous->next = NULL;
			queue_ptr->top = aux_node->previous;			
		} else {
			queue_ptr->bottom = NULL;
			queue_ptr->top = NULL;
		}
		free(aux_node);
		queue_ptr->size--;
	}	
	return elem_ptr;
}

void show_queue_elements(TQueue* queue){
	if (is_queue_empty(queue))
		printf("La cola está vacía.\n");
	else {
		printf("Datos de la cola de tamaño %d:\n", queue->size);
		TQueueNode *aux_node = queue->bottom;
		while (aux_node != NULL){			
			printf("%d-%d -> ", aux_node->elem->info.id, aux_node->elem->info.quality);
			aux_node = aux_node->next;
		} 		
	}
}

void finalize_queue(TQueue *queue){	
	if (!is_queue_empty(queue)) {
		printf("Se liberaron los siguientes nodos: ");
		TQueueNode *ptr_to_free = queue->bottom;
		while (ptr_to_free != NULL){
			printf("%d:%d ", ptr_to_free->elem->info.id, ptr_to_free->elem->info.quality);
			queue->bottom = ptr_to_free->next;		
			free(ptr_to_free);
			ptr_to_free = queue->bottom;
		}
		queue->bottom = NULL;
		queue->top = NULL;		
	}
}

int get_queue_size(TQueue* queue_ptr){
	return queue_ptr->size;
}