
#include <stdio.h>

int buscamayor(int arr[],int n){
	int opcion1,opcion2;
	
	if(n==1)	
		return(arr[n-1]);
	/*  20,8,11  ,16   ,10 */    // n = 5   
	opcion1=arr[n-1];            // opcion1=10
	opcion2=buscamayor(arr,n-1); // opcion2= 20
								// return 20	
	                            //  n=4 opcion1=16
	                             //  opcion2= 20
								 // return 20 
	                             // n=3 opcion1=11
	                             //  opcion2= 20
								 //  return 20  
	                             // n=2 opcion1=8
	                             //  opcion2= 20
								 //  return 20 
	                             // n=1 return 20
	if(opcion1<opcion2)
		return opcion2;
	else	
		return opcion1;
}

int buscanumero(int arr[],int n,int numero){
	if(n==0)
		return -1;
	if(arr[n-1]==numero)
		return(n-1);
	else
		buscanumero(arr,n-1,numero);		
}



int main(){
	int arreglo[]={20,8,11,16,10};
	int n=5;
	printf("Mayor: %d\n",buscamayor(arreglo,n));
	printf("Busca: %d\n",buscanumero(arreglo,n,12));
	return 0;
}
