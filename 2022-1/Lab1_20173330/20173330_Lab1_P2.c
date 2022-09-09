#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Course {
    char id[10];
    int credits;
    char horario[10];
    int sesionTeo;
    int horaIniTeo;
    int horaFinTeo;
    int sesionPrac;
    int horaIniPrac;
    int horaFinPrac;
    int evaluacion;
} Course;
//voy a leer los 10 datos por fila y almacenarlos en el arrelgo de cursos 
int readDataFromFile(int totalCourses,Course* cursos) {
    int readCourses = totalCourses;

    FILE* file = fopen("20221_Lab1_2.txt","r");
    for (int i=0;i<totalCourses;i++) {
        int assigned = fscanf(file,"%s %s %d %d %d %d %d %d %d %d\n",cursos[i].id,cursos[i].horario,&cursos[i].credits,
        &cursos[i].sesionTeo,&cursos[i].horaIniTeo,&cursos[i].horaFinTeo,&cursos[i].sesionPrac,&cursos[i].horaIniPrac,
        &cursos[i].horaFinPrac,&cursos[i].evaluacion);
        if (assigned<10) {
            readCourses = i;
            break;
        }
    }
    fclose(file);
    return readCourses;
}
// se llena el cromosoma con el numero
void fill_chromosome(int n, int totalCourses, int chromosome[]){
	int i=totalCourses-1,j;
	while ( n != 0) {
		chromosome[i] = n%2;
		n /= 2;
		i--;
	}
	for (j=0; j<=i; j++)
		chromosome[j] = 0;
}
int mismo_ID(Course* cursos,int i,int j){
    int valid = 1;
    for(int k=0;k<6;k++){
        if(cursos[i].id[k]!=cursos[j].id[k])  {
            valid = 0;
            break;
        }
    }
    return valid;
}
int hay_cruce(Course* cursos,int i,int j){
    int valid = 0;
    //chequeo cruces mediante el horario de inicio de cada uno asi como practica y teoria
    // asi viendo si esta entre el horario de inicio y fin del otro curso
    if(cursos[i].sesionTeo==cursos[j].sesionTeo){
        if(cursos[i].horaIniTeo<cursos[j].horaFinTeo && cursos[i].horaIniTeo> cursos[j].horaIniTeo) valid = 1;
        if(cursos[j].horaIniTeo<cursos[i].horaFinTeo && cursos[j].horaIniTeo> cursos[i].horaIniTeo) valid = 1;
    }
    if(cursos[i].sesionTeo==cursos[j].sesionPrac){
        if(cursos[i].horaIniTeo<cursos[j].horaFinPrac && cursos[i].horaIniTeo> cursos[j].horaIniPrac) valid = 1;
        if(cursos[j].horaIniPrac<cursos[i].horaFinTeo && cursos[j].horaIniPrac> cursos[i].horaIniTeo) valid = 1;        
    }
    if(cursos[j].sesionTeo==cursos[i].sesionPrac){
        if(cursos[j].horaIniTeo<cursos[i].horaFinPrac && cursos[j].horaIniTeo> cursos[i].horaIniPrac) valid = 1;
        if(cursos[i].horaIniPrac<cursos[j].horaFinTeo && cursos[i].horaIniPrac> cursos[j].horaIniTeo) valid = 1;
    }
    if(cursos[j].sesionPrac==cursos[i].sesionPrac){
        if(cursos[i].horaIniPrac<cursos[j].horaFinPrac && cursos[i].horaIniPrac> cursos[j].horaIniPrac) valid = 1;
        if(cursos[j].horaIniPrac<cursos[i].horaFinPrac && cursos[j].horaIniPrac> cursos[i].horaIniPrac) valid = 1;
    }
    return valid;
}
int is_valid(Course* cursos,int chromosome[],int totalCourses,int L){
    int total_credits=0,valid = 1;
    //probrando por cantidad de creditos
    for(int i=0;i<totalCourses;i++){
        if(chromosome[i]){
            total_credits += cursos[i].credits;
        }
    }
    if(total_credits > L || total_credits < 12) valid = 0;
    //probando cruces y mismo id
    for(int i=0;i<totalCourses-1;i++){
        if(chromosome[i]){
        for(int j=i+1;j<totalCourses;j++){
            if(chromosome[j]){
                if(mismo_ID(cursos,i,j)) valid = 0;            
                if(hay_cruce(cursos,i,j)) valid = 0;
            }
        }
        }
    }
    return valid;
}
void calc_credits(Course* cursos,int chromosome[],int totalCourses,int* total_credits){
    for(int i=0;i<totalCourses;i++){
        if(chromosome[i]){
            *total_credits += cursos[i].credits;
        }
    }    
}
void fill_final_chromosome(int totalCourses, int chromosome[], int final_chromosome[]) {
	int i;
	for (i=0; i<totalCourses; i++){
		final_chromosome[i] = chromosome[i];
	}
}
void imprimir_horario_y_curso(Course* cursos,int i){
    printf("*");
    for(int j=0;j<6;j++){
        printf("%c",cursos[i].id[j]);
    }
    printf("-");
    for(int k=0;k<4;k++){
        printf("%c",cursos[i].horario[k]);
    }
    printf("\n");
}
void show_final_chromosome(int final_chromosome[],Course* cursos,int totalCourses,int max_credits,int L){
    printf("\nEl horario que cumple con las condiciones (12<=C<=%d) \n",L);
    for(int i=0;i<totalCourses;i++){
        if(final_chromosome[i]){
            imprimir_horario_y_curso(cursos,i);
        }
    }
    printf("Total de creditos seleccionados: %d",max_credits);
}
void show_chromosome(int final_chromosome[],Course* cursos,int totalCourses,int max_credits,int L){
    printf("Una solucion al problema es: \n");
    for(int i=0;i<totalCourses;i++){
        if(final_chromosome[i]){
            imprimir_horario_y_curso(cursos,i);
        }
    }    
}
int main(){
    int L;
    printf("Ingrese la cantidad de creditos maximo que se quiere matricular: ");
    scanf("%d",&L);
    int totalCourses = 15;
    Course* cursos = (Course*)malloc(totalCourses*sizeof(Course));
    int readCourses = readDataFromFile(totalCourses,cursos);
    printf("Se han encontrado %d cursos",readCourses);
    int lim = pow(2,totalCourses);
	int chromosome[totalCourses];
	int final_chromosome[totalCourses];
    int total_credits=0;
    int max_credits=0;
    //parte b
    for(int i=0;i<lim;i++){
        fill_chromosome(i,totalCourses,chromosome);
        if(is_valid(cursos,chromosome,totalCourses,L)){
            total_credits=0;
            calc_credits(cursos,chromosome,totalCourses,&total_credits);
            if(total_credits>=max_credits){
                max_credits = total_credits;
                fill_final_chromosome(totalCourses, chromosome, final_chromosome);
            }
        }
    }
    show_final_chromosome(final_chromosome,cursos,totalCourses,max_credits,L);
    //parte c
    for(int i=0;i<lim;i++){
        fill_chromosome(i,totalCourses,chromosome);
        if(is_valid(cursos,chromosome,totalCourses,L)){
            total_credits=0;
            calc_credits(cursos,chromosome,totalCourses,&total_credits);
            if(total_credits==max_credits){
                fill_final_chromosome(totalCourses, chromosome, final_chromosome);
                show_chromosome(final_chromosome,cursos,totalCourses,max_credits,L);
            }
        }
    }
    printf("Total de creditos seleccionados: %d\n",max_credits);
}