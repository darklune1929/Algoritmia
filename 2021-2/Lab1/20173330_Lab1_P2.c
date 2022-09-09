#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//Para la base de datos dada asi
/*
10000
4
6
1 3000 0.1
2 3800 0.02
3 2800 0.15
4 3500 0.05
5 3200 0.08
6 3400 0.03 */

const int MAX_Cli=16; //maximo de divisiones
const char *FILE_NAME="Datos_P2.txt";

typedef struct Cliente{
    int id;
    int acciones;
    double comision;
}TCliente;
void read_data(TCliente **Clients,int *T,int *P,int *N){
    int i;
    FILE *arch=fopen(FILE_NAME,"r");
    fscanf(arch,"%d %d %d",T,P,N);
    for(i=0;i<(*N);i++){
        Clients[i]=(TCliente *)malloc(sizeof(TCliente));
        fscanf(arch,"%d %d %lf",&(Clients[i]->id),&(Clients[i]->acciones),&(Clients[i]->comision));
        Clients[i]->comision*=(*P)*Clients[i]->acciones;
    }
    fclose(arch);
}
void fill_cromosome(int cromosome[],int N,int size){
    int i=size-1,j;
    while(N!=0){
        cromosome[i]=N%2;
        N/=2;
        i--;
    }
    for(j=0;j<=i;j++)
        cromosome[j]=0;
}
int is_valid(int cromosome[],int N,int T,TCliente **Clients){
    int i,suma_acciones=0;
    for(i=0;i<N;i++){
        suma_acciones+=cromosome[i]*Clients[i]->acciones;
        if(T<suma_acciones) return 0;
    }
    return 1;
}
void show_cromosome(int cromosome[],int N,TCliente **Clients){
    int i,acciones_total=0;
    double ganancia_total=0;
    for(i=0;i<N;i++){
        if(cromosome[i]){
        ganancia_total+=Clients[i]->comision;
        acciones_total+=Clients[i]->acciones;
        printf("El cliente %d otorga una ganancia de %.02lf dolares por comprar %d acciones\n",(Clients[i]->id),Clients[i]->comision,Clients[i]->acciones);
        }
    }
    printf("Ganancia por comision: %02lf con %d acciones",ganancia_total,acciones_total);
}
void fill_final(int cromosome[],int N,int final_cromosome[]){
    int i;
    for(i=0;i<N;i++){
        final_cromosome[i]=cromosome[i];
    }

}
int calcular_gain(int N,int cromosome[],TCliente **Clients){
    int i;
    double ganancia_total=0;
    for(i=0;i<N;i++){
        ganancia_total+=cromosome[i]*Clients[i]->comision;
    }
    return ganancia_total;
}
int main(){
    int N,P,T; 
    int i;
    TCliente *Clients[MAX_Cli]; 
    read_data(Clients,&T,&P,&N);
    printf("Los datos registrados son: T= %d P= %d N=%d\n",T,P,N);
    for(int i=0;i<N;i++) {
        printf(" Cliente %d: %d %.02lf\n",(Clients[i]->id),Clients[i]->acciones,Clients[i]->comision);
    }
    int lim=pow(2,N);
    int cromosome[N];
    int max_gain=0;
    int ganancia_total;
    int final_cromosome[N];
    //parte b
    for(i=0;i<lim;i++){
        fill_cromosome(cromosome,i,N);
        if(is_valid(cromosome,N,T,Clients)){
            ganancia_total=calcular_gain(N,cromosome,Clients);
            if(max_gain<=ganancia_total){
                max_gain=ganancia_total;
                fill_final(cromosome,N,final_cromosome);
            }
        }
    }
    show_cromosome(final_cromosome,N,Clients);
    printf("\n");
    for(i=0;i<lim;i++){
        fill_cromosome(cromosome,i,N);
        if(is_valid(cromosome,N,T,Clients)){
            ganancia_total=calcular_gain(N,cromosome,Clients);
            if(fabs(ganancia_total-max_gain)<1){
                max_gain=ganancia_total;
                show_cromosome(cromosome,N,Clients);
            }
        }
    }   
    return 0;
}
