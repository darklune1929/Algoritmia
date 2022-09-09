#include <stdio.h>
int greater(int arr[],int ini_index,int n){
    if(n==1) return arr[ini_index];
    int max=greater(arr,ini_index+1,n-1);
    if(arr[ini_index]>max) return arr[ini_index];
    return max;
    // return arr[ini_index] > max ? arr[ini_index] : max;
}

int main(){
    int arr[20]={666,669,96,999,969,0xFFF,123,0777};
    int n=8,i=0;
    printf("El maximo es: %d. \n ",greater(arr,i,n));
    return 0;
}