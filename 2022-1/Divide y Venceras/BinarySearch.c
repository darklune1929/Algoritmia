#include <stdio.h>
#include <stdlib.h>

int binarySearch(int item,int startPos,int endPos,int* array);

int main() {
    int numberOfItems;
    printf("Ingresar numero de elementos: ");
    scanf("%d",&numberOfItems);

    int* array = (int*)malloc(numberOfItems*sizeof(int));
    printf("Ingresar elementos del arreglo: ");
    for (int i=0;i<numberOfItems;i++) {
        scanf("%d",&array[i]);
    }

    int itemToFind;
    printf("Ingresar numero a buscar: ");
    scanf("%d",&itemToFind);

    int foundPosition = binarySearch(itemToFind,0,numberOfItems-1,array);
    if (foundPosition==-1) {
        printf("No se encontro el valor en el arreglo :(");
    } else {
        printf("Se encontro el valor en posicion %d",foundPosition);
    }

    free(array);

    return 0;
}

int binarySearch(int item,int startPos,int endPos,int* array) {
    if (startPos>endPos) {
        return -1;
    }

    int currentMidPos = (startPos+endPos)/2;
    if (item==array[currentMidPos]) {
        return currentMidPos;
    } else if (item>array[currentMidPos]) {
        return binarySearch(item,currentMidPos+1,endPos,array);
    } else {
        return binarySearch(item,startPos,currentMidPos-1,array);
    }
}