/*
 * Laboratorio 4 (2021-1), pregunta 1
 * Desarrollado por Johan Baldeón
 */

#include <stdlib.h>

typedef struct Batch{
	char nombre;
	int price;
} TInfo;
typedef struct Node {
	TInfo info;
	struct Node *left, *right;
} TNode;

typedef struct Tree{
	TNode * root;
} TBinaryTree;

/*Prototipos*/
void create_binary_tree(TBinaryTree *);
void insert(TBinaryTree *, TInfo);
TNode * insert_rec(TNode *, TNode *);
int height(TNode *);
int weight(TNode *);
int is_present(TNode *,int);
void print_preorder(TNode *)
int is_tree_empty(TBinaryTree);
void remove_node(TBinaryTree *, TInfo);
void deallocate (TBinaryTree *, TNode *);
void free_binary_tree(TBinaryTree *);

/* Funciones resueltas de modo iterativo */
void insert_iter(TBinaryTree *, TInfo);

//Nuevas funciones
void print_preorder_accesibles(TNode *,int ,int *);