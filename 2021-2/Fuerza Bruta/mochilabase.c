#include <stdio.h>
#include <math.h>
#define MAX 5

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
	int art[]={1,15,2,10,5};
	int i,j,parcial,comb,peso = 15;
	int total=0,mcomb=0,mpeso=0,flag=0;
	int cromo[MAX];
	comb=pow(2,MAX);
	/*0 0 0 0 0
	0 0 0 0 1
	0 0 0 1 0
	0 0 0 1 1 */
	for(i=0;i<comb;i++){
		cargabin(i,cromo);
		parcial=0;

		for(j=0;j<MAX;j++)
			if(cromo[j]==1)
				parcial = parcial + art[j];
		if(parcial<=peso && mpeso<=parcial){
			mpeso=parcial;
			mcomb=i;
			if(mpeso==peso) flag=1;
		}
		if(flag) break;
	}
	cargabin(mcomb,cromo);
	for(j=0;j<MAX;j++){
		printf("%d ",cromo[j]);
	}
	printf("\n %d %d",mcomb,mpeso);
	
	return 0;
}
