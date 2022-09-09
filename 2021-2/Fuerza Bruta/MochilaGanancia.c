#include <stdio.h>
#include <math.h>
#define MAX 10
/*Codigo desarrollado por el prof Cueva en clase*/
void cargabin(int num,int cromo[]){
	int i=0,j,res;
	
	for(j=0;j<MAX;j++) cromo[j]=0;
	while(num>0){
		res=num%2;
		num=num/2;
		cromo[i]=res;			
		i++;
	}
	 
}


int main(){
	int art[][2]={{8,15},{2,20},{10,5},{10,10},{5,8},{5,5}};
	int i,j,parcial,comb,peso = 25, n=6;
	int total=0,mcomb=0,mpeso=0,mvalor=0,valor,flag=0;
	int cromo[MAX];
	comb=pow(2,n);
	/*0 0 0 0 0
	0 0 0 0 1
	0 0 0 1 0
	0 0 0 1 1 */
	for(i=0;i<comb;i++){
		cargabin(i,cromo);
		parcial=0;
		valor = 0;
		for(j=0;j<MAX;j++)
			if(cromo[j]==1){
				parcial = parcial + art[j][0];
				valor = valor + art[j][1];
			}

		if(parcial<=peso && mvalor<valor){
			mvalor=valor;
			mcomb=i;
			mpeso=parcial;
		}
	}
	cargabin(mcomb,cromo);
	for(j=0;j<n;j++){
		printf("%d ",cromo[j]);
	}
	printf("\n %d %d %d",mcomb,mvalor,mpeso);
	
	return 0;
}
