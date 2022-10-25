#include "stdio.h"

/*
Desarrollado por Johan Baldeón
Problema de las N reinas con una solución
*/

#define N 4

void fill_board(int board[N][N]){
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			board[i][j] = 0;
}

void print_board(int board[N][N]){
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
}

int is_valid(int board[N][N], int row, int col){
	int i, j;
	//Se evalúan las filas superiores en la misma columna.
	for(i=0; i< row; i++)
		if (board[i][col] == 1) return 0;

	//Se evalúa la diagonal superior izquierda
	for (i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
		if(board[i][j] == 1) return 0;

	//Se evalúa la diagonal superior derecha
	for (i=row-1, j=col+1; i>=0 && j<N; i--, j++)
		if(board[i][j] == 1) return 0;

	return 1;
}

int n_queens_bt(int n, int board[][n], int row){
	int bt_res=0;
	if (row == n) 
		return 1;

	for (int i=0; i<n; i++){
		if (is_valid(board, row, i)){
			board[row][i] = 1;
			bt_res = n_queens_bt(n, board, row+1);
			if (bt_res)
				return 1;
			else
				board[row][i] = 0; // Regresamos a su valor anterior
		}
	}
	return 0;
}

int main(){
	int board [N][N];
	fill_board(board);

	n_queens_bt(N, board, 0);

	print_board(board);
	return 0;
}