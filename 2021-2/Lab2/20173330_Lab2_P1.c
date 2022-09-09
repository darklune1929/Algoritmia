#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//creación de estructuras para el problema
const char *FILE_NAME="Datos_P1.txt";
typedef struct TConsData{
    char empresa;
    int costo;
}TCons;
typedef struct TFaseData{    
    int fase;
    int porcentaje;
    TCons *consultoras;
    int orden;
    int cantidad;
}TFase;

void read_data(int *P,int *NF,int *N,TFase ***fases){
//leer los datos mediante triple puntero a las fases apara asi reservar memoria dependiendo del numero de fases leido
// e ir reservando espacio para cada cantidad de empresas
    FILE *file=fopen(FILE_NAME,"r");
    fscanf(file,"%d %d %d",P,NF,N);
    (*fases)=(TFase **)malloc(sizeof(TFase *)*(*NF));
    for(int i=0;i<(*NF);i++){
        (*fases)[i]=(TFase *)malloc(sizeof(TFase));
        fscanf(file,"%d %d",&((*fases)[i]->fase),&((*fases)[i]->porcentaje));
        (*fases)[i]->consultoras=(TCons *)malloc(sizeof(TCons)*(*N));
        for(int j=0;j<(*N);j++){
            (*fases)[i]->consultoras[j].empresa='A'+j;
            fscanf(file,"%d",&((*fases)[i]->consultoras[j].costo));
        }
        fscanf(file,"%d %d",&((*fases)[i]->orden),&((*fases)[i]->cantidad));
    }
    fclose(file);
}
int min_index(TCons *consultoras,int ini,int end){
	int min,val;
	if(ini==end) return ini;
	min=ini;
	val=min_index(consultoras,ini+1,end);
	if(consultoras[min].costo < consultoras[val].costo) return min;
	else return val;
}
void asc_sort(TCons *consultoras,int ini,int end ){
	int min;
	TCons aux;
	if (ini >= end) return;
	min = min_index(consultoras,ini,end);
    aux.empresa=consultoras[ini].empresa;
	consultoras[ini].empresa= consultoras[min].empresa;
	consultoras[min].empresa = aux.empresa;

	aux.costo=consultoras[ini].costo;
	consultoras[ini].costo= consultoras[min].costo;
	consultoras[min].costo = aux.costo;
	asc_sort(consultoras, ini+1, end);
}
int Max_index(TCons *consultoras,int ini,int end){
	int max,val;
	if(ini==end) return ini;
	max=ini;
	val=Max_index(consultoras,ini+1,end);
	if(consultoras[max].costo>consultoras[val].costo) return max;
	else return val;
}
void desc_sort(TCons *consultoras,int ini,int end ){
	int max;
	TCons aux;
	if (ini >= end) return;
	max = Max_index(consultoras,ini,end);
    aux.empresa=consultoras[ini].empresa;
	consultoras[ini].empresa= consultoras[max].empresa;
	consultoras[max].empresa = aux.empresa;
	aux.costo=consultoras[ini].costo;
	consultoras[ini].costo= consultoras[max].costo;
	consultoras[max].costo = aux.costo;
	desc_sort(consultoras, ini+1, end);
}
//lo puse en comentarios porque no funcionaba como esperaba el calculo de costo real y falta arreglar un poco para que seleccione
//si es que puede comprar el que sigue o no
int calcular_costo_real(TFase **fases,int ini,int end,int contador,int n_fase,int presupuesto_total,int N){
    int total;
    if(contador==end || ini==N) return 0;
    printf("%d",total);
    if(fases[n_fase]->consultoras[ini].costo<=presupuesto_total){
        contador++;
        printf("%c ",fases[n_fase]->consultoras[ini].empresa);
        presupuesto_total-=fases[n_fase]->consultoras[ini].costo;
        calcular_costo_real(fases,ini+1,end,contador,n_fase,presupuesto_total,N);
    } else{
        calcular_costo_real(fases,ini+1,end,contador,n_fase,presupuesto_total,N);
    }//por calcular el acumulador de costo_total
    return total;
}
void elegir_consultoras(int P,int NF,int N,int n_fase,TFase **fases,int ahorro_total){
    int costo_real=0,monto_destinado,presupuesto_total;
    if(fases[n_fase-1]->orden) asc_sort(fases[n_fase-1]->consultoras,0,N-1);//ordeno las filas de consultoras de acuerdo al costo//
    else desc_sort(fases[n_fase-1]->consultoras,0,N-1);
    for(int i=0;i<N;i++)
        printf(" %d %c ",fases[n_fase-1]->consultoras[i].costo,fases[n_fase-1]->consultoras[i].empresa);
    monto_destinado=P*(fases[n_fase-1]->porcentaje)/100;
    printf("Fase %d:  ",fases[n_fase-1]->fase);
    printf("Monto destinado: %d ",monto_destinado);
    presupuesto_total=monto_destinado+ahorro_total;
    printf("Consultoras elegidas: ");
    costo_real+=calcular_costo_real(fases,0,fases[n_fase-1]->cantidad,0,n_fase-1,presupuesto_total,N);
    /*for(int i=0;i<fases[n_fase-1]->cantidad;i++){
        costo_real+=fases[n_fase-1]->consultoras[i].costo;
        printf("%c ",fases[n_fase-1]->consultoras[i].empresa);
    }*/
    ahorro_total=presupuesto_total-costo_real;
    printf(" %d %d",costo_real,ahorro_total);
    printf("\n");
    elegir_consultoras(P,NF,N,n_fase+1,fases,ahorro_total);
}

int main(){
    int P,NF,N,n_fase=1;
    TFase **fases;
    read_data(&P,&NF,&N,&fases);
    //printf("%d %c",fases[1]->consultoras[3].costo,fases[1]->consultoras[3].empresa); Probando lectura//
    elegir_consultoras(P,NF,N,n_fase,fases,0);
    return 0;
}