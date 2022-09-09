#include <stdio.h>
#include <stdlib.h>
//parte b
#define N 6
#define M 6
int max(int v1,int v2){
    if(v1 > v2 ) return v1;
    return v2; // programa para devolver el maximo de 2 numeros;
}
void robotalmaceneroDP(int p,int q,int table[][M],int solution[][q]){
    int suma = 0;
    solution[0][0] = table[0][0];
    suma = solution [0][0];
    for(int a=1;a<p;a++){
        suma +=table[0][a];
        solution[0][a] = suma;
    }
    // inicializo la primera fila de la solucion
    suma = solution [0][0];
    for(int b=1;b<q;b++){
        suma +=table[b][0];
        solution[b][0] = suma;
    }
    //inicializo la primera columna 
    for(int i=1;i<p;i++){
        for(int j=1;j<q;j++){
            solution[i][j] = max(solution[i-1][j] + table[i][j],solution[i][j-1] + table[i][j]);
            //comparo con la solución anterior y luego le sumo el actual, comparando cual seria el mayor de los 2 recorridos
        }
    }
    printf("Si el area a considerar es p = %d y q = %d\n",p,q);
    printf("La solución a esta disposición es  de %d unidades.\n",solution[p-1][q-1]);
}

int main(){
    int p,q;
    int dato;
    /*printf("Ingrese los datos n y m:");
    scanf("%d %d",&n,&m); */
    int table[N][M]= {1,2,9,1,2,3,
                      5,1,7,1,2,1,
                      1,7,1,3,8,1,
                      2,2,6,1,2,2,
                      3,6,9,5,1,5,
                      1,1,4,1,9,1};
    printf("Ingrese el area que quiere considerar:");
    scanf("%d %d",&p,&q);
    int solution[p][q];
    robotalmaceneroDP(p,q,table,solution);
    
    return 0;
}