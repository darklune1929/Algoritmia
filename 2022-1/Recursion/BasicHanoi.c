#include <stdio.h>

void basicHanoi(int towerSize,char startTower,char extraTower,char endTower);

int main() {
    int towerHeight;
    printf("Ingresar altura de torre: ");
    scanf("%d",&towerHeight);

    basicHanoi(towerHeight,'A','B','C');

    return 0;
}

void basicHanoi(int towerSize,char startTower,char extraTower,char endTower) {
    if (towerSize==0) {
        return;
    }

    basicHanoi(towerSize-1,startTower,endTower,extraTower);
    printf("Mover disco %d de la posicion %c a %c\n",towerSize,startTower,endTower);
    basicHanoi(towerSize-1,extraTower,startTower,endTower);
}