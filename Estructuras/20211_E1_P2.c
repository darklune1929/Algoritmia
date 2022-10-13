/*
 * Examen 1 (2021-1), pregunta 2
 * Desarrollado por Johan Baldeón
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int id;
	char timedate[15] ;
	char docType[3];
	char documentId[16];
	char txnType;
	double price;	
	int quantity;	

	struct Node* next;
	struct Node* prev;
} TNode;

typedef struct List{
	TNode* first;
	TNode* last;
} TList;

/* Prototipos */
void append_node(TList * list_ptr, TNode *node_ptr);
int list_size(TList list, char txnType);
void show_list(TList list, char txnType);
void reverse(TList *list_ptr);

/*Opcional*/ 
void finalize_list(TList list);

int main(){
	int i = 1, must_read=1;
	char res;
	TList list;
	while (must_read){
		printf("Ingrese los datos de la operación %d:\n", i);
		TNode* node = (TNode *) malloc(sizeof(TNode));
		node->id = i;
		printf("Fecha y hora de la operación [YYYYMMDDhhmmss]: ");
		scanf("%s", node->timedate);
		printf("Tipo de documento [01, 04, 06, 07, 11, 00]: ");
		scanf("%s", node->docType);
		printf("Número de documento: ");
		scanf("%s", node->documentId);
		printf("Tipo de operación [C, V]: ");
		scanf(" %c", &node->txnType);
		printf("Precio de la acción: ");
		scanf("%lf", &node->price);
		printf("Número de acciones: ");
		scanf("%d", &node->quantity);
		append_node(&list, node);

		printf("¿Desea ingresar más datos? [S,N]: " );
		scanf(" %c", &res);
		if (res == 'N' || res == 'n') must_read = 0;
		else if (res == 'S' || res == 's') i++;
	}

	printf("Ingrese el tipo de operación para mostrar las operaciones de compra (C) o de venta (V) [C, V]: ");
	scanf(" %c", &res);
	show_list(list, res);
	printf("La cantidad total de operaciones es %d.\n", list_size(list, res));
	reverse(&list);
	printf("Luego de la reversa se mostrarán las operaciones de compra (C) o de venta (V) [C, V]: ");
	scanf(" %c", &res);
	show_list(list, res);
	return 0;
}

void append_node(TList * list_ptr, TNode *new_node_ptr){	
	new_node_ptr->next = NULL;
	if (list_ptr->first == NULL){			
		new_node_ptr->prev = NULL;	
		list_ptr->first = new_node_ptr;
		list_ptr->last = new_node_ptr;
	} else {
		list_ptr->last->next = new_node_ptr;
		new_node_ptr->prev = list_ptr->last;	
		list_ptr->last = new_node_ptr;
	}
}

int list_size(TList list, char txnType){
	if (list.first == NULL )
		return 0;
	else {
		if (list.first->txnType == txnType) {
			list.first = list.first->next;
			return 1 + list_size(list, txnType);
		} else {
			list.first = list.first->next;
			return list_size(list, txnType);
		}
	}
}

void show_list(TList list, char txnType){
	if (list.first != NULL && list.last != NULL && list.first->txnType == txnType){
		printf("Op. %d, Fecha: %s, Tipo doc.: %s, Núm. doc.: %s, Tipo ope.: %c, Precio: %.2lf, Cant. acciones: %d\n", 
			list.first->id, list.first->timedate, list.first->docType, list.first->documentId, 
			list.first->txnType, list.first->price, list.first->quantity);
	}
	if (list.first != list.last) {		
		list.first = list.first->next;
		show_list(list, txnType);
	}
}

void reverse(TList *list_ptr){
	if (list_ptr->last == list_ptr->first){
		TNode *aux_node = list_ptr->last->prev;
		list_ptr->last->prev = list_ptr->last->next;
		list_ptr->last->next = aux_node;
		return;
	} else {
		TNode *last_node = list_ptr->last;
		TNode *first_node = list_ptr->first;
		TNode *aux_node = list_ptr->last->prev;
		list_ptr->last->prev = list_ptr->last->next;
		list_ptr->last->next = aux_node;
		list_ptr->last = aux_node;
		reverse(list_ptr);
		list_ptr->first = last_node;
		list_ptr->last = first_node;
	}
}

void finalize_list(TList list){
	if (list.first != NULL){
		TNode *ptr_to_free = list.first;
		list.first = list.first->next;
		free(ptr_to_free);
		finalize_list(list);
	}
}