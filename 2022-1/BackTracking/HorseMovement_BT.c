#include <stdio.h>
#define N 8

void print_solution(int board[N][N]){
	int i, j;
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++)
			printf(" %2d ", board[i][j]);
		printf("\n");
	}
}

int is_safe(int board[N][N], int x, int y){
	return (x>=0 && x<N && y>=0 && y<N && board[x][y] == -1);
}

int solve_HM_BT(int board[N][N], int x, int y, 
				int move_i, int x_move[N], int y_move[N]){
	int k, bt_return, next_x, next_y;
	if (move_i == N * N)
		return 1;
	else {
		for (k=0; k<8; k++){
			next_x = x + x_move[k];
			next_y = y + y_move[k];
			if (is_safe(board, next_x, next_y)){
				board[next_x][next_y] = move_i;
				bt_return = solve_HM_BT(board, next_x, next_y, 
									    move_i+1, x_move, y_move);
				if (bt_return)
					return 1;
				else
					board[next_x][next_y] = -1; // backtracking
			}
		}
		return 0;
	}
}

int solve_horse_movement() {
	int board[N][N], i, j;

	for (i=0; i<N; i++)
		for (j=0; j<N; j++)
			board[i][j] = -1;

	int x_move[8] = {2, 1,-1,-2,-2,-1, 1, 2};
	int y_move[8] = {1, 2, 2, 1,-1,-2,-2,-1};	

	board[0][0] = 0;

	i = solve_HM_BT(board, 0, 0, 1, x_move, y_move);
	if (i) {
		print_solution(board);
		return 1;
	}
	else {	
		printf("La solución no existe!");
		return 0;
	}	
}

int main() {
	solve_horse_movement();
	return 0;
}