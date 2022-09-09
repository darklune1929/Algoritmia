/*
 * Laboratorio 3, pregunta 1
 * Desarrollado por Johan Baldeón
 *
 * Datos de prueba:
 * Cantidad de empresas (C): 7
 * Cantidad de días (T): 6
 * Índice Bursátil meta (IBm): 4.2
 * Precios de cada acción [A - G] por día:
 * Día 1: 8 4 5 6 7 1 2
 * Día 2: 3 4 5 7 1 2 6
 * Día 3: 5 6 5 2 1 6 8
 * Día 4: 3 4 5 6 2 1 9
 * Día 5: 3 4 5 4 5 3 2
 * Día 6: 3 4 4 8 9 7 6
 * 
 * Salida:
 * Día 1, IBd: 4.714, Decisión: Vende, Monto: 26.00, Empresas: C D E A 
 * Día 2, IBd: 4.000, Decisión: Compra, Monto: 10.00, Empresas: E F A B 
 * Día 3, IBd: 4.714, Decisión: Vende, Monto: 30.00, Empresas: C A F B G 
 * Día 4, IBd: 4.286, Decisión: Vende, Monto: 20.00, Empresas: C D G 
 * Día 5, IBd: 3.714, Decisión: Compra, Monto: 8.00, Empresas: G F A 
 * Día 6, IBd: 5.857, Decisión: Vende, Monto: 30.00, Empresas: G F D E 
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

double ibm;
int companies_count;

double calculate_ibd (double * prices, int ini){
	double ibd = prices[ini] / companies_count;
	if (ini == companies_count-1) return ibd;	
	return ibd + calculate_ibd(prices, ini+1);
}

void merge(double * prices, char * companies, int ini, int mid, int end){
	int i, p=0, q=0;
	int l1 = mid - ini + 1;
	int l2 = end - mid;

	double left_array[l1+1];
	char c_left_array[l1];
	double right_array[l2+1];
	char c_right_array[l2];

	for (i = ini; i <= mid; i++){
		left_array[i - ini] = prices[i];
		c_left_array[i-ini] = companies[i];
	}
	left_array[l1] = INT_MAX;

	for (i = mid+1; i<= end; i++){
		right_array[i-mid-1] = prices[i];
		c_right_array[i-mid-1] = companies[i];
	}
	right_array[l2] = INT_MAX;

	for (i=ini; i <= end; i++)
		if (left_array[p] < right_array[q]){
			prices[i] = left_array[p];
			companies[i] = c_left_array[p++];
		}
		else {
			prices[i] = right_array[q];
			companies[i] = c_right_array[q++];
		}
}

void merge_sort_for_prices_and_companies(double * prices, char * companies, int ini, int end){
    if(ini == end) return;
    int mid = (ini + end)/2;
    merge_sort_for_prices_and_companies(prices, companies, ini, mid);
    merge_sort_for_prices_and_companies(prices, companies, mid+1, end);
    merge(prices, companies, ini, mid, end);	
}

double add_range(double * prices, int ini, int end) {	
	double sum = prices[ini];
	if (ini == end) return sum;
	return sum + add_range(prices, ini+1, end);
}

void show_companies(char * companies, int ini, int end) {
	printf("%c ", companies[ini]);
	if (ini == end) return;
	show_companies(companies, ini+1, end);
}

int pos_bin_search(double * prices, int l, int r, double ibd, char action){
    if (r >= l) {
        int mid = l + (r - l) / 2; 
        if (action == 'C' && (prices[mid] < ibd || fabs(prices[mid] - ibd) <= 0.0001 ) && prices[mid+1] > ibd)
            return mid;
        if (action == 'V' && prices[mid] > ibd && (prices[mid-1] < ibd || fabs(prices[mid-1] - ibd) <= 0.0001 ))
            return mid; 
    	if (prices[mid] > ibd)
    		return pos_bin_search(prices, l, mid - 1, ibd, action);
    	return pos_bin_search(prices, mid + 1, r, ibd, action);	
    }
    return -1;
}

void print_sum_and_prices(double * prices, char * companies, double ibd, char action) {
	int index = pos_bin_search(prices, 0, companies_count-1, ibd, action);
	double sum = 0;
	if (action == 'C') {
		printf("Monto: %.2lf, Empresas: ", add_range(prices, 0, index));
		show_companies(companies, 0, index);
	}
	else {		
		printf("Monto: %.2lf, Empresas: ", add_range(prices, index, companies_count-1));
		show_companies(companies, index, companies_count-1);
	}
}

void make_a_decision(double * prices, char * companies) {
	double ibd = calculate_ibd(prices, 0);
	merge_sort_for_prices_and_companies(prices, companies, 0, companies_count-1);	
	printf("IBd: %.3lf, Decisión: ", ibd);
	if (ibd <= ibm) {
		printf("Compra, ");
		print_sum_and_prices(prices, companies, ibd, 'C');
	} else {
		printf("Vende, ");
		print_sum_and_prices(prices, companies, ibd, 'V');
	}
}

void analyze_stock_prices(double mat_stock_prices[][companies_count], char mat_companies[][companies_count], int ini, int end){
    if (ini == end){
    	printf("\nDía %d, ", ini+1);
    	make_a_decision(mat_stock_prices[ini], mat_companies[ini]);
        return;    	
    }
    int mid = (ini + end)/2;
    analyze_stock_prices(mat_stock_prices, mat_companies, ini, mid);
    analyze_stock_prices(mat_stock_prices, mat_companies, mid+1, end);
}

void load_stock_prices(double *stock_prices, char * companies, int company_number){
	if (company_number == companies_count) return;
	scanf("%lf", stock_prices);
	*companies = 'A' + company_number;
	load_stock_prices(stock_prices+1, companies+1, company_number+1);
}

void load_stock_prices_and_companies(double mat_stock_prices[][companies_count], 
									char mat_companies[][companies_count], int days, int day){
	if (day == days) return;
	printf("Ingrese los %d precios de cada acción [A - %c] para el día %d: ", companies_count , 'A' + companies_count - 1, day+1);	
	load_stock_prices(mat_stock_prices[day], mat_companies[day], 0);	
	load_stock_prices_and_companies(mat_stock_prices, mat_companies, days, day+1);
}

int main(){
	int t, i, j;
	printf("Ingrese la cantidad de empresas: ");
	scanf("%d", &companies_count);
	printf("Ingrese la cantidad de días: ");
	scanf("%d", &t);
	printf("Ingrese el índice bursátil meta: ");
	scanf("%lf", &ibm);

	double mat_stock_prices[t][companies_count];
	char mat_companies[t][companies_count];

	load_stock_prices_and_companies(mat_stock_prices, mat_companies, t, 0);
	analyze_stock_prices(mat_stock_prices, mat_companies, 0, t-1);
	return 0;
}