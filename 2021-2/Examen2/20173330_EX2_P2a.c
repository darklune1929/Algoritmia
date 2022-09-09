#include <stdio.h>
#include <stdlib.h>
/* datos 
4 2 2 4
1 4 6 8
2 5 9 1
1 3 11 12 */
#define N 4
#define M 4
//parte a
int min(int v1,int v2,int v3){
    if(v1 < v2 && v1 < v3) return v1;
    if(v2 < v3) return v2;
    return v3; // programa para devolver el menor de 3 numeros;
}
void printtable(int n,int m,int solution[][M]){
    for (int i=0; i<n ;i++){
        for(int j=0;j<m;j++)
        printf("%d ",solution[i][j]);
        printf("\n");
    }
}
void robotdronDP(int n,int m,int table[][M],int solution[][M]){
    int diff = 0;
    solution[0][0] = 0;
    for(int a=1;a<n;a++){
        diff +=abs(table[0][a]-table[0][a-1]);
        solution[0][a] = diff;
    }
    // inicializo la primera fila
    diff=0;
    for(int b=1;b<m;b++){
        diff +=abs(table[b][0]-table[b-1][0]);
        solution[b][0] = diff;
    }
    //inicializo la primera columna para poder comparar con
    // la casilla de la tabla solution que este arriba, a la izquierda y diagonal superior izquierda
    //dado que los posibles movimientos son derecha,abajo y diagonal inferior derecha
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            solution[i][j] = min(solution[i-1][j-1] + abs(table[i][j]-table[i-1][j-1]),
            solution[i-1][j] + abs(table[i][j]-table[i-1][j]),solution[i][j-1] + abs(table[i][j]-table[i][j-1]));
            //comparo con el minimo de las anteriores diferencias de alturas sumandole la diferencia de la casilla actual con
            // la casilla anterior desde donde quiero moverme asi obteniendo el minimo recorrido para cada casilla
        }
    }
}
int main(){
    //int n,m;
    int dato;
    /*printf("Ingrese los datos n y m:");
    scanf("%d %d",&n,&m); */
    int table[N][M]= {4,2,2,4,1,4,6,8,2,5,9,1,1,3,11,12};
    int solution[N][M];
    /* printf("Ingrese los datos de la tabla %d x %d:\n",n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&dato);
            table[i][j]=dato;
        }
    }*/
    robotdronDP(N,M,table,solution);
    printtable(N,M,solution);
    //printtable(n,m,table);


    return 0;
}
