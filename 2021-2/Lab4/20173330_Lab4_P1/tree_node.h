/*
 * Laboratorio 4 (2021-1), pregunta 1
 * Desarrollado por Johan Baldeón
 */

#include <stdlib.h>
#include "batch.h"

#ifndef TREE_NODE_H
#define TREE_NODE_H

typedef struct Node {
	TInfo info;
	struct Node *left, *right;
} TNode;

#endif