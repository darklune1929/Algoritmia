#include <stdio.h>
#define N 9
int encontrarEspacio(int Sudoku[N][N],int *fila,int *columna){
    for ((*fila) = 0; (*fila) < N; (*fila)++)
        for ((*columna) = 0; (*columna) < N; (*columna)++)
            if (Sudoku[(*fila)][(*columna)] == 0)
                return 1;
    return 0;
}
int buscaFila(int Sudoku[N][N], int fila, int num){
    for (int columna = 0; columna < N; columna++)
        if (Sudoku[fila][columna] == num)
            return 1;
    return 0;
}
int buscaColumna(int Sudoku[N][N], int columna, int num){
    for (int fila = 0; fila < N; fila++)
        if (Sudoku[fila][columna] == num)
            return 1;
    return 0;
}
int busca3x3(int Sudoku[N][N], int filaini,int columnaini, int num){
    for (int fila = 0; fila < 3; fila++)
        for (int columna = 0; columna < 3; columna++)
            if (Sudoku[fila + filaini][columna + columnaini] == num)
                return 1;
    return 0;
}
int sePuedeColocar(int Sudoku[N][N], int fila,int columna, int num){
    return (!buscaFila(Sudoku, fila, num) && !buscaColumna(Sudoku, columna, num)
           && !busca3x3(Sudoku, fila - fila % 3,columna - columna % 3, num) && Sudoku[fila][columna] == 0);
}
int ResolverSudoku(int Sudoku[N][N]){
    int fila, columna;
    if (!encontrarEspacio(Sudoku,&fila,&columna))
        return 1;
    for (int num = 1; num <= 9; num++){  
        if (sePuedeColocar(Sudoku, fila, columna, num)){
            Sudoku[fila][columna] = num;
            if (ResolverSudoku(Sudoku))
                return 1;
            Sudoku[fila][columna] = 0;
        }
    }
    return 0;
}
void mostrar(int Sudoku[N][N]){
    for (int fila = 0; fila < N; fila++) {
        for (int columna = 0; columna < N; columna++)
            printf("%3d ", Sudoku[fila][columna]);
        printf("\n");
    }
}
int main(){
    // aca puede colocar el sudoku que quiera resolver pero tiene que tener comas :¨v
    int Sudoku[N][N] = {0,0,1,0,0,9,0,0,6,
                        0,0,0,0,0,5,0,0,4,
                        0,6,4,0,3,0,0,0,2,
                        0,0,3,0,0,7,0,8,0,
                        4,5,0,0,0,0,0,0,0,
                        7,0,0,0,5,0,0,1,0,
                        0,0,7,2,0,0,0,0,1,
                        0,0,0,0,0,0,0,0,0,
                        0,0,6,0,0,3,0,9,0};
    if (ResolverSudoku(Sudoku) == 1)
        mostrar(Sudoku);
    else
        printf("No tiene solución");
    return 0;
}