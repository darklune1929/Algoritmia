#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
    TBinaryTree my_tree;
    char seguir;
    do{
        TInfo data;
        printf("Ingrese el nombre y precio del producto: ");
        scanf(" %c %d",&data.nombre,&data.price);
        printf("Se agrego el producto %c - %d \n",data.nombre,data.price);
        insert(&my_tree,data);
        printf("Desea seguir ingresando productos? (S(Si)/N(No)): ");
        scanf(" %c",&seguir);
    } while(seguir == 's' || seguir == 'S');
    balance_tree(&my_tree);
    int precio;
    print_preorder(my_tree.root);
    printf("Ingrese el precio para filtrar productos:");
    scanf("%d",&precio);
    int count=0;
    print_preorder_accesibles(my_tree.root,precio,&count);
    printf("%d resultados encontrados.\n",count);
}
