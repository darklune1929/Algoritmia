#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
/* datos de ingreso:
4
19
1 4 3
2 5 2
3 4 1
4 2 1
5 6 3
6 3 3
7 4 2
8 1 4
*/
//estructura que soporta el tipo herramienta//
typedef struct herramienta {
    int precio;
    int cant;
} herramienta;
// función que busca saber si se paso del limite de tipo de herramientas y el prespuesto total además de guardar la variables maximas para colocarlas //
// en la impresión de la solución//
int esValido(int n,int* cromosoma,herramienta* herramientas,int presupuesto,int maximoTipos,int* monto_total,int* cantTotal){
    int tipos = 0,precioTotal = 0;
    int cantHerramientas = 0;
    for(int i=0;i<n;i++){
        if(cromosoma[i]==1) {
            tipos++;
            precioTotal += herramientas[i].cant * herramientas[i].precio;
            cantHerramientas += herramientas[i].cant;
        }
    }
    if(tipos>0 && maximoTipos >= tipos && precioTotal <= presupuesto && cantHerramientas > (*cantTotal)){
        (*monto_total) = precioTotal;
        (*cantTotal) = cantHerramientas;
        return 1;
    } 

    return 0;
}
// carga el cromosoma//
void cargabin(int num,int n,int cromosoma[]){
	int res,i;
	for(i=0;i<n;i++) cromosoma[i]=0;
	i=0;
	while(num>0){
		res = num%2;
		num = num/2;
		cromosoma[i]=res;
		i++;
	}
}
//muestra la solución con los datos traidos de la anterior función//
void mostrarSol(int n,int* cromosoma,int montoTotal,int cantTotal,int cantSoluciones){
    printf("Solucion %d: \n",cantSoluciones);
    for(int i=0;i<n;i++){
        if(cromosoma[i]==1){
            printf("%d ",i+1);
        }
    }
    printf("\nMonto Total: %d\n",montoTotal);
    printf("Cantidad de herramientas: %d\n",cantTotal);
}
int main(){
    int M,P,precioUni,cantRenov,tipo,n=8;
    printf("Ingrese el maximo tipo de herramientas a escoger(M): ");
    scanf("%d",&M);
    printf("Ingrese el presupuesto(P): ");
    scanf("%d",&P);
    herramienta* herramientas = (herramienta*)malloc(n*sizeof(herramienta));
    for(int i=0;i<n;i++) {
        scanf("%d %d %d",&tipo,&precioUni,&cantRenov);
        herramientas[i].cant = cantRenov;
        herramientas[i].precio = precioUni;
    }
/* estoy poniendo que el numero de tipo de herramientas es 8 dado que  este dato no entra como input y para probar con la lista que se me da*/
    int limite = pow(2,n);
    int cromosoma[8] = {0};
    int max=0,mejorSol=0;
    int montoTotal=0,cantTotal=0;
    for(int i=0;i<limite;i++){
        cargabin(i,n,cromosoma);
        if(esValido(n,cromosoma,herramientas,P,M,&montoTotal,&cantTotal)){
            mejorSol = i;
        }
    }
    int cantSoluciones=0;
    printf("Todas las soluciones posibles son: \n");
    // se toma la mejor solución que vendria a ser la cantidadTotal que cumple con las condiciones y se compara denuevo con todas las soluciones posibles
    // se hace uso de la anterior función y se va calculando la cantida de herramientas y el precio de estas para cada vez que se encuentra una solución que hace uso
    // de la cantidad maxima de herramientas y no exceda el presupuesto y en caso pase esto imprime la solución
    for(int i=0;i<limite;i++){
        int tipos = 0,costoHerramientas=0,cantHerramientas=0;
        cargabin(i,n,cromosoma);
        for(int j=0;j<n;j++){
            if(cromosoma[j]) {
                tipos++;
                cantHerramientas += herramientas[j].cant;
                costoHerramientas += herramientas[j].cant*herramientas[j].precio;
            }
        }
        if(tipos <= M && costoHerramientas <= P && cantHerramientas == cantTotal){
            cantSoluciones++;
            mostrarSol(n,cromosoma,costoHerramientas,cantHerramientas,cantSoluciones);
        }
    }
    // para esta combinación de datos solo hay una solución que cumpla las condiciones
    return 0;
}