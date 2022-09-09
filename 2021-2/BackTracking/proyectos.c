#include <stdio.h>
int lista[10];
int x=0,y=0;

int valida(int k,int n,int pre[],int pro[]){
	int i,cont=0;
	if(pre[k]==-1)	
		return 1;
	for(i=0;i<n;i++)
		if(pre[k]==lista[i])
			cont++;		
	if(cont)
		return 1;
	return 0;	
}

int empaca(int i,int n,int peso,int paq[],int prec[],int proy[]){

	if(i==n || peso <0)
		return 0;
	if(paq[i]==peso && valida(i,y,prec,proy) ){
		int z;
		lista[y]=proy[i];
		printf("La respuesta es:");
		for(z=0;z<=y;z++)
			printf("P%d ",lista[z]);
		printf("\n");

	}
	
	lista[y]=proy[i];
	y++;
	if( valida(i,y,prec,proy)  && empaca(i+1,n,peso-paq[i],paq,prec,proy)   ){
	//	printf("%d ",paq[i]);
		//return 1;
	}
	else{
		y--;
		return(empaca(i+1,n,peso,paq,prec,proy));
	}
	
}


int main(){
	int proye[]={0,1,2,3,4,5,6,7};
	int costo[]={7,1,3,2,4,5,1,5};
	int prece[]={-1,-1,1,-1,2,4,-1,6} ;  
	int n=8;
	int peso=10;
	
	empaca(0,n,peso,costo,prece,proye);

	
}
