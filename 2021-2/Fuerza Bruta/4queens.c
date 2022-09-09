/*
 * Ejemplo de fuerza bruta para resolver el problema de las 4 reinas.
 * Desarrollado por Johan Baldeón 
*/
#include <stdio.h>
#include <math.h>

const int N = 5;

/* Función que convierte un número en base 10 a matriz de bits */
void fill_chromosome_board(int n, int chromosome_board[N][N]);

/* Función que verifica si el cromosoma matricial de distribución de reinas es una solución válida. */
int is_valid(int chromosome_board[N][N]);

/* Función que muestra el tablero con la distribución de las reinas*/
void show_board(int chromosome_board[N][N]);

int main(){
	int chromosome_board[N][N];
	int k, lim = pow(2, N * N);
	for (k=0; k< lim; k++) {
		fill_chromosome_board(k, chromosome_board);
		if (is_valid(chromosome_board)){			
			show_board(chromosome_board);
			printf("\n");
		}
	}
	return 0;
}

void fill_chromosome_board(int n, int chromosome_board[N][N]){	
	int i=N*N-1,j;
	while ( n != 0) {
		chromosome_board[i/N][i%N] = n%2;
		n /= 2;
		i--;
	}
	for (j=0; j<=i; j++)
		chromosome_board[j/N][j%N] = 0;
}

/* Función que verifica si el cromosoma matricial de distribución de reinas es una solución válida. */
int is_valid(int chromosome_board[N][N]){
	int i,j, bit_total_counter=0, row_bit_counter, col_bit_counter,
		left_down_diagonal_bit_counter, right_down_diagonal_bit_counter, 
		left_up_diagonal_bit_counter, right_up_diagonal_bit_counter;

	for (i=0; i<N; i++) {
		row_bit_counter = 0;
		col_bit_counter = 0;
		left_down_diagonal_bit_counter = 0;
		right_down_diagonal_bit_counter = 0;
		left_up_diagonal_bit_counter = 0;
		right_up_diagonal_bit_counter = 0;		
		for (j=0; j<N; j++){
			bit_total_counter += chromosome_board[i][j]; //Cuenta los bits prendidos totales
			if (bit_total_counter > N) // Si el número de bits prendidos totales sobrepasa la cantidad N, retorna 0.
				return 0;
			row_bit_counter += chromosome_board[i][j]; //Cuenta los bits prendidos por fila
			if (row_bit_counter > 1) // Si el número de bits prendidos por fila es mayor que 1, retorna 0.
				return 0;
			col_bit_counter += chromosome_board[j][i]; //Cuenta los bits prendidos por columna
			if (col_bit_counter > 1) // Si el número de bits prendidos por columna es mayor que 1, retorna 0.
				return 0;
			if (i+j<N) {
				left_down_diagonal_bit_counter += chromosome_board[i+j][j]; //Cuenta los bits prendidos por diagonal con pendiente negativa del lado izquierdo a la diagonal principal con pendiente negativa.
				right_down_diagonal_bit_counter += chromosome_board[j][i+j];//Cuenta los bits prendidos por diagonal con pendiente negativa del lado derecho a la diagonal principal con pendiente negativa.
				if (left_down_diagonal_bit_counter > 1 || right_down_diagonal_bit_counter > 1) // Si el número de bits prendidos es mayor que 1, retorna 0.
					return 0;

				if (N-1-i-j >= 0){
					left_up_diagonal_bit_counter += chromosome_board[N-1-i-j][j]; //Cuenta los bits prendidos por diagonal con pendiente positiva del lado izquierdo a la diagonal principal con pendiente positiva.
					right_up_diagonal_bit_counter += chromosome_board[N-1-j][i+j]; //Cuenta los bits prendidos por diagonal con pendiente positiva del lado derecho a la diagonal principal con pendiente positiva.
					if (left_up_diagonal_bit_counter > 1 || right_up_diagonal_bit_counter > 1)
						return 0;
				}
			}			
		}
	}
	if (bit_total_counter < N) //Si el número de bits totales prendidos es menor a la cantidad N, retorna 0.
		return 0;
	else
		return 1;	
}

void show_board(int chromosome_board[N][N]){
	int i,j;
	for (i=0; i<N; i++){
		for (j=0; j<N; j++)
			if (chromosome_board[i][j])
				printf("Q");
			else
				printf("_");
		printf("\n");	
	}
}
