#include <stdio.h>
#define MAX 20

int lista[MAX];
int sol[MAX];
double max = 0;
int num,y = 0;

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
	
	if(suma>max){
		for(z=0;z<y;z++) sol[z] = lista[z];
		max = suma;
		num = y;
	}
	
	lista[y] = canal[i].codigo;
	y++;
	
	if(calcular_maximo(canal,i+1,suma+canal[i].inversion*canal[i].ROAS,p-canal[i].inversion,n)){
		
	}
	else{
		y--;
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
	printf("El maximo ingreso por ventas es de %.2lf ",max);
	int tot = 0;
	for(i=0;i<num;i++)
		tot += canal[sol[i]-1].inversion;
	printf("con una inversion total en publicidad de %d.00 dolares \n\n",tot);
	printf("Los canales de publicidad que se deben elegir para obtener el maximo ingreso total son: \n");
	for(i=0;i<num;i++){
		printf("Canal %d - %s, ",sol[i],canal[sol[i]-1].nombre);
		printf("ingreso = %.2lf ",canal[sol[i]-1].inversion*canal[sol[i]-1].ROAS);
		printf("dolares con una inversion publicitaria de %d.00 dolares. \n",canal[sol[i]-1].inversion);
	}
		
	
	return 0;
}





