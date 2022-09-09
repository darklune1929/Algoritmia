#include <stdio.h>
#include <math.h>

const int N=4;

void fill_chromosome_board(int n, int chromosome_board[N][N]);

int is_valid(int chromosome_board[N][N]);

void show_board(int chromosome_board[N][N]);

int main() {
	int chromosome_board[N][N];
	int k, lim = pow(2, N * N);
	for (k=0; k<lim; k++){
		fill_chromosome_board(k, chromosome_board);
		if (is_valid(chromosome_board)){
			show_board(chromosome_board);
			printf("\n");
		}
	}
	return 0;
}

void fill_chromosome_board(int n, int chromosome_board[N][N]){
	int i= N*N -1, j;
	while (n != 0){
		chromosome_board[i/N][i%N] = n%2;
		n /= 2;
		i--;
	}
	for (j=0; j<=i; j++)
		chromosome_board[j/N][j%N] = 0;
}

int is_valid(int chromosome_board[N][N]){
	int i, j, bit_total_counter=0,
	row_bit_counter, col_bit_counter, left_down_diagonal_bit_counter, left_up_diagonal_bit_counter,
	right_down_diagonal_bit_counter, right_up_diagonal_bit_counter;

	for (i=0; i<N; i++){
		row_bit_counter = 0;
		col_bit_counter = 0;
		left_down_diagonal_bit_counter = 0;
		right_down_diagonal_bit_counter = 0;
		left_up_diagonal_bit_counter = 0;
		right_up_diagonal_bit_counter = 0;
		for (j=0; j<N; j++){
			bit_total_counter += chromosome_board[i][j];
			if (bit_total_counter > N) return 0;

			row_bit_counter += chromosome_board[i][j];
			if (row_bit_counter > 1) return 0;

			col_bit_counter += chromosome_board[j][i];
			if (col_bit_counter > 1) return 0;

			if (i+j < N){
				left_down_diagonal_bit_counter += chromosome_board[i+j][j];
				right_down_diagonal_bit_counter += chromosome_board[j][i+j];
				if (left_down_diagonal_bit_counter>1 || right_down_diagonal_bit_counter >1 ) return 0;

				if (N-1-i-j >=0 ){
					left_up_diagonal_bit_counter += chromosome_board[N-1-i-j][j];
					right_up_diagonal_bit_counter += chromosome_board[N-1-j][i+j];
					if (left_up_diagonal_bit_counter >1 || right_up_diagonal_bit_counter>1) return 0;
				}
			}
		}
	}
	if (bit_total_counter < N) 	return 0;
	else						return 1;
}

void show_board(int chromosome_board[N][N]){
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++)
			if (chromosome_board[i][j]) printf("Q");
			else printf("_");
		printf("\n");	
	}
}