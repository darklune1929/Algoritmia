#include <stdio.h>
#include <stdlib.h>

void readDataFromTerminal(int ncols,int nrows,int** terrain);
int recursiveExplore(int ncols,int nrows,int x,int y,int direction,int** terrain,int firstIteration);

int main() {
    int ncols;
    int nrows;
    printf("Ingresar dimensiones xmax,ymax: ");
    scanf("%d %d",&ncols,&nrows);

    int startX;
    int startY;
    printf("Ingresar punto de inicio x,y: ");
    scanf("%d %d",&startX,&startY);

    int direction;
    printf("Ingresar direccion 0-arriba 1-derecha 2-abajo 3-izquierda: ");
    scanf("%d",&direction);

    int** terrain = (int**)malloc(ncols*sizeof(int*));
    readDataFromTerminal(ncols,nrows,terrain);

    int unitsFound = recursiveExplore(ncols,nrows,startX,startY,direction,terrain,1);
    printf("Se encontraron %d unidades!",unitsFound);

    return 0;
}

int recursiveExplore(int ncols,int nrows,int x,int y,int direction,int** terrain,int firstIteration) {
    if ((x<0) || (x>=ncols) || (y<0) || (y>=nrows)) {
        return 0;
    }

    int unitsFound = 0;
    switch (direction) {
        case 0: // arriba
        case 2: // abajo
            if (firstIteration) {
                for (int i=0;i<nrows;i++) {
                    unitsFound += (terrain[x][i]==1) ? 1 : 0;
                }
            }
            for (int i=0;i<ncols;i++) {
                if (i==x) {
                    continue;
                }
                unitsFound += (terrain[i][y]==1) ? 1 : 0;
            }
            break;   
        case 1: // derecha
        case 3: // izquierda
            if (firstIteration) {
                for (int i=0;i<ncols;i++) {
                    unitsFound += (terrain[i][y]==1) ? 1 : 0;
                }
            }
            for (int i=0;i<nrows;i++) {
                if (i==y) {
                    continue;
                }
                unitsFound += (terrain[x][i]==1) ? 1 : 0;
            }
            break;
    }

    int nextX;
    int nextY;
    switch (direction) {
        case 0: // arriba
            nextX = x;
            nextY = y-1;
            break;
        case 1: // derecha
            nextX = x+1;
            nextY = y;
            break;
        case 2: // abajo
            nextX = x;
            nextY = y+1;
            break;
        case 3: // izquierda
            nextX = x-1;
            nextY = y;
            break;
    }

    return unitsFound+recursiveExplore(ncols,nrows,nextX,nextY,direction,terrain,0);
}

void readDataFromTerminal(int ncols,int nrows,int** terrain) {
    printf("Ingresar condiciones del terreno:\n");
    for (int i=0;i<ncols;i++) {
        terrain[i] = (int*)malloc(nrows*sizeof(int));
        for (int j=0;j<nrows;j++) {
            scanf("%d",&terrain[i][j]);
        }
    }
}