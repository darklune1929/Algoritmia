/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ALEJANDRO
 *
 * Created on 6 de mayo de 2022, 04:17 PM
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Meteorito{
    int valor;
    int x;
    int y;
    int z;
}Meteorito;

int binary_search(Meteorito *, int, int, int);
void MergeSort(int,int,Meteorito*);
void merge(int ,int ,int ,Meteorito*);

int main(int argc, char** argv) {
    
    // L, W, H
    int x, y, z;
    FILE *arch;
    
    arch = fopen("datos.txt", "r");
    if(arch == NULL){
        printf("Error en datos.txt\n");
        exit(1);
    }
    
    fscanf(arch,"%d %d %d", &x, &y, &z);
    
    Meteorito **meteorito = (Meteorito**)malloc(y*z*sizeof(Meteorito*));
    
    int posicion_x=1, posicion_y=1, posicion_z=1;
    
    for(int i=0;i<y*z;i++){
        meteorito[i] = (Meteorito*)malloc(x*sizeof(Meteorito));
        posicion_x=1;
        for(int j=0;j<x;j++){
            fscanf(arch, "%d", &meteorito[i][j].valor);
            meteorito[i][j].x=posicion_x;
            meteorito[i][j].y=posicion_y;
            meteorito[i][j].z=posicion_z;
            posicion_x++;
        }
        posicion_y++;
        if(posicion_y>y){
            posicion_y=1;
            posicion_z++;
        }
    }
    
    printf("%d %d %d\n", x, y, z);
    for(int i=0;i<y*z;i++){
        for(int j=0;j<x;j++){
            //printf("%d %d", meteorito[i][j].x, meteorito[i][j].y);
            //printf("%d %d\n", meteorito[i][j].z, meteorito[i][j].valor);
            printf("%d ", meteorito[i][j].valor);
        }
        printf("\n");
        if((i+1)%y==0){
            printf("---------\n");
        }
    }
    
    int i, posicion;
    
    for(i=0;i<y*z;i++){
        MergeSort(0, x-1, meteorito[i]);
        posicion = binary_search(meteorito[i], 1, 0, x-1);
        if(posicion!=-1)break;
        posicion_y++;
        if(posicion_y==y){
            posicion_y=0;
            posicion_z++;
        }
    }
    
    printf("Posición del cubo de vibranio: (%d,%d,%d)\n", 
            meteorito[i][posicion].x,meteorito[i][posicion].y, 
            meteorito[i][posicion].z);
    printf("Dinero invertido en cortes (en millones de USD): %d\n", i+1);
    
    free(meteorito);
    fclose(arch);
    
    return (EXIT_SUCCESS);
}

int binary_search(Meteorito *arr, int value, int ini, int end){
    if (ini > end) return -1;
    
    int med = (ini + end) / 2;
    
    if (arr[med].valor == value) return med;
    else if (arr[med].valor < value) 
        return binary_search(arr, value, med + 1, end);
    else 
        return binary_search(arr, value, ini, med-1);	
}

void MergeSort(int startPos,int endPos,Meteorito* array){
    if (startPos>=endPos)return;
    int midPos = (startPos+endPos)/2;
    
    MergeSort(startPos,midPos,array);
    MergeSort(midPos+1,endPos,array);
    merge(startPos,midPos,endPos,array);
}

void merge(int startPos,int midPos,int endPos,Meteorito* array) {
    int size1 = midPos-startPos+1;
    int size2 = endPos-midPos;

    Meteorito* array1 = (Meteorito*)malloc((size1+1)*sizeof(Meteorito));
    for (int i=0;i<size1;i++) {
        array1[i] = array[startPos+i];
    }

    Meteorito* array2 = (Meteorito*)malloc((size2+1)*sizeof(Meteorito));
    for (int i=0;i<size2;i++) {
        array2[i] = array[midPos+i+1];
    }

    int i = 0, j = 0;
    array1[size1].valor = array2[size2].valor = 9999999;
    for (int k=startPos; k <= endPos; k++){
        if (array1[i].valor<array2[j].valor){
            array[k] = array1[i++];
        }
        else{
            array[k] = array2[j++]; 
        }
    }

    free(array1);
    free(array2);
}
