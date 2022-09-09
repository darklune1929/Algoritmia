#include <stdio.h>
#include <stdlib.h>

typedef struct RobotData{
	char name;
	int price;
} TRobotData;

typedef struct RegionData{
	char region[20];
	double percentage; 
	int robots_number;	
	TRobotData *robots;
	int choose_economic;
	int robots_num_to_choose;
} TRegionData;

int read_data(int *P_ptr, int *NR_ptr, int *NM_ptr, TRegionData ***region_ptr) { 
	int i, j;
	FILE *file = fopen("2022-1_L2_P2_data.txt", "r");
  	if (file == NULL) {
	  printf("El archivo no se ha podido abrir para lectura.\n");
	  return -1;
  	}	
  	if (!feof(file)) {
	    fscanf(file, "%d", P_ptr);
	    fscanf(file, "%d", NR_ptr);
		fscanf(file, "%d", NM_ptr);
  	}  	
  	*region_ptr = (TRegionData **)malloc(sizeof(TRegionData *) * (*NR_ptr));
  	for (i=0; i < *NR_ptr; i++) {
		(*region_ptr)[i] = (TRegionData *) malloc(sizeof(TRegionData));
		fscanf(file, "%s", &(*region_ptr)[i]->region);
		fscanf(file, "%lf", &(*region_ptr)[i]->percentage);
		(*region_ptr)[i]->robots_number = *NM_ptr;
		(*region_ptr)[i]->robots = (TRobotData *)malloc(sizeof(TRegionData) * (*region_ptr)[i]->robots_number);
		for (j=0; j< (*region_ptr)[i]->robots_number; j++) {
			(*region_ptr)[i]->robots[j].name = 'A' + j;		
	    	fscanf(file, "%d", &(*region_ptr)[i]->robots[j].price);
	    }
	    fscanf(file, "%d", &(*region_ptr)[i]->choose_economic);	    
	    fscanf(file, "%d", &(*region_ptr)[i]->robots_num_to_choose);	    
	}
	if (fclose(file)!=0) {
	    printf("No se ha podido cerrar el archivo.\n");
		return -1;
	} 
	return 1; 
}

int maxIndex(TRobotData *robots, int ini, int end){
	int max, val;
	if (ini == end) return ini;
	max = ini;
	val = maxIndex(robots, ini+1, end);

	if (robots[max].price < robots[val].price) return val;
	else return max;
}

void desc_sort(TRobotData *robots, int ini, int end){
	int max_index;
	TRobotData aux;
	if (ini >= end) return;

	max_index = maxIndex(robots, ini, end);
	aux = robots[ini];
	aux.name = robots[ini].name;
	aux.price = robots[ini].price;
	robots[ini] = robots[max_index];
	robots[max_index] = aux;
	desc_sort(robots, ini+1, end);
}

int minIndex(TRobotData *robots, int ini, int end){
	int min, val;
	if (ini == end) return ini;
	min = ini;
	val = minIndex(robots, ini+1, end);

	if (robots[min].price > robots[val].price) return val;
	else return min;
}

void asc_sort(TRobotData *robots, int ini, int end){
	int min_index;
	if (ini >= end) return;

	min_index = minIndex(robots, ini, end);
	TRobotData aux;
	aux.name = robots[ini].name;
	aux.price = robots[ini].price;
	robots[ini] = robots[min_index];
	robots[min_index] = aux;
	asc_sort(robots, ini+1, end);
}

int calc_and_show_selected_robots(TRobotData *robots, double budget, 
						int robots_num_to_choose, int robot_number, int robot_index,
						int total_cost){
    //pare en caso el numero de robot exceda a la cantidad de robots permitidos	
	if (robots_num_to_choose < robot_number) 
		return total_cost;	
	total_cost += robots[robot_index].price;
    // pare en caso el costo total exceda el budget en tal caso le resta lo del robot actual que hizo 
    //que se pase del presupuesto
	if (total_cost > budget) {
		total_cost -= robots[robot_index].price;
	} else  {
		printf("%c, ", robots[robot_index].name);
		robot_number++;
	}
    //aumenta indice del robot que se quiere sumar al costo	
	total_cost = calc_and_show_selected_robots(robots, budget,
						robots_num_to_choose, robot_number, robot_index+1, 
						total_cost); 
	return total_cost;
}

void calc_costs(TRegionData **regiones, int region_num, int NR, int NM, int ini_budget, int savings) {
	int robot_number=1;
	double budget; 
	int total_cost=0;
    //si el numero de region excede al numero de regiones acaba el bucle e imprime el costo
    // total invertido y cuanto se ahorro
	if (region_num > NR) {
		printf("El costo real de la distribucion es de USD %d con un ahorro de USD %d\n", ini_budget-savings, savings);
		return;
	}
    // se calcula el presupuesto actual multiplicando el total inicial por el porcentaje asignado a la region
    // ademas de sumar cuanto se ahorro de la region anterior
	budget = ini_budget * regiones[region_num-1]->percentage/100 + savings;
    // se ordena de los robots por cada region de forma ascendente o descendete dependiendo de la opcion economica
    // asi poder sumarlos más facilmente al momento de calcular los costos
	if (regiones[region_num-1]->choose_economic) 
		asc_sort(regiones[region_num-1]->robots, 0, NM-1);			
	else
		desc_sort(regiones[region_num-1]->robots, 0, NM-1);
    // se calcula el costo total de una region dependiendo del presupuesto y cuantos robots se pueden usar en esa region
	printf("Region %s - Monto destinado: %.0lf - Robots a distribuir: ",  
		regiones[region_num-1]->region, ini_budget * regiones[region_num-1]->percentage/100);
	total_cost = calc_and_show_selected_robots(regiones[region_num-1]->robots, budget, 
			regiones[region_num-1]->robots_num_to_choose, robot_number, 0, total_cost);
	// funcion que te devuelve en caso ya no tengas presupuesto o que ya no sea necesario gastar más
	if (budget <= 0 || (budget > 0 && total_cost == 0)){
		return;
	} else {
		savings = budget - total_cost;
		printf(" Costo real: %d - Ahorro hasta la region: %d\n", total_cost, savings);
        // se avanza a la siguiente region
		calc_costs(regiones, region_num+1, NR, NM, ini_budget, savings);		
	}
}

int main(){
	int budget, NR, NM, ini_budget, region_num=1,savings=0;
	TRegionData ** regiones;
	//Lectura de datos mediante archivo de texto
	read_data(&budget, &NR, &NM, &regiones);
	ini_budget = budget;
    //funcion principal recursiva para la optimizacion de la seleccion
	calc_costs(regiones, region_num, NR, NM, ini_budget, savings);
	return 0;
}