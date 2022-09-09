#include <stdio.h>
void selection_sort(int arr[],int n);
void bubble_sort (int arr[],int n);
void print_array(int arr[],int size){
    int i;
    for (i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main(){
    int arr[]={666,699,999,333,123,6,9,96};
    int n=sizeof(arr)/sizeof(arr[0]);

    //selection_sort(arr,n);
    bubble_sort(arr,n);
    printf("Arreglo ordenado: \n");
    print_array(arr,n);

    return 0;
}
void swap (int *e1,int *e2){
    int aux=*e1;
    *e1=*e2;
    *e2=aux;
}
void selection_sort (int arr[],int n){
    int i,j,min;
    for (i=0;i<=n-2;i++){
        min=i;
        for (j=i+1;j<=n-1;j++)
            if(arr[j]<arr[min])
                min=j;
        swap(&arr[min],&arr[i]);        
    }
}
void bubble_sort (int arr[],int n){
    int i,j;
    for(i=0;i<=n-2;i++)
        for(j=0;j<=n-2-i;j++)
            if(arr[j+1]<arr[j])
                swap(&arr[j],&arr[j+1]);
}


