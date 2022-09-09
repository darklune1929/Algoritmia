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
	
	int paq[]={7,9,8,18,17,12,6,7,14,11,10,15,19,8,12,11};
	int n=16,peso=23,pparcial;
	int i,j,k,comb,cont;
	int cromo[n];
	comb=(int)pow(2,n);
	for(i=0;i<comb;i++){
		cargabin(i,n,cromo);
		pparcial=0;
		cont=0;
		for(j=0;j<n;j++){
			if(cromo[j]){
				pparcial = pparcial + paq[j];
				cont++;
			}
		}
		if(pparcial==peso){
			for(k=0;k<n;k++){
				if(cromo[k]){
					if(k%4==0)printf("I A %d  ",k/4+1);	
					if(k%4==1)printf("I B %d  ",k/4+1);					
					if(k%4==2)printf("D A %d  ",k/4+1);
					if(k%4==3)printf("D B %d  ",k/4+1);										
				}
			}
			printf("\n");
		}
		
	}

	return 0;
}


