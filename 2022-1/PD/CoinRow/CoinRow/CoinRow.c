#include <stdio.h>
#include <stdlib.h>

#define max(x,y) ((x>y) ? x : y)

int coinRow(int numberOfCoins,int* coins);

int main() {
    int numberOfCoins;
    printf("Ingresar numero de monedas: ");
    scanf("%d",&numberOfCoins);

    int* coins = (int*)malloc(numberOfCoins*sizeof(int));
    printf("Ingresar las monedas: ");
    for (int i=0;i<numberOfCoins;i++) {
        scanf("%d",&coins[i]);
    }

    int maxValue = coinRow(numberOfCoins,coins);
    printf("\nEl valor maximo es %d",maxValue);

    return 0;
}

int coinRow(int numberOfCoins,int* coins) {
    int* bestValue = (int*)malloc((numberOfCoins+1)*sizeof(int));
    bestValue[0] = 0;
    bestValue[1] = coins[0];

    for (int i=0;i<=numberOfCoins;i++) {
        if (i>=2) {
            bestValue[i] = max(bestValue[i-1],coins[i-1]+bestValue[i-2]);
        }
        printf("%d ",bestValue[i]);
    }

    return bestValue[numberOfCoins];
}