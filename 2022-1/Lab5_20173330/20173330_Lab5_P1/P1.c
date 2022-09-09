#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_solucion(char* solucion,int n,int* parent_izq,int* parent_der){
    printf("Solución: ");
    for(int i=0;i<n+1;i++){
        printf("%c",solucion[i]);
    }
}
int resolverCadena(char* cadena,char*solucion,int n,int longitud,int* parent_izq,int* parent_der){
	int i=0;
	if (n > longitud - 1) return;
	do {
		solucion[n] = i;
		if (is_valid(solucion, n,parent_izq,parent_der)){
			if (n == longitud - 1){
                strcpy(solucion,cadena);
				print_solucion(solucion, n,parent_izq,parent_der);
            }
			else
				resolverCadena(cadena,solucion, n+1,longitud,parent_izq,parent_der);
		}
		i++;
	} while (solucion[n] != 1);	
	solucion[n] = -1;
}
int main() {
    char cadena[50];
    char solucion[50];
    int longitud,parent_izq=0,parent_der=0;
    //se leen los datos
    printf("Ingrese la cadena de caracteres:");
    scanf("%s",cadena);
    longitud=strlen(cadena);
    for(int i=0;i<longitud;i++){
        printf("%c",cadena[i]);
    }
    if(resolverCadena(cadena,solucion,0,longitud,&parent_izq,&parent_der)){
        printf("Fin de programa");
    }
    return 0;
}