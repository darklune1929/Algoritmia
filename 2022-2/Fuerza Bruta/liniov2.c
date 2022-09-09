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
	int matriz[][4]={{100,4,8,2},
					{101,2,10,2},
					{102,3,12,2},
					{103,1,13,2},
					{104,3,15,1},
					{105,1,10,2},
					{106,4,16,1},
					{107,2,8,2},
					{108,3,14,1},
					{109,2,18,2},
					{110,1,8,2},
					{111,4,14,2}};
					
	int i,j,k,comb,n=12,cruce;
	int cromo[n],horario[24];
	int p1,p2,p3,p4;
	
	comb=(int)pow(2,n);
	for(i=0;i<comb;i++){
		cargabin(i,n,cromo);
		for(k=0;k<24;k++) horario[k]=0;	
		p1=p2=p3=p4=0;
		cruce=0;
		for(j=0;j<n;j++){
			if(cromo[j]){

			switch(matriz[j][1]){
				case 1: p1++;break;
				case 2: p2++;break;
				case 3: p3++;break;
				case 4: p4++;
			}
			for(k=matriz[j][2];
				k<matriz[j][2]+matriz[j][3];k++){
				
				if(horario[k]==0)
					horario[k]=1;
				else{
					cruce=1;
					break;
					}		
				}
			}		
		}
		if(p1>=2 && p2>=2 && p3>=1 
			&& p4>=1 && cruce==0){
			for(j=0;j<n;j++)
				if(cromo[j])
					printf("\n%d %d",matriz[j][0],matriz[j][1]);
				
			printf("\n");
		}
	}
					
					
					
	return 0;	
}
