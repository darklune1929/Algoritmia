#include <stdio.h>
#include <stdlib.h>




int portafolio(int n,int proy[]){
	int i,renta[n+1];
	
	renta[0]=0;
	renta[1]=proy[0];
	
	if(proy[0]<proy[1]) 
		renta[2]=proy[1];
	else
		renta[2]=proy[0];
	
	for(i=3;i<=n;i++){
		int max=renta[i-1];
		int aux=renta[i-3]+proy[i-1];
		
		if(aux>max)
			renta[i]=aux;
		else
			renta[i]=max;	
		
		
	}
	
	return renta[n];
}

int main(){
	int proy[]={3,6,1,2,4,5,18,10,13,7,15,2};
	int ganancia,n=12;
	
	ganancia=portafolio(n,proy);
	printf("La ganacia es:%d",ganancia);
	
	return 0;
}
