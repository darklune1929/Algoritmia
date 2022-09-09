/*
 * Laboratorio 1 (2021-1), pregunta 2a y 2b
 * Desarrollado por Johan Baldeón
 * Datos del archivo "2021-1_L1_P2_data.txt":
4
5
20
1 2 5 6 10
2 7 8 15 3
3 11 9 6 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int BAY_NUM=3; 
const char *FILE_NAME = "2021-1_L1_P2_data.txt";

typedef struct BayData{
	int id;
	int products_number;
	int *weights;
} TBayData;

int read_data(int *N_ptr, int *M_ptr, int *C_ptr, TBayData **bays_ptr) { 
	int result, i, j;
	FILE *file = fopen(FILE_NAME, "r");
  	if (file == NULL) {
	  printf("El archivo no se ha podido abrir para lectura.\n");
	  return -1;
  	}	
  	if (!feof(file)) {
	    result = fscanf(file, "%d", N_ptr);
		if (result != 1) {
			printf("No se puede leer la cantidad N de productos por bahía.");
			return -1;
		}
	    result = fscanf(file, "%d", M_ptr);	    	    
		if (result != 1) {
			printf("No se puede leer la cantidad total M de productos.");
			return -1;
		}		
		result = fscanf(file, "%d", C_ptr);
		if (result != 1) {
			printf("No se puede leer el límite C de toneladas.");
			return -1;
		}		
  	}  	
  	for (i=0; i < BAY_NUM; i++) {
		bays_ptr[i] = (TBayData *) malloc(sizeof(TBayData));
		fscanf(file, "%d", &bays_ptr[i]->id);
		bays_ptr[i]->products_number = *N_ptr;
		bays_ptr[i]->weights = (int *)malloc(sizeof(int) * bays_ptr[i]->products_number);
		for (j=0; j< *N_ptr; j++)			
	    	fscanf(file, "%d", &bays_ptr[i]->weights[j]);
	}	
	if (fclose(file)!=0) {
	    printf("No se ha podido cerrar el archivo.\n");
		return -1;
	} 
	return 1; 
}

void show_selected_products(TBayData ** bays, int N, int chromosome[]){
	int i, j, prev_index = 0;
	printf("Los pesos de los productos seleccionados son: \n");
	for (i=0; i< BAY_NUM; i++){
		printf("Bahía %d: ", i+1);
		for (j=prev_index; j< prev_index + bays[i]->products_number; j++){
			if (chromosome[j] == 1)
				printf("%d ", bays[i]->weights[j%N]);
		}
		prev_index += N;
		printf("\n");
	}
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

int is_valid(TBayData **bays, int n, int N, int M, int C, int chromosome[]){
	int i, total_weight=0, div_cont=0;
	for (i=0; i<n; i++){
		if (chromosome[i]){
			div_cont++;
			if (div_cont > M)
				return 0;
			total_weight += bays[i/N]->weights[i%N];
		}
	}
	if (total_weight == C && div_cont == M)
		return 1;
	else 
		return 0;
}

int main(){
	int N, M, C, result, i=0, j, n=0, valid_count=0;	
	//TBayData ** bays;
	//bays = (TBayData **) malloc(sizeof(TBayData *) * BAY_NUM);
	TBayData *bays[BAY_NUM];
	
	result = read_data(&N, &M, &C, bays);
	/* Presentación de los datos leídos del archivo */	

	if (result == 1) {
		printf("N = %d, M = %d, C = %d\n", N, M, C);	
	  	for (i=0; i<BAY_NUM; i++){
		    printf("Bahía: %d, Pesos: ", bays[i]->id);
		    for (j=0; j<N; j++){	    	
		    	printf("%d ", bays[i]->weights[j]);
		    }
		    printf("\n");
		}
		/* Fin de presentación de los datos leídos */

		n = BAY_NUM * N;
		unsigned long long lim = pow(2, n);
		int chromosome[n];  // 	[0,1,0,1,
						    //   0,0,1,0,
							//	 1,0,0,0]

		for (i=0; i < lim; i++){
			fill_chromosome(i, n, chromosome);
			if (is_valid(bays, n, N, M, C, chromosome)){
				valid_count++;
				show_selected_products(bays, N, chromosome);
				//break;
			}
		}
		if (valid_count == 0)
			printf("No hay respuestas válidas.\n");
	} else {
		printf("Los datos no se han logrado leer.\n");
		exit(1);
	}	
	return 0;
}