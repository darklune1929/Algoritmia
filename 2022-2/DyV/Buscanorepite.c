
#include<stdio.h> 
  
void search(int arr[],int cantidad[], int low, int high) 
{ 
    if (low > high) 
       return; 
  
    if (low==high) 
    { 
        printf("Los elementos son %d %d %d %d \n",low-2,low-1, low, arr[low]);
		printf("El stock suma:%d",cantidad[low-2]+cantidad[low-1]+cantidad[low]);
        return; 
    } 
  
  
    int mid = (low + high) / 2; 
  
    if (mid%2 == 0) 
    { 
        if (arr[mid] == arr[mid+1]) 
            search(arr,cantidad, mid+2, high); 
        else
            search(arr,cantidad, low, mid); 
    } 
    else  
    { 
        if (arr[mid] == arr[mid-1]) 
            search(arr,cantidad, mid+1, high); 
        else
            search(arr,cantidad, low, mid-1); 
    } 
} 


int main() 
{ 
    int arr[] = {1, 1, 2, 2, 4, 4, 5, 5, 5, 6, 6}; 
    int cantidad[]={20,20,30,10,10,10,20,20,20,10,10};
    int len = sizeof(arr)/sizeof(arr[0]); 
    search(arr,cantidad,0, len-1); 
    return 0; 
} 










