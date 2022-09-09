/*
 * Laboratorio 1 (2019-2), pregunta 1a  y 1b
 * Desarrollado por Johan Baldeón
 * Datos del archivo "2019-2_L1_P1_data.txt":
8 
250
1 80 150 0
2 20 80 0
3 100 300 2 1 2
4 100 150 0
5 50 80 0
6 10 50 1 2
7 50 120 1 6
8 50 150 1 6
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int N_MAX=12; 
const char *FILE_NAME = "2019-2_L1_P1_data.txt";

typedef struct ProjectData{
	int id;
	int cost;
	int gain;
	int predecessors_number;
	int *predecessors;
} TProjectData;

int read_data(int *N_ptr, int *P_ptr, TProjectData ** projects) {
	int result, i, j;
	FILE *file = fopen(FILE_NAME, "r");
  	if (file == NULL) {
	  printf("El archivo no se ha podido abrir para lectura.\n");
	  return -1;
  	}	
  	if (!feof(file)) {
	    result = fscanf(file, "%d", N_ptr);	    	    
		if (result != 1) {
			printf("No se puede leer la cantidad de proyectos.");
			return -1;
		}
		result = fscanf(file, "%d", P_ptr);
		if (result != 1) {
			printf("No se puede leer el presupuesto para los proyectos.");
			return -1;
		}		
  	}  	
  	for (i=0; i < *N_ptr; i++) {
		projects[i] = (TProjectData *) malloc(sizeof(TProjectData));;
	    result = fscanf(file, "%d %d %d %d", &projects[i]->id, &projects[i]->cost, &projects[i]->gain, &projects[i]->predecessors_number );
		if (result != 4) {
			printf("No se pueden leer los datos del proyecto.");
			return -1;
		}
		if (projects[i]->predecessors_number > 0)
			projects[i]->predecessors = (int *) malloc(sizeof(int) * projects[i]->predecessors_number);

		for (j=0; j< projects[i]->predecessors_number; j++) {
		    result = fscanf(file, "%d", &(projects[i]->predecessors[j]) );
			if (result != 1) {
				printf("No se puede leer el predecesor del proyecto.");
				return -1;
			}
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

void calc_total_profit_and_cost(TProjectData ** projects, int N, int chromosome[], int *total_profit, int *total_cost) {
	int i;
	*total_profit = 0;
	*total_cost = 0;
	for (i=0; i<N; i++){
		*total_profit += chromosome[i] * projects[i]->gain;
		*total_cost += chromosome[i] * projects[i]->cost;
	}
}

void fill_final_chromosome(int size, int chromosome[], int final_chromosome[]) {
	int i;
	for (i=0; i<size; i++){
		final_chromosome[i] = chromosome[i];
	}
}

void show_selected_projects(int size, int final_chromosome[], TProjectData **projects) {
	int i;
	printf("Los proyectos seleccionados son:\n");
	for (i=0; i<size; i++){
		if (final_chromosome[i]==1){
			printf(" - Proyecto %d, ganancia: %d, costo: %d\n",projects[i]->id, projects[i]->gain, projects[i]->cost);
		}
	}
}

int is_valid(TProjectData **projects, int size, int chromosome[], int budget) {
	int i, j, total_cost=0;

	for (i=0; i<size; i++){
		if (chromosome[i]){
			if (projects[i]->predecessors_number > 0){
				for (j=0; j< projects[i]->predecessors_number; j++){
					if (chromosome[*(projects[i]->predecessors+j) - 1] == 0)
						return 0;
				}
			} 
			total_cost += projects[i]->cost;
			if (total_cost > budget)
				return 0;			
		}
	}
	return 1;
}

int main(){
	int N, P, result, i=0, j;
	TProjectData ** projects;
	projects = (TProjectData **) malloc(sizeof(TProjectData *) * (N_MAX));
	result = read_data(&N, &P, projects);
	/* Presentación de los datos leídos del archivo */
	/*
	printf("N = %d,  P = %d\n", N, P);	
  	for (i=0; i<N; i++){
	    printf("Proyecto: %d, costo: %d, ganancia: %d, cant. de predecesores: %d", projects[i]->id, projects[i]->cost, projects[i]->gain, projects[i]->predecessors_number);
		if (projects[i]->predecessors_number > 0)
			printf("\nPredecesores: ");		
		for (j=0; j< projects[i]->predecessors_number; j++){
			printf("%d ", *(projects[i]->predecessors + j) ); 					
		}
		printf("\n\n");
	}
	*/		
	/* Fin de presentación de los datos leídos */

	int lim = pow(2,N);
	int chromosome[N];
	int final_chromosome[N];
	int total_cost = 0;
	int total_profit = 0;
	int higher_total_profit = 0;
	int final_total_cost = 0;
	for (i=0; i < lim; i++){
		fill_chromosome(i, N, chromosome);
		calc_total_profit_and_cost(projects, N, chromosome, &total_profit, &total_cost);
		if (is_valid(projects, N, chromosome, P)){
			if (total_profit > higher_total_profit){
				fill_final_chromosome(N, chromosome, final_chromosome);
				higher_total_profit = total_profit;
				final_total_cost = total_cost;
			}
		}
	}

	show_selected_projects(N, final_chromosome, projects);
	printf("\nGanancia total máxima (en millones de $): %d", higher_total_profit);
	printf("\nCosto total (en millones de $): %d\n\n", final_total_cost);

	return 0;
}