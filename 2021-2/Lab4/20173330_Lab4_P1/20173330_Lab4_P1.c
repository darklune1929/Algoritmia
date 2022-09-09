#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
    TBinaryTree my_tree;
    TInfo node;
	create_binary_tree(&my_tree);
    node.id = 10;
    node.quality = 1;
    insert(&my_tree,node);
    node.id = 5;
    node.quality = 2;
    insert(&my_tree,node);
    node.id = 20;
    node.quality = 2;
    insert(&my_tree,node);
    node.id = 2;
    node.quality = 3;
    insert(&my_tree,node);
    node.id = 6;
    node.quality = 3;
    insert(&my_tree,node);
    node.id = 21;
    node.quality = 3;
    insert(&my_tree,node);
    TInfo data;
    int can_insert;
    int can_update;
    data.id=16;
    data.quality=2;
    can_insert = can_be_inserted(my_tree.root,data.quality);
    data.id=1;
    data.quality=3;
    can_insert = can_be_inserted(my_tree.root,data.quality);
    print_bfs(my_tree.root);
    can_update = update_code(my_tree.root,17,10);
    can_update = update_code(my_tree.root,7,5);
    print_bfs(my_tree.root);
}
