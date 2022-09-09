#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Machine {
    int costo;
    int ganancia;
    int tipo;
} Machine;
int readDataFromFile(int totalMachines,Machine* machines) {
    int readMachines = totalMachines;

    FILE* file = fopen("2020-2_L1_P2_data.txt","r");
    for (int i=0;i<totalMachines;i++) {
        int assigned = fscanf(file,"%d %d %d",&machines[i].costo,&machines[i].ganancia,&machines[i].tipo);
        if (assigned<3) {
            readMachines = i;
            break;
        }        
    }
    fclose(file);

    return readMachines;
}
void fill_chromosome(int chromosome[], int n, int size){
	int i=size-1,j;
	while ( n != 0) {
		chromosome[i] = n%2;
		n /= 2;
		i--;
	}
	for (j=0; j<=i; j++)
		chromosome[j] = 0;
}
int is_valid(Machine* machines,int readmachines,int chromosome[],int budget,int typeCounter[]) {
    int i,totalCost=0,valid=1;
    for(i=0;i<readmachines;i++){
        if(chromosome[i]){
            totalCost += machines[i].costo;
            typeCounter[machines[i].tipo-1]++;
        }
    }
    for(int j=0;j<3;j++){
        if(typeCounter[j]==0) valid=0;
    }
    if(totalCost<=budget && valid) return 1;
    return 0;
}
void calcGain(int chromosome[],Machine* machines,int readmachines,int* costoTotal,int* gananciaTotal){
    *costoTotal = 0;
    *gananciaTotal = 0;
    for(int i=0;i<readmachines;i++){
        *costoTotal += machines[i].costo * chromosome[i];
        *gananciaTotal += machines[i].ganancia * chromosome[i];
    }
}
void fill_final_chromosome(int chromosome[],int final_chromosome[],int readmachines){
    for(int i=0;i<readmachines;i++){
        final_chromosome[i] = chromosome[i];
    }
}
void show_combination(int final_chromosome[],int mejorCosto,int mejorGanancia,int readmachines){
    printf("Las maquinas: ");
    for(int i=0;i<readmachines;i++){
        if(final_chromosome[i]) printf("%d ",i+1);
    }
    printf(". Costo de maquinas %d (Millones de $) y una ganancia de %d (Millones de $)",mejorCosto,mejorGanancia);
}
void minimizeLosses(int readmachines,int budget,Machine* machines){
    int totalCombinations = pow(2,readmachines);
    int chromosome[readmachines],final_chromosome[readmachines],typeCounter[3]={0,0,0};
    int costoTotal=0,gananciaTotal=0,maxgain=0;
    int mejorCosto,mejorGanancia;
    for(int i=0;i<totalCombinations;i++){
        fill_chromosome(chromosome,i,readmachines);
        if (is_valid(machines,readmachines,chromosome,budget,typeCounter)){
            calcGain(chromosome,machines,readmachines,&costoTotal,&gananciaTotal);
            if((gananciaTotal-costoTotal)>maxgain){
                maxgain = gananciaTotal - costoTotal;
                mejorCosto = costoTotal;
                mejorGanancia = gananciaTotal;
                fill_final_chromosome(chromosome,final_chromosome,readmachines);
            }
        }
    }
    show_combination(final_chromosome,mejorCosto,mejorGanancia,readmachines);
}
int main() {
    int totalMachines = 8;
    Machine* machines = (Machine*)malloc(totalMachines*sizeof(Machine));

    int readmachines= readDataFromFile(totalMachines,machines);
    printf("Se han encontrado %d maquinas",readmachines);

    int budget;
    printf(" Ingresar presupuesto: ");
    scanf("%d",&budget);

    printf("\nUna solución:");
    minimizeLosses(readmachines,budget,machines);

    free(machines);

    return 0;
}
