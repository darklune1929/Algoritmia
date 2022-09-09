
#include <stdio.h>

int myArray[10] = {8,4,5,3,2,1,0,9,7,6};
void printfArray(int arraySize,int myArray[]);
void swap(int* value1,int* value2);
void selectionSort(int arraySize,int myArray[]);

int main(){
    printf("Arreglo desordenado: ");
    int arraySize = sizeof(myArray)/sizeof(int);
    printfArray(arraySize,myArray);
    selectionSort(arraySize,myArray);
    printf("Arreglo ordenado: ");
    printfArray(arraySize,myArray);
    //getchar();
    return 0;
}
void selectionSort(int arraySize,int myArray[]){
    for(int i = 0; i<arraySize;i++){
        int minPos = i;
        for(int j = i; j<arraySize;j++){
            if(myArray[minPos] > myArray[j]){
                minPos = j;
            }
        }
        swap(&myArray[i],&myArray[minPos]);
    }
}

void printfArray(int arraySize,int myArray[]){
    for (int i = 0;i<arraySize;i++){
        printf("%d",myArray[i]);
        if(i<(arraySize-1)){
            printf(",");
        } else{
            printf("\n");
        }
    }
}
void swap(int* value1,int* value2){
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}