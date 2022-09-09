#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const int max=50;
const char *FILE_NAME="Datos_P2.txt";
void read_data(int *n,int almacen[][max]){
    int i,j;
    FILE *file=fopen(FILE_NAME,"r");
    fscanf(file,"%d",n);
	for(i=0;i<*n;i++)
		for(j=0;j<*n;j++)		
			fscanf(file,"%d",&almacen[i][j]);
	fclose(file);
}
int calculo_maximo(int almacen[][max],int n,int m,int mayor){
    
    return mayor;
}
int main(){
	int n,max;
	int almacen[max][max];
    read_data(&n,almacen);
    printf("%d\n",n);
    /*for(int i=0;i<n;i++){
    printf("\n");
        for(int j=0;j<n;j++)
            printf("%d ",almacen[i][j]);
    }*/
    max=calcular_maximo(almacen,n,n,0);
}