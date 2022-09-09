/*
 * Laboratorio 4 (2021-1), pregunta 1
 * Desarrollado por Johan Baldeón
 */

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

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
	if (node->info.price  < root_node->info.price)
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

int is_present(TNode *node_ptr, int price){ // lo cambie para que en vez de usar Tinfo trabaje con el price del nodo
	int res = 0;
	if (node_ptr == NULL)
		return res;
	if (node_ptr != NULL && node_ptr->info.price == price)
		return 1;
	if (price < node_ptr->info.price)
		res = is_present(node_ptr->left, price);
	else
		res = is_present(node_ptr->right, price);
	return res;
}

void print_preorder(TNode *node_ptr){
	if (node_ptr == NULL) return;
	printf("(%d - %d)", node_ptr->info.id, node_ptr->info.quantity);
	print_preorder(node_ptr->left);
	print_preorder(node_ptr->right);
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
		if (data.price < aux->info.price)
			aux = aux->left;
		else if (data.price > aux->info.price)
			aux = aux->right;
	}

	if (parent == NULL)
		tree_ptr->root = new_node_ptr;
	else
		if (data.price <= parent->info.price)
			parent->left = new_node_ptr;
		else
			parent->right = new_node_ptr;
}

void remove_node(TBinaryTree * tree_ptr, TInfo data){
	TNode *aux = tree_ptr->root;
	TNode *the_node_ptr = NULL;
	while (aux != NULL){
		if ( aux->info.price == data.price) break;
		else if (data.price < aux->info.price){
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
//Pregunta b
//void balance_tree(TBinaryTree *my_tree){

//}
//Pregunta c
void print_preorder_accesibles(TNode *node_ptr,int precio,int *count){
	if (node_ptr == NULL) return;
	if(node_ptr->info.price <= precio) { // solo imprime si el precio del producto es menor o igual al ingresado por el usuario
		printf("(%c - %d)", node_ptr->info.nombre, node_ptr->info.price);
		(*count)++; // aumenta la cuenta de productos que han sido impresos y como estoy pasando la direccion de memoria esta se actualiza
	}
	print_preorder_accesibles(node_ptr->left,precio,count); // recorre el hijo izquierdo en preorden
	print_preorder_accesibles(node_ptr->right,precio,count); // recorre el hijo derecho en preorden
}