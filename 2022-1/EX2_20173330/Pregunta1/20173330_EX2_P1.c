#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    printf("Ingrese la cantidad de palabras de ingreso:");
    scanf("%d",&N);
    char* cadena = (char*)malloc(100*sizeof(char));
    int cont = 0;
    for(int i=0;i<N;i++){
        int l;
        printf("Ingrese la cantida de letras de la palabra %d : ",i+1);
        scanf("%d",&l);
        char *cad;
        printf("Ingrese la palabra %d : ",i+1);
        for(int j=0;j<l;j++){
            scanf("%c",&cadena[cont+j]);
        }
        cont +=l;
    }
    cadena[cont] = '\0';
    
}