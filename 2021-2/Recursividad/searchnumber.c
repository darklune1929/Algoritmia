#include <stdio.h>
int search_number(int arr[],int ini_index,int n,int number_to_search){
    if(n==0) return -1; 
    if(number_to_search==arr[ini_index]) return ini_index;
    else
        return search_number(arr,ini_index+1,n-1,number_to_search);
}

int main(){
    int arr[20]={666,669,96,999,969,0xFFF,123,0777};
    int n=8,num;
    printf("Ingrese un numero: ");
    scanf("%d",&num);
    int res= search_number(arr,0,n,num);
    if(res>0)
        printf("El numero %d esta en la posicion %d \n",num,res);
    else
        printf("El numero no se encuentra en el arreglo\n");
    return 0;
}