#include <stdio.h>
#include <stdlib.h>

#define abs(x) (((x)<0) ? -(x) : (x))
#define max(x,y) (((x)>(y)) ? (x) : (y))
#define min(x,y) (((x)<(y)) ? (x) : (y))

void solveDrone(int droneX,int droneY,int** droneBoard,int** droneAnswer);
void solveStorage(int storageX,int storageY,int** storageBoard,int** storageAnswer);

int main() {
    // Drone
    int droneX, droneY;
    printf("Ingresar dimensiones maximas de drone: ");
    scanf("%d %d",&droneX,&droneY);

    printf("Ingresar tablero de drone:\n");
    int** droneBoard = (int**)malloc(droneY*sizeof(int*));
    int** droneAnswer = (int**)malloc(droneY*sizeof(int*));
    for (int i=0;i<droneY;i++) {
        droneBoard[i] = (int*)malloc(droneX*sizeof(int));
        droneAnswer[i] = (int*)malloc(droneX*sizeof(int));
        for (int j=0;j<droneX;j++) {
            scanf("%d",&droneBoard[i][j]);
            droneAnswer[i][j] = 0;
        }
    }

    solveDrone(droneX,droneY,droneBoard,droneAnswer);

    printf("La solcuion para el drone:\n");
    for (int i=0;i<droneY;i++) {
        for (int j=0;j<droneX;j++) {
            printf("%d ",droneAnswer[i][j]);
        }
        printf("\n");
    }

    // Almacen
    int storageX, storageY;
    printf("Ingresar dimensiones maximas de robot almacen: ");
    scanf("%d %d",&storageX,&storageY);

    printf("Ingresar tablero de robot almacen:\n");
    int** storageBoard = (int**)malloc(storageY*sizeof(int*));
    int** storageAnswer = (int**)malloc(storageY*sizeof(int*));
    for (int i=0;i<storageY;i++) {
        storageBoard[i] = (int*)malloc(storageX*sizeof(int));
        storageAnswer[i] = (int*)malloc(storageX*sizeof(int));
        for (int j=0;j<storageX;j++) {
            scanf("%d",&storageBoard[i][j]);
            storageAnswer[i][j] = 0;
        }
    }

    solveStorage(storageX,storageY,storageBoard,storageAnswer);

    printf("La solcuion para el robot almacen:\n");
    for (int i=0;i<storageY;i++) {
        for (int j=0;j<storageX;j++) {
            printf("%02d ",storageAnswer[i][j]);
        }
        printf("\n");
    }

    int storageGoalX, storageGoalY;
    printf("Ingresar posicion final de robot almacen: ");
    scanf("%d %d",&storageGoalX,&storageGoalY);
    printf("La solucion a esta disposicion es %d unidades",storageAnswer[storageGoalX-1][storageGoalY-1]);

    free(droneAnswer);
    free(droneBoard);
    free(storageAnswer);
    free(storageBoard);

    return 0;
}

void solveDrone(int droneX,int droneY,int** droneBoard,int** droneAnswer) {
    for (int i=1;i<droneX;i++) {
        droneAnswer[0][i] = droneAnswer[0][i-1] + abs(droneBoard[0][i]-droneBoard[0][i-1]);
    }

    for (int i=1;i<droneY;i++) {
        droneAnswer[i][0] = droneAnswer[i-1][0] + abs(droneBoard[i][0]-droneBoard[i-1][0]);
    }

    for (int i=1;i<droneX;i++) {
        for (int j=1;j<droneY;j++) {
            int diffH = droneAnswer[j][i-1] + abs(droneBoard[j][i]-droneBoard[j][i-1]);
            int diffV = droneAnswer[j-1][i] + abs(droneBoard[j][i]-droneBoard[j-1][i]);
            int diffD = droneAnswer[j-1][i-1] + abs(droneBoard[j][i]-droneBoard[j-1][i-1]);
            droneAnswer[j][i] = min(min(diffH,diffV),diffD);
        }
    }
}

void solveStorage(int storageX,int storageY,int** storageBoard,int** storageAnswer) {
    storageAnswer[0][0] = storageBoard[0][0];

    for (int i=1;i<storageX;i++) {
        storageAnswer[0][i] = storageAnswer[0][i-1] + storageBoard[0][i];
    }

    for (int i=1;i<storageY;i++) {
        storageAnswer[i][0] = storageAnswer[i-1][0] + storageBoard[i][0];
    }

    for (int i=1;i<storageX;i++) {
        for (int j=1;j<storageY;j++) {
            int sumH = storageAnswer[j][i-1] + storageBoard[j][i];
            int sumV = storageAnswer[j-1][i] + storageBoard[j][i];
            storageAnswer[j][i] = max(sumH,sumV);
        }
    }
}