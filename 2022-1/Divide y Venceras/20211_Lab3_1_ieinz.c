#include <stdio.h>
#include <stdlib.h>

int main(){
    int companies;
    printf("Ingresar numero de compañias: ");
    scanf("%d",companies);
    int time;
    printf("Ingresar periodo del tiempo: ");
    scanf("%d",&time);

    double** stocksTable = (double**)malloc(time*sizeof(double*));
    for(int i=0;i<time;i++){
        stocksTable[i] = (double*)malloc(companies*sizeof(double));
        printf("Ingresar valores de acciones para dia %d: ",i+1);
        for(int j=0;j<companies;j++){
            scanf("%lf",&stocksTable[i][j]);
        }
    }
    free(stocksTable);
}