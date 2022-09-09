
#include <stdio.h>
#include <math.h>

void cargabin(int num,int n,int cromo[]){
	int i,res;
	for(i=0;i<n;i++)cromo[i]=0; /*1 0 1 0 0*/
	i=0;
	while(num>0){
		res=num%2;
		num=num/2;
		cromo[i]=res;
		i++;	
	}

}


int main(){
	int paq[][2]={{8,15},{2,20},{10,5},{10,10},{5,8},{5,5}};
	int i,j,n=6,parcial,mpeso=0,mcomb,peso=25; 
	int valor,mvalor=0;
	int opcion=(int)pow(2,n);
	int cromo[n];
	
	for(i=0;i<opcion;i++){
		parcial=0;
		valor=0;
		cargabin(i,n,cromo);/*Toma i y lo vuelve binario en cromo*/
		for(j=0;j<n;j++){
			parcial=parcial+paq[j][0]*cromo[j];
			valor  =valor  +paq[j][1]*cromo[j];
		}
		if(parcial<=peso && valor > mvalor ){
			mvalor = valor;
			mcomb=i;
		}
	}
	cargabin(mcomb,n,cromo);
	for(j=0;j<n;j++){
		if(cromo[j]==1)
			printf("%d ",j+1);
		
	}
	printf("\nCombinacion:%d Valor:%d",mcomb,mvalor);
	
	return 0;
}


