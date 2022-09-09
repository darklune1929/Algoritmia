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
	int i,j,parcial,pvalor,mvalor=0,mcomb,peso=25,n = 6;
	int paq[]={8,2,10,10,5,5};
	int valor[]={15,20,5,10,8,5};
	int cromo[n];
	int opcion= (int)pow(2,n);
	
	for(i=0;i<opcion;i++){
		parcial = 0;
		pvalor = 0;
		cargabin(i,n,cromo); /*convierte el decimal en bin en el arreglo*/
		for(j=0;j<n;j++){
			parcial = cromo[j]*paq[j]+parcial;
			pvalor = cromo[j]*valor[j]+pvalor;
			
		}
		if(parcial<=peso && mvalor<pvalor){
			mvalor = pvalor;
			mcomb = i;
		}
	}
	
	printf("%d %d",mvalor,mcomb);	
	
	return 0;
}
