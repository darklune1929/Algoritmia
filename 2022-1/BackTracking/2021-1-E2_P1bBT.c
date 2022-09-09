/*
 * Examen 2 (2021-1), pregunta 1a 
 * Desarrollado por Johan Baldeón
 * Datos del archivo "2021-1_E2_P1_data.txt":
6 // Cantidad de ciudades
// Id ciudad, 1/0: cuenta/no cuenta con ref. esp, cant. ciudades colindantes, ciudades colindantes ...
0 0 3 1 2 5 
1 0 3 0 2 3
2 1 4 0 1 3 5
3 0 4 1 2 4 5
4 1 2 3 5
5 0 4 0 2 3 4
*/

#include <stdio.h>
#include <stdlib.h>

const char *FILE_NAME="2021-1_E2_P1_data.txt";
double vaccines[4] = {10, 5, 12, 8};

typedef struct CityData {
	int id;
	int has_cooling;
	int neighboring_cities_number;
	int *neighboring_cities;
} TCityData;


int read_data(int *N_ptr, TCityData *** cities_ptr) {
	int result, i, j;
	FILE *file = fopen(FILE_NAME, "r");
  	if (file == NULL) {
	  printf("El archivo no se ha podido abrir para lectura.\n");
	  return -1;
  	}	
  	if (!feof(file)) {
	    result = fscanf(file, "%d", N_ptr);	    	    
		if (result != 1) {
			printf("No se puede leer la cantidad de ciudades.");
			return -1;
		}
  	}  	

  	*cities_ptr = (TCityData **)malloc(sizeof(TCityData *) * (*N_ptr));
  	for (i=0; i < *N_ptr; i++) {
		(*cities_ptr)[i] = (TCityData *) malloc(sizeof(TCityData));
		fscanf(file, "%d", &(*cities_ptr)[i]->id);	    	    
		fscanf(file, "%d", &(*cities_ptr)[i]->has_cooling);	    	    
		fscanf(file, "%d", &(*cities_ptr)[i]->neighboring_cities_number);

		(*cities_ptr)[i]->neighboring_cities = (int *)malloc(sizeof(int) * 
											  (*cities_ptr)[i]->neighboring_cities_number);    
		
		for (int j=0; j<(*cities_ptr)[i]->neighboring_cities_number; j++) {
			fscanf(file, "%d", &(*cities_ptr)[i]->neighboring_cities[j]);
		}
	}	
	if (fclose(file)!=0) {
	    printf("No se ha podido cerrar el archivo.\n");
		return -1;
	} 
	return 1; 
}

/*
* Función que muestra la distribución de vacunas de acuerdo con el arreglo solution.
*/
void show_solution(int n, int solution[], TCityData * cities[]){
	int i,j;
	double total=0;
	printf("Vacuna\t");
	for (i=0; i< n; i++){
		printf("%d,C:%.0lf\t", solution[i], vaccines[solution[i]-1]);
		total += vaccines[solution[i]-1];
	}
	printf("Costo total: %.0lf\n", total);	
}

int is_valid(int solution[], int stage, TCityData *cities[]){
	for (int i=0; i<= stage; i++){
		for (int j=0; j<cities[i]->neighboring_cities_number; j++){
			if (cities[i]->neighboring_cities[j] == cities[cities[i]->neighboring_cities[j]]->id &&
				solution[i] == solution[cities[i]->neighboring_cities[j]])
				return 0;
		}
		if (solution[i] == 1 && !cities[i]->has_cooling)
			return 0;
	}
	return 1;
}

/*
* Función recursiva que, usando el algoritmo de backtracking, busca las implementaciones de cada tipo de vacuna en las ciudades.
*/
int find_solution(int n, int solution[], int stage, TCityData * cities[]) {
	int i=1;
	if (stage == n){
		show_solution(n, solution, cities);
		return 0;
	}
	do {
		solution[stage] = i;
		if (is_valid(solution, stage, cities)){
			if (find_solution(n, solution, stage+1, cities) )
				return 1;
		}
		i++;
	} while (solution[stage] !=4);
	solution[stage] = 0;
	return 0;
}

int main(){
	int n, stage=0;

	TCityData **cities;
	read_data(&n, &cities);
	int solution[n];

	for (int i =0;i<n; i++)
		solution[i] = 0;

	/* Presentación de los datos leídos del archivo */	
	printf("N = %d\n", n);	
	printf("Ciudad, cuenta con equipo especial, ciudades colindantes\n"); 
  	for (int i=0; i<n; i++){
	    printf("%d\t %d\t", cities[i]->id, cities[i]->has_cooling);
	    for (int j=0; j<cities[i]->neighboring_cities_number; j++)
	    	printf("%d ", cities[i]->neighboring_cities[j]);
		printf("\n");
	}
	/* Fin de presentación de los datos leídos */

	printf("\nLas soluciones de distribución son:\nCiudad\t");
	for (int i=0; i< n; i++){
		printf("%d\t", i);
	}
	printf("\n");
	for (int i=0; i<=n*8; i++)
		printf("-");
	printf("\n");
	find_solution(n, solution, stage, cities);

	return 0;
}
