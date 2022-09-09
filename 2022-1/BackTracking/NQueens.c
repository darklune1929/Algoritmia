#include <stdio.h>
#include <stdlib.h>

int isValid(int** board,int currentRow,int currentColumn,int boardSize);
void nQueens(int boardSize);
int solveNQueens(int** board,int currentColumn,int boardSize);

int main() {
    int boardSize;
    printf("Ingresar dimensiones del tablero: ");
    scanf("%d",&boardSize);

    nQueens(boardSize);

    return 0;
}

int isValid(int** board,int currentRow,int currentColumn,int boardSize) {
    for (int i=0;i<currentColumn;i++) {
        if (board[currentRow][i]) {
            return 0;
        }
    }

    for (int i=currentRow,j=currentColumn;(i>=0) && (j>=0);i--,j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    for (int i=currentRow,j=currentColumn;(i<boardSize) && (j>=0);i++,j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    return 1;
}

void nQueens(int boardSize) {
    int** board = (int**)malloc(boardSize*sizeof(int*));
    for (int i=0;i<boardSize;i++) {
        board[i] = (int*)malloc(boardSize*sizeof(int));
        for (int j=0;j<boardSize;j++) {
            board[i][j] = 0;
        }
    }

    if (solveNQueens(board,0,boardSize)) {
        printf("La solucion es:\n");
        for (int j=0;j<boardSize;j++) {
            for (int i=0;i<boardSize;i++) {            
                printf("%d ",board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No hay solucion!");
    }

    free(board);
}

int solveNQueens(int** board,int currentColumn,int boardSize) {
    if (currentColumn>=boardSize) {
        return 1;
    }

    for (int i=0;i<boardSize;i++) {
        if (isValid(board,i,currentColumn,boardSize)) {
            board[i][currentColumn] = 1;
            if (solveNQueens(board,currentColumn+1,boardSize)) {
                return 1;
            } else {
                board[i][currentColumn] = 0;
            }
        }
    }

    return 0;
}