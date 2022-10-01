#include <stdio.h>
#include <stdlib.h>
int busqueda(int arr[][2],int K,int ini,int fin,int modo){
    //buscar de forma ascendente
    if(modo){
        if(ini>fin)
            return -1;
        
        int med = (ini+fin)/2;
        
        if(arr[med][0]==K)
            return med;
        if(arr[med][0]>K)	
            busqueda(arr,K,ini,med-1,modo);
        else
            busqueda(arr,K,med+1,fin,modo);	
    } else{
        //buscar de forma descendente
        if(ini>fin)
            return -1;
        
        int med = (ini+fin)/2;
        
        if(arr[med][0]==K)
            return med;
        if(arr[med][0]<K)	
            busqueda(arr,K,ini,med-1,modo);
        else
            busqueda(arr,K,med+1,fin,modo);	        
    }
}
int findMaximum(int arr[][2],int start,int end){
    if(start==end) return start;
    if((end==start+1) && arr[start][0]>=arr[end][0]) return start;
    if((end==start+1) && arr[start][0]<arr[end][0]) return end;
    int mid = (start+end)/2;
    if(arr[mid][0]>arr[mid+1][0] && arr[mid][0]>arr[mid-1][0]) return mid;
    if(arr[mid][0]>arr[mid+1][0] && arr[mid][0]<arr[mid-1][0]){
        return findMaximum(arr,start,mid-1);
    } else{
        return findMaximum(arr,mid+1,end);
    }
}

void cantidadStockProducto(int arr[][2],int ini,int fin,int numProducto,int* pos1,int* pos2){
    int pivote = findMaximum(arr,ini,fin);
    (*pos1) = busqueda(arr,numProducto,ini,pivote,1);
    (*pos2) = busqueda(arr,numProducto,pivote,fin,0);
}
int main(){
    int arrProductos[10][2]={{10,20},
							 {15,20},
							 {20,30},
						 	 {80,10},
						 	 {1000,10},
							 {200,10},
							 {100,20},
							 {50,20},
							 {20,20},
							 {10,10}};
    int n=10;
    int numProducto=20;
    int cantStock= 0;
    int pos1=5,pos2=5;
    cantidadStockProducto(arrProductos,0,n-1,numProducto,&pos1,&pos2);
    cantStock = arrProductos[pos1][1] + arrProductos[pos2][1];
    printf("La cantidad de stock es: %d\n",cantStock);
    printf("Se encuentran en las posiciones : %d y %d dentro del almacen.\n", pos1,pos2);
}