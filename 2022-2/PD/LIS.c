#include <stdio.h>

int solucionalis(int lista[],int n){
	int i,j,max=0;
	int F[n];
	
	for(i=0;i<n;i++){
		F[i]=1;
		for(j=0;j<i;j++){
			if(lista[j]<lista[i] && F[j]+1>F[i])
				F[i] = F[j]+1;
		}
		if(F[i]>max) max = F[i];
	
	}
	return max;
}




int main(){
	int lista[]={-7,10,9,2,3,8,8,1};
	int n=8;
	
	int resultado=solucionalis(lista,n);
	
	printf("%d ",resultado);
	
	return 0;
}

