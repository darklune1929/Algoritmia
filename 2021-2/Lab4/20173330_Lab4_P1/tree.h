/*
 * Laboratorio 4 (2021-1), pregunta 1
 * Desarrollado por Johan Baldeón
 */

#include <stdlib.h>
#include "batch.h"
#include "stack.h"
#include "queue.h"
#include "tree_node.h"
/*
typedef struct Node {
	TInfo info;
	struct Node *left, *right;
} TNode;
*/
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
int is_tree_empty(TBinaryTree);
void remove_node(TBinaryTree *, TInfo);
void deallocate (TBinaryTree *, TNode *);
void free_binary_tree(TBinaryTree *);

/* Funciones resueltas de modo iterativo */
void insert_iter(TBinaryTree *, TInfo);

//Nuevas funciones
void print_bfs(TNode *);
int total_quality(TNode *,int );
int can_be_inserted(TNode *,int );
TNode* search_node(TNode *,int );
int update_code(TNode *,int ,int );