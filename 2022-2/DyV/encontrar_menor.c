#include <stdio.h>
#include <stdlib.h>
int findPivot(int arr[], int low, int high)
{
    // base cases
    if (high < low)
        return -1;
    if (high == low)
        return low;
 
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
    return findPivot(arr, mid + 1, high);
}
int main(){
    int arr[] = {5,6,1,2,3,4};
    int n=6;
    printf("The minimum element is %d", arr[findPivot(arr, 0, n-1)+1]);
    return 0;
}