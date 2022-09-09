#include <stdio.h>
#define MAX 20

double max = 0;

struct Canal{
	int codigo;
	char nombre[30];
	int inversion;
	double ROAS;
	int niv_rec;
};

int calcular_maximo(struct Canal *canal,int i,double suma,int p,int n){
	int z;
	if(i==n || p<0) return 0;
	
	if(suma>max) max = suma;
	if(calcular_maximo(canal,i+1,suma+canal[i].inversion*canal[i].ROAS,p-canal[i].inversion,n)){
		
	}
	else{
		return calcular_maximo(canal,i+1,suma,p,n);
	}
}

int main(){
	FILE *arch;
	arch = fopen("2021-2_E2_P1_data.txt","r");
	
	int p,n,i,max_ing;
	fscanf(arch,"%d %d",&p,&n);
	
	struct Canal canal[MAX];
	for(i=0;i<n;i++){
		fscanf(arch,"%d",&canal[i].codigo);
		fscanf(arch,"%s",&canal[i].nombre);
		fscanf(arch,"%d",&canal[i].inversion);
		fscanf(arch,"%lf",&canal[i].ROAS);
		fscanf(arch,"%d",&canal[i].niv_rec);
	}
	
	calcular_maximo(canal,0,0,p,n);
	printf("El maximo ingreso por ventas es de %.2lf dolares.",max);
	
	return 0;
}










