/*
 * Laboratorio 2 (2021-1), pregunta 2
 * Desarrollado por Johan Baldeón
 * Datos del archivo "2021-1_L2_P2_data.txt":

36
7
6
2
1 3 4 5 6 7 1 2 1
2 3 4 5 7 1 2 6 1
3 3 4 5 2 1 6 8 0
4 3 4 5 6 2 1 9 0
5 3 4 5 7 8 9 2 1
6 3 4 5 8 9 7 6 1

*/
#include <stdio.h>
#include <stdlib.h>

int T,C, ini_budget;

const char *FILE_NAME = "2021-1_L2_P2_data.txt";

typedef struct CompanyData{
	char name;
	int stock_price;
} TCompanyData;

typedef struct DayData{
	int id;
	int companies_number;
	TCompanyData *companies;
	int tendence;
} TDayData;

int read_data(int *P_ptr, int *C_ptr, int *T_ptr, int *B_ptr, TDayData ***days_ptr) { 
	int result, i, j;
	FILE *file = fopen(FILE_NAME, "r");
  	if (file == NULL) {
	  printf("El archivo no se ha podido abrir para lectura.\n");
	  return -1;
  	}	
  	if (!feof(file)) {
	    result = fscanf(file, "%d", P_ptr);
		if (result != 1) {
			printf("No se puede leer el presupuesto P.");
			return -1;
		}
	    result = fscanf(file, "%d", C_ptr);	    	    
		if (result != 1) {
			printf("No se puede leer la cantidad C de empresas.");
			return -1;
		}		
		result = fscanf(file, "%d", T_ptr);
		if (result != 1) {
			printf("No se puede leer la cantidad T de días.");
			return -1;
		}		
		result = fscanf(file, "%d", B_ptr);
		if (result != 1) {
			printf("No se puede leer la cantidad inicial B de empresas.");
			return -1;
		}		
  	}  	
  	
  	*days_ptr = (TDayData **)malloc(sizeof(TDayData *) * (*T_ptr));
  	for (i=0; i < *T_ptr; i++) {
		(*days_ptr)[i] = (TDayData *) malloc(sizeof(TDayData));
		fscanf(file, "%d", &(*days_ptr)[i]->id);
		(*days_ptr)[i]->companies_number = *C_ptr;
		
		(*days_ptr)[i]->companies = (TCompanyData *)malloc(sizeof(TCompanyData) * (*days_ptr)[i]->companies_number);
		for (j=0; j< (*days_ptr)[i]->companies_number; j++) {
			(*days_ptr)[i]->companies[j].name = 'A' + j;		
	    	fscanf(file, "%d", &(*days_ptr)[i]->companies[j].stock_price);
	    }
	    fscanf(file, "%d", &(*days_ptr)[i]->tendence);	    
	}
	printf("Se han leído con éxito los datos.\n");	
	if (fclose(file)!=0) {
	    printf("No se ha podido cerrar el archivo.\n");
		return -1;
	} 
	return 1; 
}

int maxIndex(TCompanyData *companies, int ini, int end){
	int max, val;
	if (ini == end) return ini;
	max = ini;
	val = maxIndex(companies, ini+1, end);

	if (companies[max].stock_price < companies[val].stock_price) return val;
	else return max;
}

void desc_sort(TCompanyData *companies, int ini, int end){
	int max_index; //, aux, aux_char;
	TCompanyData aux;
	if (ini >= end) return;

	max_index = maxIndex(companies, ini, end);
	aux = companies[ini];
	aux.name = companies[ini].name;
	aux.stock_price = companies[ini].stock_price;
	companies[ini] = companies[max_index];
	companies[max_index] = aux;
	desc_sort(companies, ini+1, end);
}

int minIndex(TCompanyData *companies, int ini, int end){
	int min, val;
	if (ini == end) return ini;
	min = ini;
	val = minIndex(companies, ini+1, end);

	if (companies[min].stock_price > companies[val].stock_price) return val;
	else return min;
}

void asc_sort(TCompanyData *companies, int ini, int end){
	int min_index;
	TCompanyData aux;
	if (ini >= end) return;

	min_index = minIndex(companies, ini, end);
	aux.name = companies[ini].name;
	aux.stock_price = companies[ini].stock_price;
	companies[ini] = companies[min_index];
	companies[min_index] = aux;
	asc_sort(companies, ini+1, end);
}

void stocks_purchase(TDayData ** days, int day_number, int B, int budget){
	int total_to_buy=0;
	char tendence = days[day_number-1]->tendence ? '-' : '+';

	if (days[day_number-1]->tendence)
		desc_sort(days[day_number-1]->companies, 0, C-1);
	else
		asc_sort(days[day_number-1]->companies, 0, C-1);	

	printf("\nDía %d: ($ %c) Presupuesto = %d, ",  day_number, tendence, budget);

	for (int i=0; i<B; i++){
		total_to_buy += days[day_number-1]->companies[i].stock_price;
		if (total_to_buy > budget)
			total_to_buy -= days[day_number-1]->companies[i].stock_price;
		else 
			printf("(%c) %d, ", days[day_number-1]->companies[i].name, 
							  days[day_number-1]->companies[i].stock_price);
	}
	budget -= total_to_buy;

	if (budget <= 0 || (budget > 0 && total_to_buy == 0)){
		printf("\nSólo ha podido comprar acciones hasta el día %d, tiene %d dólares en acciones y le ha quedado %d dólar(es) de presupuesto.\n", 
				day_number-1, ini_budget - budget, budget);
		return;
	} else {
		if (days[day_number-1]->tendence) B++;
		else B--;
		stocks_purchase(days, day_number+1, B, budget);
	}
}

int main(){
	int budget, B, day_number=1, i,j;
	TDayData ** days;
	/*
	// Lectura de datos por consola
	printf("P: ");
	scanf("%d", &budget);
	printf("C: ");
	scanf("%d", &C);
	printf("T: ");
	scanf("%d", &T);
	printf("B: ");
	scanf("%d", &B);
	days = (TDayData **)malloc(sizeof(TDayData *) * T);
	for (int i=0; i<T; i++){
		days[i] = (TDayData *) malloc(sizeof(TDayData));
		days[i]->companies_number = C;
		days[i]->companies = (TCompanyData *)malloc(sizeof(TCompanyData) * days[i]->companies_number);
		printf("Día %d. Ingrese los precios de cada acción de las %d empresas: ", i+1, C);
		for (int j=0; j<C; j++){			
			scanf("%d", &days[i]->companies[j].stock_price);
			days[i]->companies[j].name = 'A' + j;
		}
		printf("Ingrese la tendencia de tipo de cambio (0: Sube, 1: Baja) para el día %d: ", i+1);
		scanf("%d", &days[i]->tendence);
	}
	*/

	//Lectura de datos mediante archivo de texto
	read_data(&budget, &C, &T, &B, &days);

	/* Presentación de los datos leídos */	
	/*
	printf("P = %d,  C = %d,  T = %d  B = %d\n", budget, C, T, B);	
  	for (i=0; i<T; i++){
	    printf("Día: %d, cant. de empresas: %d, tendencia: %d ", 
	    	days[i]->id, days[i]->companies_number, days[i]->tendence);
		for (j=0; j< days[i]->companies_number; j++){
			printf("%c-%d, ", days[i]->companies[j].name, 					
				days[i]->companies[j].stock_price); 					
		}
		printf("\n\n");
	}
	*/			
	/* Fin de presentación de los datos leídos */

	ini_budget = budget;
	stocks_purchase(days, day_number, B, budget);	
	return 0;
}