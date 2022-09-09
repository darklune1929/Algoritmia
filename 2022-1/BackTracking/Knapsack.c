/*
Desarrollado por Johan Baldeón
Problema de la mochila resuelto con backtracking
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct {
	int id;
	double weight;
	double profit;	
} item;

double profit_addition(item * items, int n, double capacity, double current_weight, 
						double current_profit, int level) {
	int lvl = level;
	double result=current_profit, remaining_capacity = capacity - current_weight;
	while (lvl < n && items[lvl].weight <= remaining_capacity){
		remaining_capacity -= items[lvl].weight;
		result += items[lvl].profit;
		lvl++;
	}
	return result;
}


void knapsack_bt(item *items, int n, double capacity, int *current_knapsack, double *current_weight,
	double *current_profit, int *max_knapsack, double *max_profit, int level){
	if (level == n){
		*max_profit = *current_profit;
		memcpy(max_knapsack, current_knapsack, n * sizeof(int));
		return;
	}

	if (*current_weight + items[level].weight <= capacity){
		*current_weight += items[level].weight;
		*current_profit += items[level].profit;
		current_knapsack[items[level].id] = 1;
		knapsack_bt (items, n, capacity, current_knapsack, current_weight, current_profit, 
			max_knapsack, max_profit, level+1);
		*current_weight -= items[level].weight;
		*current_profit -= items[level].profit;
		current_knapsack[items[level].id] = 0;
	}

	double profit_add = profit_addition(items, n, capacity, *current_weight, *current_profit, level+1);

	if (profit_add > *max_profit){
		knapsack_bt(items, n, capacity, current_knapsack, current_weight, current_profit, max_knapsack,
					max_profit, level+1);
	}
}

int compare_items(item *item1, item *item2) {
    if (item1->profit / item1->weight > item2->profit/item2->weight) {
        return -1;
    }
    if (item1->profit / item1->weight < item2->profit/item2->weight) {
        return 1;
    }
    return 0;
}

int main(){
	double ids[] = {1,2,3,4,5};
	double weights[] = {5,4,3,2,1};
	double profits[] = {6,8,9,7,12};

	double capacity = 8, max_profit;
	int n = 5;

	//Colección de items
	item *items = (item *)malloc(n* sizeof(item));
	for (int i=0; i<n; i++){
		items[i].id = ids[i];
		items[i].weight = weights[i];
		items[i].profit = profits[i];
	}

	int * current_knapsack = (int *) malloc(n * sizeof(int));
	double current_weight = 0, current_profit = 0;
	int * max_knapsack = (int *) malloc(n * sizeof(int));

	qsort(items, n, sizeof(item),  (int (*)(const void *, const void *))compare_items);

	knapsack_bt(items, n, capacity, current_knapsack, &current_weight, &current_profit, 
			max_knapsack, &max_profit, 0);

	printf("El beneficio máximo es %.2lf.\n", max_profit);	

	return 0;
}