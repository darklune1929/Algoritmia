/*
 * Laboratorio 1 (2020-1), pregunta 2
 * Desarrollado por Johan Baldeón
 * Datos del archivo "2020-1_L1_P2_data.txt":
6
24
1 1 7 5
2 2 8 3
3 2 9 2
4 3 12 2
5 1 7 4
6 3 11 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define MAX 40
//int arrSalariesPerHour[] = {16, 19, 22};

const int N_MAX=12; 
const char *FILE_NAME = "2020-1_L1_P2_data.txt";

typedef struct WorkerData{
	int id;
	int role_id;
	int reposition_speed;
	int salary_per_hour;
	int bonus_per_brand;
} TWorkerData;

int read_data(int *t_ptr, int *mpxh_ptr, TWorkerData ** workers) {
	int result, i, j;
	FILE *file = fopen(FILE_NAME, "r");
  	if (file == NULL) {
	  printf("El archivo no se ha podido abrir para lectura.\n");
	  return -1;
  	}	
  	if (!feof(file)) {
	    result = fscanf(file, "%d", t_ptr);	    	    
		if (result != 1) {
			printf("No se puede leer la cantidad de postulantes.");
			return -1;
		}
	    result = fscanf(file, "%d", mpxh_ptr);	    	    
		if (result != 1) {
			printf("No se puede leer la meta de marcas a reponer por hora.");
			return -1;
		}
  	}  	
  	for (i=0; i < *t_ptr; i++) {
		workers[i] = (TWorkerData *) malloc(sizeof(TWorkerData));;
	    result = fscanf(file, "%d %d %d %d", &workers[i]->id, &workers[i]->role_id, 
	    				&workers[i]->reposition_speed, &workers[i]->bonus_per_brand );
	    switch(workers[i]->role_id){
	    	case 1:
	    		workers[i]->salary_per_hour = 16;
	    		break;
	    	case 2:
	    		workers[i]->salary_per_hour = 19;
	    		break;
	    	case 3:
	    		workers[i]->salary_per_hour = 22;
	    		break;
	    }
		if (result != 4) {
			printf("No se pueden leer los datos del postulante.");
			return -1;
		}
	}	
	if (fclose(file)!=0) {
	    printf("No se ha podido cerrar el archivo.\n");
		return -1;
	} 
	return 1; 
}

int main(){
	//Declaracion de variables:
	int t, MPxH, i, j, result;
	int aux[MAX],rpta[MAX];
	TWorkerData ** workers;
	workers = (TWorkerData **) malloc(sizeof(TWorkerData *) * MAX);	
	//Lectura:
	result = read_data(&t, &MPxH, workers);

	//Algoritmo
	/* El costo mínimo inicial será la suma de todos los costos si se aceptan a todos los postulantes	
	*/
	int min_cost=0;
	for (int i=0; i<t; i++){
		min_cost += workers[i]->salary_per_hour + 
					workers[i]->reposition_speed * workers[i]->bonus_per_brand;
	}
	int max_goal=0;

	//Vamos a trabajar con las pow(2,m) posibilidades 
	int lim = 1<<t;
	for(int i = 0; i < lim; i++){		
		//Limpiamos el arreglo
		memset(aux,0,sizeof(aux));		
		int cost = 0, goal = 0;
		for(int j=0; j<t; j++){
			int bin = (1<<j) & i;
			if(bin!=0){
				//Hemos seleccionado un elemento:
				aux[j] = 1;
				cost += workers[j]->salary_per_hour + 
						workers[j]->reposition_speed * workers[j]->bonus_per_brand;
				goal += workers[j]->reposition_speed;
			} 
		}
		if (goal>=MPxH){
			//En este caso es posible que sea respuesta!
			if ( (cost < min_cost) || (cost == min_cost && goal > max_goal) ){
				//Guardamos la respuesta
				for(int j =0; j<t; j++){
					rpta[j] = aux[j];
				}
				min_cost = cost;
				max_goal = goal;
			}
		}
	}
	printf("Los trabajadores seleccionados son: ");
	for(int i =0;i < t; i++){
		if(rpta[i]==1){
			printf("%d ",i+1);
		}
	}
	printf("\tEl costo mínimo total es %d\n", min_cost);
	return 0;
}