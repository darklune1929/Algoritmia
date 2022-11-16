

#include <stdio.h>
#include <stdlib.h>

#define ELEM 4
#define W 5

int max(int val1, int val2){
    if (val1>val2) 
        return val1;
    else
        return val2;
}

void llenar_mochila(int pesos[], double valores[], double V[ELEM + 1][W + 1]) {
    int i, j;
    //Condiciones iniciales
    for (j = 0; j <= W; j++)
        V[0][j] = 0;
    for (i = 0; i <= ELEM; i++)
        V[i][0] = 0;
    
    //Iteraciones
    for (j = 1; j <= W; j++) {
        for (i = 1; i <= ELEM; i++) {
            if (j - pesos[i- 1] >= 0)
                V[i][j] = max(V[i - 1][j], valores[i - 1] + V[i - 1][j - pesos[i - 1]]);
            else
                V[i][j] = V[i - 1][j];
        }
    }
    
}

void pprint(double V[ELEM + 1][W + 1]) {
    int i, j;
    for (i=0;i<=ELEM;i++){
        for (j=0;j<=W; j++) {
            printf("%2.2lf ", V[i][j]);
        }
        printf("\n");
    }
}

int main() {
			
    int pesos[ELEM] = {2, 1, 3, 20};
    double valores[ELEM] = {12, 10, 20, 15};

    double V[ELEM + 1][W + 1];

    llenar_mochila(pesos, valores, V);

    printf("Maximo valor: %2.2lf\n", V[ELEM][W]);

    printf("Estructura Auxiliar:\n");
    pprint(V);
    
    return (EXIT_SUCCESS);
}

