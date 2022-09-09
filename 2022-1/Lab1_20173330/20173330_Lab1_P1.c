#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Canal {
    int codigo;
    char nombre[31];
    double inversion_pub;
    double roas;
    int nivel_recor;
} Canal;
int readDataFromFile(int totalCanales,Canal* canales,int* P,int* N) {
    int readCanales = totalCanales;
    FILE* file = fopen("2022-1_L1_P1_data.txt","r");
    fscanf(file,"%d",P);
    fscanf(file,"%d",N);
    for (int i=0;i<totalCanales;i++) {
        int assigned = fscanf(file,"%d %s %lf %lf %d\n",&canales[i].codigo,canales[i].nombre,&canales[i].inversion_pub,
        &canales[i].roas,&canales[i].nivel_recor);
        if (assigned<5) {
            readCanales = i;
            break;
        }
    }
    fclose(file);
    return readCanales;
}
void fill_chromosome(int n, int totalCanales, int chromosome[]){
	int i=totalCanales-1,j;
	while ( n != 0) {
		chromosome[i] = n%2;
		n /= 2;
		i--;
	}
	for (j=0; j<=i; j++)
		chromosome[j] = 0;
}
int is_valid(Canal* canales,int chromosome[],int N,int P){
    double total_costo_pub = 0;
    for(int i=0;i<N;i++){
        if(chromosome[i]){
            total_costo_pub += canales[i].inversion_pub;
        }
    }
    if(total_costo_pub>P) return 0;
    return 1;
}
void calc_ingresos(Canal* canales,int chromosome[],int N,double* ingreso_actual){
    for(int i=0;i<N;i++){
        if(chromosome[i]){
            (*ingreso_actual) += (canales[i].inversion_pub*canales[i].roas);
        }
    }    
}
int main(){
    int P,N;
    Canal* canales = (Canal*)malloc(N*sizeof(Canal));
    int readCanales = readDataFromFile(N,canales,&P,&N);
    printf("Se han encontrado %d canales",readCanales);
    int lim = pow(2,N);
	int chromosome[N];
	int final_chromosome[N];
    double max_ingreso,ingreso_actual;
    //parte b
    for(int i=0;i<lim;i++){
        fill_chromosome(i,N,chromosome);
        if(is_valid(canales,chromosome,N,P)){
            ingreso_actual=0;
            calc_ingresos(canales,chromosome,N,&ingreso_actual);
            if(ingreso_actual>=max_ingreso){
                max_ingreso = ingreso_actual;
                //fill_final_chromosome(N, chromosome, final_chromosome);
            }
        }
    }
    printf("\nEl maximo ingreso por ventas es de %.2lf\n",max_ingreso);
    
}