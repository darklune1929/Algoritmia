#include <stdio.h>
#include <stdlib.h>
const char *FILE_NAME="probando.txt";
typedef struct DayData{
    int dia;
    int cant;
    int *cod;
}TDayData;
void read_data(int *M,int *I,int *N,int *D,int *P,TDayData ***dias){
    int i,j;
    FILE *file = fopen(FILE_NAME,"r");
    fscanf(file,"%d %d %d %d %d",M,I,N,D,P);
    *dias=(TDayData **)malloc(sizeof(TDayData *)*(*D));
    for(i=0;i<*D;i++){
        (*dias)[i]=(TDayData *)malloc(sizeof(TDayData));
        fscanf(file,"%d",&((*dias)[i]->dia));
        (*dias)[i]->cant=*P;

        (*dias[i])->cod=(int *)malloc(sizeof(int)*(*P));
        for(j=0;j<*P;j++){
            fscanf(file,"%d",&(*dias)[j]->cod[j]);
        }
    }
    fclose(file);
}
int main(){
    int M,I,N,D,P;
    TDayData **dias;
    read_data(&M,&I,&N,&D,&P,&dias);
    printf("%d %d %d %d %d\n",M,I,N,D,P);
    return 0;
}