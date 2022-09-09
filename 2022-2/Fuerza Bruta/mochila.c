#include <stdio.h>
#include <math.h>

void cargabin(int num,int n,int cromo[]){
	int res,i;
	for(i=0;i<n;i++) cromo[i]=0;
	i=0;
	while(num>0){
		res = num%2;
		num = num/2;
		cromo[i]=res;
		i++;
	}
}


int main(){
	int i,j,parcial,mpeso=0,mcomb,peso=15,n = 5;
	int paq[]={1,2,4,12,1};
	int cromo[n];
	int opcion= (int)pow(2,n);
	
	for(i=0;i<opcion;i++){
		parcial = 0;
		cargabin(i,n,cromo); /*convierte el decimal en bin en el arreglo*/
		for(j=0;j<n;j++)
			parcial = cromo[j]*paq[j]+parcial;
			
			if(parcial<=peso && mpeso<parcial){
				mpeso = parcial;
				mcomb = i;
			}
	}
	
	printf("%d %d",mpeso,mcomb);	
	
	return 0;
}
