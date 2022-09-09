/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Proyecto: 20180712_Lab2_P2
 * Archivo: main.c
 * Autor: Mauricio Arenales Aquino
 * Codigo: 20180712
 * Created on 24 de septiembre de 2021, 03:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//EXPLICACION DEL PROCEDIMIENTO-----------------------------------
/*
 El almacen lo modelaremos como una matriz nxn. Para hacer la comparacion entre
 * que ruta tiene mayor peso, primeramente hallaremos el peso de la ruta más larga; luego, con 
 ayuda de la recursion, retornaremos la ruta el mayor peso si considerar la ruta más larga que 
 hemos evaluado. Compararemos estos 2 mejores casos y retornaremos, por supuesto, el mejor.
 En el problema debemos tener bastante cuidado al establecer limites en la lectura de los 
 datos de la matriz en forma de L. Ademas, tambien tendremos en cuenta la primera columna de la
 ultima fila, ya que esta no trabajará en el programa(Será otra restricción más en el problema)..
 */
//FUNCIONES MIAS----------------------------------------------------------
void eliminarMayor(int mayor,int **matriz, int columna,int x){
    if(matriz[x][columna-1]==mayor){
        matriz[x][columna-1]=0;
        return;
    }
    eliminarMayor(mayor,matriz, columna-1,x);
}

int hallarMayor(int **matriz, int columna, int x){
    if(columna==1)return matriz[x][0];
    int mayor1=matriz[x][columna-1];
    int mayor2=hallarMayor(matriz, columna-1,x);
    if(mayor1>mayor2)
        return mayor1;
    else 
        return mayor2;
} 

void imprimeMayores(int I,int **matriz, int columna, int x){
    if(I==0)return;//caso directo
    int mayor=hallarMayor(matriz, columna, x);
    eliminarMayor(mayor,matriz, columna,x);//Cambiaremos por cero la posicion del valor mayor
    printf("%d ", mayor);
    imprimeMayores(I-1,matriz,columna,x);
}
void pedirDatos(int **matriz,int fila, int columna){
    printf("\nIngreso de datos:\n");
    for(int i=0;i<fila;i++){
        printf("Ingrese los datos de la fila %d (%d valores) : ", i+1, columna);
        for(int j=0;j<columna;j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}
void imprimirDatos(int **matriz, int fila, int columna){
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
//FUNCIONES PROYECTO----------------------------------------------------------

int sumadorHoriz(int **almacen,int x,int columna){
    if(columna==1)return almacen[x][0];
    return almacen[x][columna-1]+sumadorHoriz(almacen,x,columna-1);
}

int sumadorVert(int **almacen,int columna, int x, int cantFila){
    if(cantFila==x+1)return almacen[x][columna];
    return almacen[x][columna] + sumadorVert(almacen,columna,x+1, cantFila);
}

int pesoMax(int x,int y,int **almacen,int fila,int columna){
    //Sumaremos los datos de la ruta más larga
    if(columna==1)return 0;//Parte del almacen sin entrada y salida
    int sum=0;
/*
    for(int i=0; i<columna;i++){
        sum += almacen[x][i];
    }
*/
    sum = sumadorHoriz(almacen,x,columna);
/*
    for(int i=x+1;i<fila;i++){
        sum += almacen[columna-1][i];
    }
*/
    sum += sumadorVert(almacen,columna-1, x+1,fila);
    //Caso recursivo
    int sum2=pesoMax(x+1,y,almacen, fila,columna-1);
    
    if(sum>sum2)
        return sum;
    else
        return sum2;
}

//MAIN-----------------------------------------------------------------
int main(int argc, char** argv) {
    //En cada ubicacion del almacen hay un produco representado por su peso
    //Donde haya un cero como peso, quiere decir que está vacío
    //LA ultima fila no tien puerta de entrada ni de salida (condicionar para que no trabaje la ultima fila)
    printf("Ingrese el tamanio de un lado del almacen(de medidas nxn): ");
    int n;
    scanf("%d", &n);
    //Modelaremos el almacen como una matriz nxn
    int **almacen=(int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++)almacen[i]=(int *)malloc(sizeof(int )*n);
    //Pedir e imprimir datos
    pedirDatos(almacen,n,n);
    int pesoMaximo=pesoMax(0,0,almacen,n,n);
    printf("%d\n", pesoMaximo);
    //imprimirDatos(matriz, n,n);
    return (EXIT_SUCCESS);
}

