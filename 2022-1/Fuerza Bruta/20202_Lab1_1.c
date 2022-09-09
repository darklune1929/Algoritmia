#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Worker {
    double failure;
    int salary;
} Worker;

void displayCombination(int index,int budget,double minAverageFailure,int readWorkers,int** workerCombinations);
void minimizeLosses(int minWorkers,int maxWorkers,int readWorkers,int budget,Worker* workers);
void minimizeLossesAll(int minWorkers,int maxWorkers,int readWorkers,int budget,Worker* workers);
int readDataFromFile(int totalWorkers,Worker* workers);

int main() {
    int totalWorkers = 12;
    Worker* workers = (Worker*)malloc(totalWorkers*sizeof(Worker));

    int readWorkers = readDataFromFile(totalWorkers,workers);
    printf("Se han encontrado %d obreros",readWorkers);

    int minWorkers, maxWorkers;
    printf("\nIngresar cantidad min. y max. de obreros: ");
    scanf("%d %d",&minWorkers,&maxWorkers);

    int budget;
    printf("Ingresar presupuesto: ");
    scanf("%d",&budget);

    printf("\nUna solución:");
    minimizeLosses(minWorkers,maxWorkers,readWorkers,budget,workers);

    printf("\n\nTodas las soluciones:");
    minimizeLossesAll(minWorkers,maxWorkers,readWorkers,budget,workers);

    free(workers);

    return 0;
}

void displayCombination(int index,int budget,double minAverageFailure,int readWorkers,int** workerCombinations) {
    printf("\nObreros:   ");
    for (int i=0;i<readWorkers;i++) {
        printf("%d ",(i+1));
    }
    printf("\nSeleccion: ");
    for (int i=0;i<readWorkers;i++) {
        printf("%d ",workerCombinations[index][i]);
    }
    printf("\nCosto total: %d, fallas promedio %f\n",budget,minAverageFailure);
}

void minimizeLosses(int minWorkers,int maxWorkers,int readWorkers,int budget,Worker* workers) {
    int budgetSpent;
    int index;
    double minAverageFailure = INFINITY;

    int totalCombinations = pow(2,readWorkers);
    int** workerCombinations = (int**)malloc(totalCombinations*sizeof(int*));

    for (int i=0; i<totalCombinations;i++) {
        workerCombinations[i] = (int*)malloc(readWorkers*sizeof(int));
        for (int j=0;j<readWorkers;j++) {
            workerCombinations[i][j] = 0;
        }
        
        int temp = i;
        int j = 0;
        while(temp>0) {
            workerCombinations[i][j] = temp%2;
            temp /= 2;
            j++;
        }

        int currentBudget = 0;
        int currentWorkers = 0;
        double currentAverageFailure = 0;
        for (int j=0;j<readWorkers;j++) {
            currentBudget += workerCombinations[i][j]*workers[j].salary;
            currentWorkers += workerCombinations[i][j];
            currentAverageFailure += workerCombinations[i][j]*workers[j].failure;
        }
        currentAverageFailure /= currentWorkers;

        if ((currentWorkers>=minWorkers) && 
                (currentWorkers<=maxWorkers) && 
                (currentBudget<=budget) &&
                (currentAverageFailure<minAverageFailure)) {
            minAverageFailure = currentAverageFailure;
            budgetSpent = currentBudget;
            index = i;
        }
    }

    displayCombination(index,budgetSpent,minAverageFailure,readWorkers,workerCombinations);

    free(workerCombinations);
}

void minimizeLossesAll(int minWorkers,int maxWorkers,int readWorkers,int budget,Worker* workers) {
    double minAverageFailure = INFINITY;

    int totalCombinations = pow(2,readWorkers);
    int** workerCombinations = (int**)malloc(totalCombinations*sizeof(int*));
    int* budgetSpent = (int*)malloc(totalCombinations*sizeof(int));
    double* averageFailure = (double*)malloc(totalCombinations*sizeof(double));

    for (int i=0; i<totalCombinations;i++) {
        workerCombinations[i] = (int*)malloc(readWorkers*sizeof(int));
        for (int j=0;j<readWorkers;j++) {
            workerCombinations[i][j] = 0;
        }
        
        int temp = i;
        int j = 0;
        while(temp>0) {
            workerCombinations[i][j] = temp%2;
            temp /= 2;
            j++;
        }

        int currentBudget = 0;
        int currentWorkers = 0;
        double currentAverageFailure = 0;
        for (int j=0;j<readWorkers;j++) {
            currentBudget += workerCombinations[i][j]*workers[j].salary;
            currentWorkers += workerCombinations[i][j];
            currentAverageFailure += workerCombinations[i][j]*workers[j].failure;
        }
        currentAverageFailure /= currentWorkers;

        if ((currentWorkers>=minWorkers) && 
                (currentWorkers<=maxWorkers) && 
                (currentBudget<=budget) &&
                (currentAverageFailure<minAverageFailure)) {
            minAverageFailure = currentAverageFailure;
        }

        budgetSpent[i] = currentBudget;
        averageFailure[i] = currentAverageFailure;
    }

    for (int i=0;i<totalCombinations;i++) {
        if((averageFailure[i]==minAverageFailure) &&
                (budgetSpent[i]<=budget)) {
            displayCombination(i,budgetSpent[i],averageFailure[i],readWorkers,workerCombinations);
        }
    }    

    free(workerCombinations);
}

int readDataFromFile(int totalWorkers,Worker* workers) {
    int readWorkers = totalWorkers;

    FILE* file = fopen("20202_Lab1_1.txt","r");
    for (int i=0;i<totalWorkers;i++) {
        int assigned = fscanf(file,"%lf %d",&workers[i].failure,&workers[i].salary);
        if (assigned<2) {
            readWorkers = i;
            break;
        }
    }
    fclose(file);

    return readWorkers;
}