/* Pregunta 1 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DIGITS 32
#define GTIN_DIGITS 13
#define PRODUCT_ID_POSITION 7
#define PRODUCT_ID_DIGITS 5
#define PRICE_DIGITS 7
#define STOCK_DIGITS 5
#define MIN_STOCK_DIGITS 4
#define DISCOUNT_DIGITS 3
#define PRODUCTS_COUNT 10

/* Defina las estructuras que sean necesarias para la solución de la pregunta 1 */
typedef struct QueueNode{
	char *product_id;
	int requested_quantity;
	double buy_price;
	struct QueueNode *next;
	struct QueueNode *previous;
} TQueueNode;

typedef struct Queue{
	TQueueNode *head;
	TQueueNode *last;
} TQueue;

typedef TQueue* MyQueue;

/* Prototipos de funciones */
/* Función que retorna el código del producto a partir de la trama de datos de un producto */
char* get_product_id(char * stream);
/* Función que retorna la categoría del producto a partir de la trama de datos de un producto */
char get_category(char * stream);
/* Función que retorna el precio del producto a partir de la trama de datos de un producto */
double get_price(char * stream);
/* Función que retorna el stock del producto a partir de la trama de datos de un producto */
int get_stock(char * stream);
/* Función que retorna el stock mínimo del producto a partir de la trama de datos de un producto */
int get_min_stock(char * stream);

/* Adicione los prototipos de sus funciones para la solución de la pregunta 1 */
void create_queue(MyQueue *);
void enqueue(MyQueue *ptrQueue, char *product_id, int requested_quantity,
				double buy_price);
double dequeue(MyQueue *, char category, double budget);
void show_queue_elements(MyQueue);

/* Arreglo de 10 tramas de productos */
char *db[] =	{	
	"77512344678920199990000020003000", 
	"77512342234560009690000070008000", 
	"77512343376540019990000100005000", 
	"77512341969690001990000090010000", 
	"77512343669990024990000020003000", 
	"77512341696960000990000030010000", 
	"77512342678920003990000040005000", 
	"77512342876540002990000060005000", 
	"77512343969690031990000020003000", 
	"77512342669990002990000050008000"
	};

int main(){
	int i, requested_quantity;
	char category;
	double budget, buy_price, old_budget;
	printf("Ingrese el monto límite a desembolsar para todas las compras: ");
	scanf("%lf", &budget);
	
	/* 	Programe lo necesario en el main para la solución de la pregunta 1
		invocando a las funciones que usted haya implementado.
	*/

	MyQueue myQueue;
	create_queue(&myQueue);

	printf("Los datos de los productos son:");
	for (i=0; i<PRODUCTS_COUNT; i++){ /*
		printf("\nTrama del producto %d: %s\n", i+1, db[i] );
		printf("Código: %s", get_product_id(db[i]));
		printf(", Categoría: %c", get_category(db[i]));
		printf(", Precio: %.2lf", get_price(db[i]) );
		printf(", Stock: %d", get_stock(db[i]) );
		printf(", Stock mínimo: %d \n", get_min_stock(db[i]) );
		*/
		if (get_stock(db[i]) < get_min_stock(db[i])){
			buy_price = get_price(db[i]) / 1.2;
			if (get_category(db[i]) == '1')
				requested_quantity = get_min_stock(db[i]) * 20;
			else
				requested_quantity = get_min_stock(db[i]) * 3;
			enqueue(&myQueue, get_product_id(db[i]), requested_quantity, buy_price);
		}
	}

	for (category='1'; category <='5'; category++){
		do {
			old_budget = budget;
			budget = dequeue(&myQueue, category, budget);
		} while (fabs(budget - old_budget) >= 0.01);
	}

	show_queue_elements(myQueue);
	printf("Monto del presupuesto restante: %.2lf\n", budget);
				
}

/* Defina las funciones necesarias para la solución de la pregunta 1 */

char* get_product_id(char * stream){
	char *str_product_id = (char *)malloc(PRODUCT_ID_DIGITS*sizeof(char));
	strncpy (str_product_id, stream + PRODUCT_ID_POSITION, PRODUCT_ID_DIGITS);
	return str_product_id;
}

char get_category(char * stream){
	return get_product_id(stream)[0];
}

double get_price(char * stream){
	char *str_price = (char *)malloc(PRICE_DIGITS*sizeof(char));
	strncpy (str_price, stream + GTIN_DIGITS, PRICE_DIGITS);
	return atoi(str_price)/100.0;
}

int get_stock(char * stream){
	char *str_stock = (char *)malloc(STOCK_DIGITS*sizeof(char));
	strncpy (str_stock, stream + GTIN_DIGITS + PRICE_DIGITS, STOCK_DIGITS);
	return atoi(str_stock);
}

int get_min_stock(char * stream){
	char *str_min_stock = (char *)malloc(MIN_STOCK_DIGITS*sizeof(char));
	strncpy (str_min_stock, stream + GTIN_DIGITS + PRICE_DIGITS + STOCK_DIGITS, MIN_STOCK_DIGITS);
	return atoi(str_min_stock);
}


void create_queue(MyQueue *ptrQueue){
	*ptrQueue = (TQueue *) malloc(sizeof(TQueue));
	(*ptrQueue)->head = NULL;
	(*ptrQueue)->last = NULL;
}
void enqueue(MyQueue *ptrQueue, char *product_id, int requested_quantity,
				double buy_price){
	TQueueNode *ptrNewNode = (TQueueNode*)malloc(sizeof(TQueueNode));
	ptrNewNode->product_id = product_id;
	ptrNewNode->requested_quantity = requested_quantity;
	ptrNewNode->buy_price = buy_price;
	ptrNewNode->next = (*ptrQueue)->last;
	ptrNewNode->previous = NULL;
	if ((*ptrQueue)->last != NULL)
		(*ptrQueue)->last->previous = ptrNewNode;
	(*ptrQueue)->last = ptrNewNode;
	if ((*ptrQueue)->last->next == NULL)
		(*ptrQueue)->head = (*ptrQueue)->last;
}
double dequeue(MyQueue *ptrQueue, char category, double budget){
	TQueueNode *ptr_runner = (*ptrQueue)->head;
	char * product_id;
	char node_category;
	double node_total_amount;
	int quantity_to_buy;

	while (ptr_runner != NULL){
		product_id = ptr_runner->product_id;
		node_category = product_id[0];
		if (node_category == category){
			node_total_amount = ptr_runner->requested_quantity * ptr_runner->buy_price;
			if (node_total_amount <= budget){
				if (ptr_runner->previous != NULL)
					ptr_runner->previous->next = ptr_runner->next;
				else 
					(*ptrQueue)->last = ptr_runner->next;

				if (ptr_runner->next != NULL)
					ptr_runner->next->previous = ptr_runner->previous;
				else
					(*ptrQueue)->head = ptr_runner->previous;

				quantity_to_buy = ptr_runner->requested_quantity;
				budget -= node_total_amount;
				free(ptr_runner);
			} else {
				quantity_to_buy = budget / ptr_runner->buy_price;
				ptr_runner->requested_quantity -= quantity_to_buy;
				node_total_amount = ptr_runner->buy_price * quantity_to_buy;
				budget -= node_total_amount;
			}
			if (quantity_to_buy > 0)
				printf("Del producto %s se comprarán %d unidades por un valor de %.2lf.\n",
						product_id, quantity_to_buy, node_total_amount);
		}
		ptr_runner = ptr_runner->previous;
	}
	return budget;
}
void show_queue_elements(MyQueue myQueue){
	if (myQueue->last == NULL)
		printf("No hay pedidos en la cola.\n");
	else{
		TQueueNode *ptr_runner = myQueue->last;
		printf("Datos de los pedidos que quedaron en la cola:\n");
		while (ptr_runner != NULL){
			printf("Prod.:%s, cantidad a pedir: %d, precio unitario de compra: %.2lf \n",
					ptr_runner->product_id, ptr_runner->requested_quantity,
					ptr_runner->buy_price);
			ptr_runner = ptr_runner->next;
		}
		printf("\n");
	}
}

