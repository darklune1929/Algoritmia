#include <stdio.h>
#include <stdlib.h>
int findMinMax(int arr[], int start, int end,int* min,int* max){
    if(start == end){
        if((*max)<arr[start]) (*max)= arr[start];
        if((*min)>arr[end]) (*min)= arr[end];
        return;
    }
    if(end-start==1){
        if(arr[start]<arr[end]){
            if((*min)>arr[start]) (*min)= arr[start];
            if((*max)<arr[end]) (*max)= arr[end];
            return;
        } else {
            if((*min)>arr[end]) (*min)= arr[end];
            if((*max)<arr[start]) (*max)= arr[start];
            return;
        }
        return;
    }
    int mid = (start+end)/2;
    findMinMax(arr,start,mid,min,max);
    findMinMax(arr,mid+1,end,min,max);
}
int main(){
    int arr[] = {7, 2, 9, 3, 1, 6, 7, 8, 4};
    int n=9;
    int max=INT_MIN,min=INT_MAX;
    findMinMax(arr,0,n-1,&min,&max);
    printf("The minimum number in the array is %d\n",min);
    printf("The maximum number in the array is %d",max);
    return 0;
}