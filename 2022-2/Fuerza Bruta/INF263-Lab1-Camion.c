#include <stdio.h>
#include <math.h>
#define MAX 20

void cargabin(int n,int num,int cromo[])
{	
	int i,res;
	for(i=0;i<n;i++)
		cromo[i]=0;
	i=0;	
	while(num>0){
		res = num%2;
		num = num/2;
		cromo[i]=res;
		i++;
	}
}
void imprimesol(int almacen[][MAX],int n1,int n2,int n3,int n)
{ 	int i,cromo[n];
	cargabin(n,n1,cromo);
	for(i=0;i<n;i++)
		if(cromo[i])
			printf("%d ",almacen[0][i]);
	printf("\n");
	cargabin(n,n2,cromo);
	for(i=0;i<n;i++)
		if(cromo[i])
			printf("%d ",almacen[1][i]);
	printf("\n");
	cargabin(n,n3,cromo);
	for(i=0;i<n;i++)
		if(cromo[i])
			printf("%d ",almacen[2][i]);
	
}

int main(){
	int n=4;
	int almacen[][MAX]={{2,5,6,10},
					  {7,8,15,3},
					  {11,9,6,4}};
	int m=5,cont,capacidad=20;
	int cromo1[n],cromo2[n],cromo3[n];

	int peso,mcomb=pow(2,n);
	
	for(int i=0;i<mcomb;i++){
		for(int j=0;j<mcomb;j++){
			for(int k=8;k<mcomb;k++){   
				cont=0;
				peso=0;
				cargabin(n,i,cromo1);
				cargabin(n,j,cromo2);
				cargabin(n,k,cromo3);
				for(int l=0;l<n;l++)
					if(cromo1[l]==1)
					{	cont++;
						peso=peso+almacen[0][l];
					}
				for(int l=0;l<n;l++)
					if(cromo2[l]==1)
					{	cont++;
						peso=peso+almacen[1][l];
					}
				for(int l=0;l<n;l++)
					if(cromo3[l]==1)
					{	cont++;
						peso=peso+almacen[2][l];
					}
				if(peso==capacidad && cont==m){
					printf("\nSi hay solucion %d %d %d\n", i,j,k);
					imprimesol(almacen,i,j,k,n);
					break;
				}
				}
			}
		}
	return 0;	
}
