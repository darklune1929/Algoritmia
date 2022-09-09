#include <stdio.h>
int lista[10];
int y=0,x=0;

int valida(int k,int n,int prec[]){
	int i,cont=0;
	if(prec[k]==0)
		return 1;
	for(i=0;i<n;i++)	
		if(prec[k]==lista[i]) return 1;
	return 0;
}

int empaca(int i,int n,int presu,int costo[],
	int prece[],int proy[]){
	
	if(n==i || presu<0) return 0;
	if(valida(i,y,prece) && presu==costo[i]){
		int j;
		lista[y] = proy[i];
		for(j=0;j<=y;j++)
			printf("%d ",lista[j]);
		printf("\n");
		x=1;
	} 
	lista[y]=proy[i];
	y++;
	
	if(valida(i,y,prece) && 
	empaca(i+1,n,presu-costo[i],costo,prece,proy)){
				return 1;
	}

	else{
		y--;
		return empaca(i+1,n,presu,costo,prece,proy);
	}	

	
}


int main(){ 
	//Buscar los proyectos que esten dentro del costo
	//un solo predecesor 
	int proye[]={1,2,3,4,5};
	int costo[]={7,1,3,2,5};
	int prece[]={0,0,1,0,2};

	int n=5;
	int presupuesto=10;
	empaca(0,n,presupuesto,costo,prece,proye);
	if(x) printf("Hay solucion");	
	else printf("No hay solucion");
	return 0;
	
}
