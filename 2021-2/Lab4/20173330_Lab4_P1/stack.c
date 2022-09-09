/*
 * Definición de funciones para el manejo de una pila.
 * Desarrollado por Johan Baldeón
*/
#include "stack.h"

void create_stack(TStack* stack_ptr){
	*stack_ptr = NULL;
}

int is_empty(TStack stack){
	return stack == NULL;
}

void push(TStack* stack_ptr, TInfo value){
	TStackNode *new_node_ptr;

	new_node_ptr = (TStackNode *)malloc(sizeof(TStackNode));
	new_node_ptr->elem = value;
	new_node_ptr->next = *stack_ptr;
	*stack_ptr = new_node_ptr;
}

TInfo pop(TStack *stack_ptr){
	TInfo value;
	TStackNode * node_to_free_ptr;

	if (!is_empty(*stack_ptr)){
		node_to_free_ptr = *stack_ptr;
		value = node_to_free_ptr->elem;
		*stack_ptr = node_to_free_ptr->next;
		free(node_to_free_ptr);
	}
	return value;
}

void show_stack(TStack stack){
	while (stack != NULL){
		printf("(%d - %d) ", stack->elem.id, stack->elem.quantity);
		stack = stack->next;
	}
}

void finalize_stack(TStack stack){
	TStackNode *ptr_to_free = stack;
	while (ptr_to_free != NULL){
		stack = ptr_to_free->next;
		free(ptr_to_free);
		ptr_to_free = stack;
	}
}

TInfo top(TStack stack) {
	return stack->elem;
}
