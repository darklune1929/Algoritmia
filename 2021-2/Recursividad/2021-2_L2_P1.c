/*
 * Laboratorio 2 (2021-2), pregunta 1
 * Desarrollado por Johan Baldeón
 * Datos del archivo "2021-2_L2_P1_data.txt":

200000
7
7
1 5 5100 4100 4000 5000 3000 3500 2800 1 3
2 10 4400 4000 4100 3800 4500 4200 4300 1 4
3 15 29000 31000 32000 30000 33000 35000 34000 0 1
4 45 90500 90000 91000 93000 89000 85000 92000 0 1
5 10 6800 7000 6000 6500 6800 6900 6700 1 3
6 5 10500 10000 9000 9500 11000 10800 8500 0 1
7 10 10000 9000 11000 12000 9500 10500 11500 1 2

*/
#include <stdio.h>
#include <stdlib.h>

const char *FILE_NAME = "2021-2_L2_P1_data.txt";

typedef struct ConsultantData{
	char name;
	int price;
} TConsultantData;

typedef struct PhaseData{
	int id;
	double percentage; 
	int consultants_number;	
	TConsultantData *consultants;
	int choose_economic;
	int consultants_num_to_choose;
} TPhaseData;

int read_data(int *P_ptr, int *NF_ptr, int *N_ptr, TPhaseData ***phases_ptr) { 
	int result, i, j;
	FILE *file = fopen(FILE_NAME, "r");
  	if (file == NULL) {
	  printf("El archivo no se ha podido abrir para lectura.\n");
	  return -1;
  	}	
  	if (!feof(file)) {
	    fscanf(file, "%d", P_ptr);
	    fscanf(file, "%d", NF_ptr);
		fscanf(file, "%d", N_ptr);
  	}  	
  	
  	*phases_ptr = (TPhaseData **)malloc(sizeof(TPhaseData *) * (*NF_ptr));
  	for (i=0; i < *NF_ptr; i++) {
		(*phases_ptr)[i] = (TPhaseData *) malloc(sizeof(TPhaseData));
		fscanf(file, "%d", &(*phases_ptr)[i]->id);
		fscanf(file, "%lf", &(*phases_ptr)[i]->percentage);
		(*phases_ptr)[i]->consultants_number = *N_ptr;
		
		(*phases_ptr)[i]->consultants = (TConsultantData *)malloc(sizeof(TConsultantData) * (*phases_ptr)[i]->consultants_number);
		for (j=0; j< (*phases_ptr)[i]->consultants_number; j++) {
			(*phases_ptr)[i]->consultants[j].name = 'A' + j;		
	    	fscanf(file, "%d", &(*phases_ptr)[i]->consultants[j].price);
	    }
	    fscanf(file, "%d", &(*phases_ptr)[i]->choose_economic);	    
	    fscanf(file, "%d", &(*phases_ptr)[i]->consultants_num_to_choose);	    
	}
	if (fclose(file)!=0) {
	    printf("No se ha podido cerrar el archivo.\n");
		return -1;
	} 
	return 1; 
}

int maxIndex(TConsultantData *consultants, int ini, int end){
	int max, val;
	if (ini == end) return ini;
	max = ini;
	val = maxIndex(consultants, ini+1, end);

	if (consultants[max].price < consultants[val].price) return val;
	else return max;
}

void desc_sort(TConsultantData *consultants, int ini, int end){
	int max_index;
	TConsultantData aux;
	if (ini >= end) return;

	max_index = maxIndex(consultants, ini, end);
	aux = consultants[ini];
	aux.name = consultants[ini].name;
	aux.price = consultants[ini].price;
	consultants[ini] = consultants[max_index];
	consultants[max_index] = aux;
	desc_sort(consultants, ini+1, end);
}

int minIndex(TConsultantData *consultants, int ini, int end){
	int min, val;
	if (ini == end) return ini;
	min = ini;
	val = minIndex(consultants, ini+1, end);

	if (consultants[min].price > consultants[val].price) return val;
	else return min;
}

void asc_sort(TConsultantData *consultants, int ini, int end){
	int min_index;
	if (ini >= end) return;

	min_index = minIndex(consultants, ini, end);
	TConsultantData aux;
	aux.name = consultants[ini].name;
	aux.price = consultants[ini].price;
	consultants[ini] = consultants[min_index];
	consultants[min_index] = aux;
	asc_sort(consultants, ini+1, end);
}

int calc_and_show_selected_consultants(TConsultantData *consultants, double budget, 
						int consultants_num_to_choose, int consultant_number, int consultant_index,
						int total_cost,	int choose_economic){		
	if (consultants_num_to_choose < consultant_number) 
		return total_cost;	
	total_cost += consultants[consultant_index].price;
	if (total_cost > budget) {
		total_cost -= consultants[consultant_index].price;
	} else  {
		printf("%c, ", consultants[consultant_index].name);
		consultant_number++;
	}		
	total_cost = calc_and_show_selected_consultants(consultants, budget,
						consultants_num_to_choose, consultant_number, consultant_index+1, 
						total_cost, choose_economic); 
	return total_cost;
}

void calc_costs(TPhaseData **phases, int phase_number, int NF, int N, int ini_budget, int total_cost, int savings) {
	int consultant_number=1;
	double budget; 
	total_cost=0; 	
	if (phase_number > NF) {
		printf("El costo real del proyecto es de USD %d con un ahorro de USD %d\n", ini_budget-savings, savings);
		return;
	}
	budget = ini_budget * phases[phase_number-1]->percentage/100 + savings;	
	if (phases[phase_number-1]->choose_economic) 
		asc_sort(phases[phase_number-1]->consultants, 0, N-1);			
	else
		desc_sort(phases[phase_number-1]->consultants, 0, N-1);
	
	printf("Fase %d - Monto destinado: %.0lf - Consultoras: ",  
		phase_number, ini_budget * phases[phase_number-1]->percentage/100);
	total_cost = calc_and_show_selected_consultants(phases[phase_number-1]->consultants, budget, 
			phases[phase_number-1]->consultants_num_to_choose, consultant_number, 0, total_cost, 
			phases[phase_number-1]->choose_economic);
	
	if (budget <= 0 || (budget > 0 && total_cost == 0)){
		return;
	} else {
		savings = budget - total_cost;
		printf(" Costo real: %d - Ahorro hasta la fase: %d\n", total_cost, savings);
		calc_costs(phases, phase_number+1, NF, N, ini_budget, total_cost, savings);		
	}
}

int main(){
	int budget, NF, N, ini_budget, phase_number=1, i,j, total_cost=0, savings=0;
	TPhaseData ** phases;

	//Lectura de datos mediante archivo de texto
	read_data(&budget, &NF, &N, &phases);

	/* Presentación de los datos leídos */	
	/*
	printf("P = %d,  NF = %d,  N = %d \n", budget, NF, N);	
  	for (i=0; i<NF; i++){
	    printf("Fase: %d, Porc. a invertir: %.2lf, cant. de consultoras: %d, elige econ.: %d, cant. a elegir: %d\n",	     			
	    	phases[i]->id, phases[i]->percentage, phases[i]->consultants_number, 
	    	phases[i]->choose_economic, phases[i]->consultants_num_to_choose);
		for (j=0; j< phases[i]->consultants_number; j++){
			printf("%c-%d, ", phases[i]->consultants[j].name, 					
				phases[i]->consultants[j].price); 					
		}
		printf("\n\n");
	}
	*/
	/* Fin de presentación de los datos leídos */

	ini_budget = budget;
	calc_costs(phases, phase_number, NF, N, ini_budget, total_cost, savings);	
	return 0;
}