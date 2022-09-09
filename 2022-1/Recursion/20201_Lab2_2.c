#include <stdio.h>
#include <stdlib.h>

void displayStorage(int nrows,int ncols,int** storage);
int populateStorage(int startRow,int endRow,int ncols,int minSlots,int maxSlots,int** storage);
void readData(int nrows,int ncols,int** storage);

int main() {
    int nrows,ncols;
    printf("Ingresar filas y columnas: ");
    scanf("%d %d",&nrows,&ncols);

    int** storage = (int**)malloc(nrows*sizeof(int*));
    readData(nrows,ncols,storage);
    
    int wantedSlots;
    printf("Ingresar ubicaciones deseadas: ");
    scanf("%d",&wantedSlots);

    int minSlots,maxSlots;
    printf("Ingresar minimo y maximo de ubicaciones por columna: ");
    scanf("%d %d",&minSlots,&maxSlots);

    int availableSlots = populateStorage(0,nrows-1,ncols,minSlots,maxSlots,storage);
    printf("Espacios disponibles: %d\n",availableSlots);
    if (availableSlots>=wantedSlots) {
        printf("Se pueden ubicar los productos! :)\n");
    } else {
        printf("No se pueden ubicar los productos! :(\n");
    }

    displayStorage(nrows,ncols,storage);

    return 0;
}

void displayStorage(int nrows,int ncols,int** storage) {
    for (int i=0;i<nrows;i++) {
        for (int j=0;j<ncols;j++) {
            printf("%d ",storage[i][j]);
        }
        printf("\n");
    }
}

int populateStorage(int startRow,int endRow,int ncols,int minSlots,int maxSlots,int** storage) {
    if ((startRow>endRow) || (minSlots>maxSlots)) {
        return 0;
    }

    int storageSlots = 0;
    int minCols = ((ncols>maxSlots) ? maxSlots : ncols);

    if (startRow==endRow) {
        for (int i=0;i<minCols;i++) {
            if (storage[startRow][i]==0) {
                storage[startRow][i] = 5;
                storageSlots++;
            }
        }
    } else {
        for (int i=0;i<minCols;i++) {
            if (storage[startRow][i]==0) {
                storage[startRow][i] = 5;
                storageSlots++;
            }
            if (storage[endRow][i]==0) {
                storage[endRow][i] = 5;
                storageSlots++;
            }
        }
    }

    return storageSlots + populateStorage(startRow+1,endRow-1,ncols,minSlots,maxSlots-1,storage);
}

void readData(int nrows,int ncols,int** storage) {
    printf("Ingresar informacion de almacen: ");
    for (int i=0;i<nrows;i++) {
        storage[i] = (int*)malloc(ncols*sizeof(int));
        for (int j=0;j<ncols;j++) {
            scanf("%d",&storage[i][j]);
        }
    }
}