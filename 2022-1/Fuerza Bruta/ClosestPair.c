#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define readFromTerminal 0

typedef struct {
    int x;
    int y;
} Point2D;

double closestPair(int pointAmount, Point2D* pointList, int* pair);
double distance(Point2D P1, Point2D P2);
void readDataFile(int pointAmount, Point2D* pointList);
void readDataTerminal(int pointAmount, Point2D* pointList);

int main() {
    int pointAmount;
    printf("Ingresar # de puntos: ");
    scanf("%d",&pointAmount);
    Point2D* pointList = (Point2D*)malloc(pointAmount*sizeof(Point2D));

    if(readFromTerminal) {
        readDataTerminal(pointAmount,pointList);
    }else {
        readDataFile(pointAmount,pointList);
    }

    int* pair = (int*)malloc(2*sizeof(int));
    double minDistance = closestPair(pointAmount,pointList,pair);

    printf("El par mas cercano es: [%d] (%d,%d), [%d] (%d,%d), con distancia %f",
            pair[0],pointList[pair[0]].x,pointList[pair[0]].y,
            pair[1],pointList[pair[1]].x,pointList[pair[1]].y,
            minDistance);
    
    free(pointList);
    free(pair);

    return 0;
}

double closestPair(int pointAmount, Point2D* pointList, int* pair) {
    double minDistance = INFINITY;

    for (int i = 0; i<(pointAmount-1); i++) {
        for (int j = (i+1); j<pointAmount; j++) {
            double currentDistance = distance(pointList[i],pointList[j]);
            if (currentDistance<minDistance) {
                pair[0] = i;
                pair[1] = j;
                minDistance = currentDistance;
            }
        }
    }

    return minDistance;
}

double distance(Point2D P1, Point2D P2) {
    return sqrt(pow(P1.x-P2.x,2)+pow(P1.y-P2.y,2));
}

void readDataFile(int pointAmount, Point2D* pointList) {
    FILE* file = fopen("ClosestPairData.txt","r");
    for (int i = 0; i<pointAmount; i++) {
        fscanf(file,"%d %d",&pointList[i].x,&pointList[i].y);
    }
    fclose(file);
}

void readDataTerminal(int pointAmount, Point2D* pointList) {
    for (int i = 0; i<pointAmount; i++){
        printf("Ingresar punto %d: ",(i+1));
        scanf("%d %d",&pointList[i].x,&pointList[i].y);
    }
}