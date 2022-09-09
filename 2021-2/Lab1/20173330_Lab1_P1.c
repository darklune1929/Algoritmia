#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//Para la base de datos dada asi
/*
4 Hileras
23 Peso Maximo
7 10 17 10 14 10 19 5  (Peso Precio) de cada producto por hilera
9 15 12 10 11 10 8 10
8 10 6 20 10 10 12 5
18 10 7 10 15 5 11 10*/

const int MAX_DIV=4; //maximo de divisiones
const char *FILE_NAME="Datos_P1.txt";

typedef struct Product{
    int peso;
    int precio;
    char lado;
    char AB;
} TProduct;
void read_data(TProduct **Products,int *N,int *P){
    int i,j,k; // divido j y k entre n para ver en que lado y en que hilera a o b estan
    FILE *arch=fopen(FILE_NAME,"r");
    fscanf(arch,"%d %d",N,P);
    for(i=0;i<((*N)*4);i++){
        j=i/((*N)*2);
        k=i/(*N);
        Products[i]=(TProduct *)malloc(sizeof(TProduct));
        fscanf(arch,"%d %d",&(Products[i]->peso),&(Products[i]->precio));
        if(j==0) (Products[i]->lado)='I';
        if(j==1) (Products[i]->lado)='D';
        if(k==0 || k==2) (Products[i]->AB)='A';
        if(k==1 || k==3) (Products[i]->AB)='B';
        if(feof(arch)) break;
    }
    fclose(arch);
}
void fill_cromosome(int cromosome[],int i,int N){
    int j=(4*N)-1;
    int k;
    while(j!=0){
        cromosome[j]=i%2;
        i/=2;
        j--;
    }
    for(k=0;k<=j;k++)
        cromosome[k]=0;
}
int is_valid(int cromosome[],int N,int P,TProduct **Products){
    int i,suma_pesos=0;
    for(i=0;i<N*4;i++){
        suma_pesos+=cromosome[i]*Products[i]->peso;
        if(P<suma_pesos) return 0;
    }
    if(suma_pesos==P) return 1;
    if(suma_pesos<P) return 0;
}
void show_cromosome(int cromosome[],int N,int P,TProduct **Products,int cont){
    int i;
    printf("Resultado %d: ",cont);
    for(i=0;i<4*N;i++){
        
        if(cromosome[i]){
            printf("%dk ",Products[i]->peso);
            cont++;
        }
    }
    printf("Ubicaciones: ");
    for(i=0;i<4*N;i++){
        if(cromosome[i]){
            printf("%c%c%d ",Products[i]->lado,Products[i]->AB,(i%N)+1);
        }
    }
    printf("\n");
}
int is_validC(int cromosome[],int N,int P,TProduct **Products){
    int i,suma_pesos=0;
    for(i=0;i<N*4;i++){
        suma_pesos+=cromosome[i]*Products[i]->peso;
        if(P<suma_pesos) return 0;
    }
    return 1;
}
int calculated_gain(int cromosome[],int N,TProduct **Products){
    int i,ganancia=0;
    for(i=0;i<N*4;i++){
        ganancia+=cromosome[i]*Products[i]->precio;
    }
    return ganancia;
}
void fill_final(int cromosome[],int N,int final_cromosome[]){
    int i;
    for(i=0;i<N*4;i++){
        final_cromosome[i]=cromosome[i];
    }

}
int main(){
    int N,P; //N es Hileras y P Peso pedido
    TProduct *Products[MAX_DIV*4]; 
    read_data(Products,&N,&P);
    printf("Los datos registrados son: N= %d P= %d \n",N,P);
    for(int j=0;j<4*N;j++) {
        printf(" Producto %d: %d %d %c %c\n",j+1,Products[j]->peso,Products[j]->precio,Products[j]->lado,Products[j]->AB);
    }
    int lim=pow(2,4*N); // siempre son 4 hileras lo que cambia es el N
    int cromosome[4*N];
    int max_gain=0;
    int i,cont=0;
    int ganancia_total;
    int final_cromosome[4*N];
    //parte b
    for(i=0;i<lim;i++){
        fill_cromosome(cromosome,i,N);
        if(is_valid(cromosome,N,P,Products))  {
            cont++;
            show_cromosome(cromosome,N,P,Products,cont);
        }
    }
    //parte c
    for(i=0;i<lim;i++){
        fill_cromosome(cromosome,i,N);
        if(is_validC(cromosome,N,P,Products))  {
            ganancia_total=calculated_gain(cromosome,N,Products);
            if(max_gain<ganancia_total){
                fill_final(cromosome,N,final_cromosome);
                max_gain=ganancia_total;
            } 
        }
    }
    cont=1;
    printf("La mayor ganancia es %d\n",max_gain);
    show_cromosome(final_cromosome,N,P,Products,cont);
    return 0;
}
//no logre acabar sinceramente no se porque no pasa del fill_cromosome