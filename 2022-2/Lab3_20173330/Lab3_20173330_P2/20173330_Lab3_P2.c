#include <stdio.h>
#include <stdlib.h>
int encontrarMayor(int* arr,int start,int end){
    //caso base donde quede un elemento
    if(start==end)   return arr[start];
    //caso base donde queden 2 elementos se manda el mayor de estos
    if((end==start+1) && arr[start]>=arr[end])   return arr[start]; 
    if((end==start+1) && arr[start]<arr[end])      return arr[end]; 
    //caso para 3 a más elementos chequea por izquierda y derecha los posibles casos y retorna acorde a lo que encontro
    int mid = (start+end)/2;
    if(arr[mid]>arr[mid+1] && arr[mid]> arr[mid-1])   return arr[mid]; 
    if(arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1]){
        return encontrarMayor(arr,start,mid-1);
    } else{
        return encontrarMayor(arr,mid+1,end);
    }
}
int busqueda(int* A,int K,int start,int end){
	if(start>end)
		return -1;
	
	int mid = (start+end)/2;
	
	if(A[mid]==K)
		return mid;
	if(A[mid]>K)	
		 busqueda(A,K,start,mid-1);
	else
		 busqueda(A,K,mid+1,end);	
		
}
int main(){
    //ingreso de datos n m y matriz
    int n,m;
    printf("Ingrese los numeros(columnas) n y (filas) m: ");
    scanf("%d %d",&n,&m);
    int** arr = (int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++){
        arr[i] = (int*)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            scanf(" %d",&(arr[i][j]));
        }
    }
    //parte a
    // primero una variable en 0 para calcular el mayor resultado de la busqueda en el arreglo
    //luego recorro todas las filas con un for complejidad n y por cada fila busco el mayor numero con la función encontrar mayor que seria log(n)
    //finalmente teniendo nlog(n) y en caso este sea mayor a la mayorPotencia anterior se reemplaza
    int mayorPotencia=0;
    int mayor_columna;
    for(int i=0;i<m;i++){
        //la función encontrar mayor busca en un arreglo que este primero ascendiendo y luego descendiendo como [1,2,3,4,3,2,1]
        // dado que este problema presenta este patron se puede usar la función para hallar el mayor valor de cada fila
        int mayor = encontrarMayor(arr[i],0,n-1);
        if(mayor>=mayorPotencia){
            mayorPotencia=mayor;
            mayor_columna=i;
        }   
    }
    //parte b
    //usando los valores antes dado hago una bussqueda binaria en la columna donde encontre la mayor potencia asi encontrando la mayor fila
    int mayor_fila;
    mayor_fila = busqueda(arr[mayor_columna],mayorPotencia,0,m-1);
    printf("Para este juego de datos la potencia de la mas alta bomba es %d, y la columna donde se ubica es %d. La fila con mayor impacto es la %d.",mayorPotencia,mayor_columna
    ,mayor_fila);
    return 0;
}