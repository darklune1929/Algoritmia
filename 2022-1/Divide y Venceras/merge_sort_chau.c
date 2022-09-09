#include <stdio.h>
#include <stdlib.h>
void merge();
void mergeSort(int startPos,int endPos,int* array);
int main(){
	int numberOfElements;
	printf("Ingresar numero de elementos: ");
	scanf("%d",&numberOfElements);

    int* array = (int*)malloc(numberOfElements*sizeof(int));
    printf("Ingresar elementos del arreglo: ");
    for(int i=0;i<numberOfElements;i++){
        scanf("%d",&array[i]);
    }
	int itemToFind;
	mergeSort(0,numberOfElements-1,array);

    printf("El arreglo ordenado es: ");
    for(int i=0;i<numberOfElements;i++){
        printf("%d",array[i]);
    }

    free(array);
    return 0;
}
void merge(int startPos,int currentMidPos,int endPos,int* array){
    int size1 = currentMidPos-startPos+1;
    int size2 = endPos-currentMidPos;

    int* array1 = (int*)malloc(size1*sizeof(int));
    for(int i=0;i<size1;i++){
        array1[i]=array[startPos+i];
    }
    int* array2 = (int*)malloc(size2*sizeof(int));
    for(int i=0;i<size2;i++){
        array2[i]=array[currentMidPos+i+1];
    }
    int i = 0;
    int j = 0;
    int k = startPos;
    while(i<size1 && j<size2){
        if(array1[i]<array2[j]){
            array[k] = array1[i];
            i++;
        } else {
            array[k] = array2[j];
            j++;
        }
        k++;
    }

    while(i<size1) {
        array[k] = array1[i];
        i++;
        k++;
    }
    while(j<size2) {
        array[k] = array2[j];
        j++;
        k++;
    }    
    free(array1);
    free(array2);
}
void mergeSort(int startPos,int endPos,int* array){
    if(startPos>=endPos){
        return;
    }

    int currentMidPos = (startPos+endPos)/2;
    mergeSort(startPos,currentMidPos,array);
    mergeSort(currentMidPos+1,endPos,array);
}