/*
 * Examen 2 (2021-1), pregunta 3a
 * Desarrollado por Johan Baldeón
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int N, MAX_LEN=12;

int is_valid(int solution[], int step, int digits[]){
	int i, marked_digit = 0, digits_count=1;
	int count = 1, aux_num;
	if (solution[0] == 0) return 0;

	for (i=1; i <= step; i++){
		if (solution[i] != solution[i-1]) {
			count++;
			if (digits_count > 3 || count >4) 
				return 0;
			
			aux_num = 0;
			for (int j=digits_count-1; j>=0; j--)
				aux_num += digits[i-(j+1)] * pow(10,j);
			
			if (aux_num > 255 || (digits_count==2 && aux_num < 10) || (digits_count==3 && aux_num < 100)) {
				return 0;													
			}
			digits_count = 1;
		}
		else 
			digits_count++;
	}
	aux_num = 0;
	for (int j=digits_count-1; j>=0; j--)
		aux_num += digits[i-(j+1)] * pow(10,j);

	if (aux_num > 255 || (digits_count==2 && aux_num < 10) || (digits_count==3 && aux_num < 100)) {
		return 0;													
	}

	if ( (step == N-1 && count != 4) || (step < N-1 && count >4) || digits_count > 3) // || 
		return 0;
	else 
		return 1;
}

void print_solution(int solution[], int step, int digits[]) {
	int i=0;
	printf("%d", digits[i]);
	for (i=1; i<=step; i++)
		if (solution[i] != solution[i-1]){
			printf(".");
			printf("%d", digits[i]);			
		} else 
			printf("%d", digits[i]);
	printf("\n");	
}

void get_IPs_rec(int solution[], int step, int digits[]){
	int i=0;
	if (step > N - 1) return;
	do {
		solution[step] = i;
		if (is_valid(solution, step, digits)){
			if (step == N - 1)
				print_solution(solution, step, digits);
			else
				get_IPs_rec(solution, step+1, digits);
		}
		i++;
	} while (solution[step] != 1);	
	solution[step] = -1;
}

int main(){
	char data[MAX_LEN];
	printf("Ingrese una cadena de sólo dígitos: ");
	scanf("%s", data);
	N = strlen(data);
	if(N <= MAX_LEN) {
		int solution[N], digits[N];
		for (int i=0; i<N; i++){
			solution[i] = -1;
			digits[i] = data[i]-'0';
		}		
		get_IPs_rec(solution, 0, digits);
	} else
		printf("No se pueden obtener direcciones por ser una cadena muy larga.\n");
	return 0;
}