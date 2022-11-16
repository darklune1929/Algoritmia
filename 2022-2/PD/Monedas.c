#include <stdio.h>

int coinrow(int arr[],int n){
	int F[n+1];
	int i,a,b;
	
	F[0] =0;
	F[1] =arr[0];
	
	for(i=2;i<=n;i++){
		a = F[i-1];
		b = F[i-2]+arr[i-1];
		
		if(a<b)
			F[i]=b;
		else	
			F[i]=a; 
		
	}
	
	return F[n];
}


int main(){
	int monedas[]={5,1,2,10,6,2};
	int n=6;
	
	int cant=coinrow(monedas,n);
	printf("La respuesta es:%d",cant);
	return 0;	
}
