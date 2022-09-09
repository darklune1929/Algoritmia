/*
 * Estructura y prototipos de funciones para el manejo de una pila.
 * Desarrollado por Johan Baldeón
*/
#include <stdio.h>
#include <stdlib.h>
#include "batch.h"

#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
	TInfo elem;
	struct StackNode* next;
} TStackNode;

typedef TStackNode* TStack;

/* Prototipos */
void create_stack(TStack* stack_ptr);
int is_empty(TStack stack);
void show_stack(TStack stack);
void finalize_stack(TStack stack);
void push(TStack* stack_ptr, TInfo value);
TInfo pop(TStack *stack_ptr);
TInfo top(TStack stack);

#endif /* STACK_H */
