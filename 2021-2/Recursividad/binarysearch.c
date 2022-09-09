#include <stdio.h>
int binary_search(int arr[],int value,int ini,int end){
    if(ini>end)
        return -1;
    int med=(ini+end)/2;
    if(arr[med]==value)
        return med;
    else if (arr[med]<value)
        return binary_search(arr,value,med+1,end);
    else
        return binary_search(arr,value,ini,med-1);    
}
int main(){
    int arr[]={1,2,3,5,7,12,14,18,21,31};
    int res=binary_search(arr,7,0,7);
    if(res>=0)
        printf("El numero se encuentra en la posición %d\n",res);
    else
        printf("El numero no se encuentra en el arreglo.\n");
    return 0;
}