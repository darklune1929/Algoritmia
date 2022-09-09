/*
 * Estructura y prototipos de funciones para el manejo de una cola.
 * Desarrollado por Johan Baldeón
*/
#include <stdio.h>
#include <stdlib.h>
#include "batch.h"
#include "tree_node.h"

#ifndef QUEUE_H
#define QUEUE_H


typedef struct QueueNode {
	//TInfo elem;
	TNode* elem;
	struct QueueNode* next;
	struct QueueNode* previous;
} TQueueNode;


typedef struct Queue {
	TQueueNode* top;
	TQueueNode* bottom;
	int size;
} TQueue;

void create_queue(TQueue *queue_ptr);
int is_queue_empty(TQueue* queue);
TInfo* peek(TQueue);
//void enqueue(TQueue *, TInfo);
void enqueue(TQueue *, TNode *);
//TInfo* dequeue(TQueue* queue_ptr);
TNode* dequeue(TQueue* queue_ptr);
void show_queue_elements(TQueue*);
void finalize_queue(TQueue*);
int get_queue_size(TQueue*);

#endif /* QUEUE_H */
