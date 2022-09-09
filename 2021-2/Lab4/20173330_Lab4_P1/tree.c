/*
 * Laboratorio 4 (2021-1), pregunta 1
 * Desarrollado por Johan Baldeón
 */

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include <math.h>

/* Definición de funciones */
void create_binary_tree(TBinaryTree *binary_tree_ptr){
	binary_tree_ptr->root = NULL;
}

void insert(TBinaryTree *binary_tree_ptr, TInfo data){
	TNode *new_node_ptr = (TNode *) malloc(sizeof(TNode));
	new_node_ptr->info = data;
	new_node_ptr->left = new_node_ptr->right = NULL;
	if (binary_tree_ptr->root == NULL)
		binary_tree_ptr->root = insert_rec(binary_tree_ptr->root, new_node_ptr);
	else
		insert_rec(binary_tree_ptr->root, new_node_ptr);
}

TNode* insert_rec(TNode *root_node, TNode *node){
	if (root_node == NULL){
		return node;
	}
	if (node->info.id  < root_node->info.id)
		root_node->left = insert_rec(root_node->left, node);
	else
		root_node->right = insert_rec(root_node->right, node);
	return root_node;
}

int height(TNode *node_ptr){
	if (node_ptr == NULL) return 0;
	int left_height = height(node_ptr->left);
	int right_height = height(node_ptr->right);
	return 1+ (left_height > right_height ? left_height : right_height);
}

int weight(TNode *node_ptr){
	if (node_ptr == NULL) return 0;
	return 1 + weight(node_ptr->left) + weight(node_ptr->right);
}

int is_present(TNode *node_ptr, int id){ // lo cambie para que en vez de usar Tinfo trabaje con el id del nodo
	int res = 0;
	if (node_ptr == NULL)
		return res;
	if (node_ptr != NULL && node_ptr->info.id == id)
		return 1;
	if (id < node_ptr->info.id)
		res = is_present(node_ptr->left, id);
	else
		res = is_present(node_ptr->right, id);
	return res;
}


int is_tree_empty(TBinaryTree tree) {
	return tree.root == NULL;
}

void insert_iter(TBinaryTree * tree_ptr, TInfo data){
	TNode *new_node_ptr = (TNode *) malloc(sizeof(TNode));
	new_node_ptr->info = data;
	new_node_ptr->left = new_node_ptr->right = NULL;

	TNode * aux = tree_ptr->root;
	TNode *parent = NULL;
	while (aux != NULL){
		parent = aux;
		if (data.id < aux->info.id)
			aux = aux->left;
		else if (data.id > aux->info.id)
			aux = aux->right;
	}

	if (parent == NULL)
		tree_ptr->root = new_node_ptr;
	else
		if (data.id <= parent->info.id)
			parent->left = new_node_ptr;
		else
			parent->right = new_node_ptr;
}

void remove_node(TBinaryTree * tree_ptr, TInfo data){
	TNode *aux = tree_ptr->root;
	TNode *the_node_ptr = NULL;
	while (aux != NULL){
		if ( aux->info.id == data.id) break;
		else if (data.id < aux->info.id){
			the_node_ptr = aux;
			aux = aux->left;
		} else {
			the_node_ptr = aux;
			aux = aux->right;
		}
	}
	if (aux == NULL) return;

	//En el caso que el nodo a eliminar fuese una hoja
	if (aux->left == NULL && aux->right == NULL){
		if (the_node_ptr == NULL)
			tree_ptr->root = NULL;
		else
			if (the_node_ptr->left == aux) the_node_ptr->left = NULL;
			else if (the_node_ptr->right == aux) the_node_ptr->right = NULL;
		free(aux);
		return;	
	}
	//En el caso que el nodo a eliminar tenga un solo hijo por la izquierda.
	if (aux->left != NULL && aux->right == NULL) {
		if (the_node_ptr == NULL)
			tree_ptr->root  = aux->left;
		else 
			if (the_node_ptr->left == aux) the_node_ptr->left = aux->left;
			if (the_node_ptr->right == aux) the_node_ptr->right = aux->left;
		free(aux);
		return;	
	}

	//En el caso que el nodo a eliminar tenga un solo hijo por la derecha.
	if (aux->left == NULL && aux->right != NULL) {
		if (the_node_ptr == NULL)
			tree_ptr->root  = aux->right;
		else 
			if (the_node_ptr->left == aux) the_node_ptr->left = aux->right;
			if (the_node_ptr->right == aux) the_node_ptr->right = aux->right;
		free(aux);
		return;	
	}

	//En el caso que el nodo a eliminar tenga dos hijos
	TNode* q = aux->left;
	while (q->right != NULL) q = q ->right;

	TInfo key = q->info;
	remove_node(tree_ptr, key);
	aux->info = key;
}

void deallocate (TBinaryTree * tree_ptr, TNode *node_ptr){
    if (node_ptr == NULL)
        return;
    deallocate(tree_ptr, node_ptr->left);
    deallocate(tree_ptr, node_ptr->right);
    remove_node(tree_ptr, node_ptr->info);
}

void free_binary_tree(TBinaryTree *tree_ptr) {
	deallocate(tree_ptr, tree_ptr->root);
}
//Pregunta a 
void print_bfs(TNode *root_ptr) {
	TQueue my_queue;
	create_queue(&my_queue);
	TNode * node_ptr = root_ptr;
	while (node_ptr){
		printf("(%d - %d) ", node_ptr->info.id, node_ptr->info.quality);
		if (node_ptr->left)
			enqueue(&my_queue, node_ptr->left);
		if (node_ptr->right)
			enqueue(&my_queue, node_ptr->right);
		node_ptr = dequeue(&my_queue);
	}
}
//Pregunta b
int total_quality(TNode *node_ptr,int quality){
	if(node_ptr->info.quality == quality)
		return 1 + total_quality(node_ptr->left,quality) + total_quality(node_ptr->right,quality); // sumo 1 al contador solo si la calidad del
		//producto actual es igual a la que se le paso de la anterior función
	else 
		return total_quality(node_ptr->left,quality) + total_quality(node_ptr->right,quality);
}
int can_be_inserted(TNode *node_ptr,int quality){
	int max=pow(quality,2); // calculo el maximo de productos de esta calidad posible
	int count; //contador para recorrer el arbol
	count = total_quality(node_ptr,quality);
	if(count < max){
		printf("Se puede insertar al arbol el producto de calidad %d\n",quality);
		return 1;
	} else{
		printf("No se puede insertar al arbol el producto de calidad %d\n",quality);
		return 0;
	}
}
//Pregunta c
TNode* search_node(TNode *node_ptr,int codantiguo){ // recorro el arbol devolviendo el nodo dado que ya he verificado que si
// se encuentra en el arbol
	TNode *node;
	if(node_ptr->info.id == codantiguo) return node_ptr; // verifico si el nodo coincide con el codigo del producto
	if(node_ptr!=NULL){
	 	node = search_node(node_ptr->left,codantiguo);
	 	node = search_node(node_ptr->right,codantiguo);
	}
	 return node;

}
int update_code(TNode *node_ptr,int codnuevo,int codantiguo){
	TNode *node_searched;// creo nodo auxiliar para guardar el valor del nodo que voy a buscar en el arbol
	if (is_present(node_ptr,codantiguo) && !(is_present(node_ptr,codnuevo))){ // verifico con la función is_present si el producto esta
	// en el arbol además que el nuevo codigo no se encuentre ya registrado
		node_searched = search_node(node_ptr,codantiguo);
		if(node_searched->info.id > node_searched->left->info.id && node_searched->info.id < node_searched->right->info.id){
			printf("El producto con codigo %d se puede actualizar al codigo %d.\n",codantiguo,codnuevo); // verifica que el codigo nuevo es
			// mayor al hijo izquierdo, además que sea menor al hijo derecho
			return 1;
		} else{
			printf("El producto con codigo %d no se puede actualizar al codigo %d.\n",codantiguo,codnuevo);
			return 0;
		} 
	} else{
		printf("El producto que se quiere actualizar no se encuentra en el arbol.\n");
	}
}
