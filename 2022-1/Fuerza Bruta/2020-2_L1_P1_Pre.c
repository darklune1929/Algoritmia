/*
 * Laboratorio 1 (2020-2), pregunta 1a y 1b
 * Desarrollado por Johan Baldeón
 * Datos del archivo "2020-2_L1_P1_data.txt":
7
4
20
1 1 10
2 5 5 
3 1 5
4 10 3
5 5 2
6 6 1
7 2 8
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

const int N_MAX=12; 
const char *FILE_NAME = "2020-2_L1_P1_data.txt";

typedef struct WorkerData{
	int id;
	int avg_break;
	int salary;
} TWorkerData;

int read_data(int *N_ptr, int *M_ptr, int *P_ptr, TWorkerData ** workers) {
	int result, i, j;
	FILE *file = fopen(FILE_NAME, "r");
  	if (file == NULL) {
	  printf("El archivo no se ha podido abrir para lectura.\n");
	  return -1;
  	}	
  	if (!feof(file)) {
	    result = fscanf(file, "%d", N_ptr);	    	    
		if (result != 1) {
			printf("No se puede leer la cantidad máxima de obreros.");
			return -1;
		}
	    result = fscanf(file, "%d", M_ptr);	    	    
		if (result != 1) {
			printf("No se puede leer la cantidad mínima de obreros.");
			return -1;
		}		
		result = fscanf(file, "%d", P_ptr);
		if (result != 1) {
			printf("No se puede leer el presupuesto para todos los obreros.");
			return -1;
		}		
  	}  	
  	for (i=0; i < *N_ptr; i++) {
		workers[i] = (TWorkerData *) malloc(sizeof(TWorkerData));;
	    result = fscanf(file, "%d %d %d", &workers[i]->id, &workers[i]->avg_break, &workers[i]->salary );
		if (result != 3) {
			printf("No se pueden leer los datos del obrero.");
			return -1;
		}
	}	
	if (fclose(file)!=0) {
	    printf("No se ha podido cerrar el archivo.\n");
		return -1;
	} 
	return 1; 
}

void fill_chromosome(int n, int size, int chromosome[]){
	int i=size-1,j;
	while ( n != 0) {
		chromosome[i] = n%2;
		n /= 2;
		i--;
	}
	for (j=0; j<=i; j++)
		chromosome[j] = 0;
}

void fill_final_chromosome(int size, int chromosome[], int final_chromosome[]) {
	int i;
	for (i=0; i<size; i++){
		final_chromosome[i] = chromosome[i];
	}
}

void calc_total_avg_break_and_salary(TWorkerData ** workers, int size, int chromosome[], double *total_avg_break, int *total_salary) {
	//Completar
}

void show_selected_workers(int size, int final_chromosome[], TWorkerData **workers) {
	//Completar
}

int is_valid(TWorkerData **workers, int size, int workers_min_num, int chromosome[], int budget) {
	//Completar
}

int main(){
	int N, M, P, result, i=0, j;
	TWorkerData ** workers;
	workers = (TWorkerData **) malloc(sizeof(TWorkerData *) * (N_MAX));
	result = read_data(&N, &M, &P, workers);
	/* Presentación de los datos leídos del archivo */
	/*
	printf("N = %d, M = %d, P = %d\n", N, M, P);	
  	for (i=0; i<N; i++){
	    printf("Obrero: %d, rotura promedio: %d, salario: %d", 
	    	workers[i]->id, workers[i]->avg_break, workers[i]->salary);
		printf("\n");
	}
	*/		
	/* Fin de presentación de los datos leídos */

	
	return 0;
}