#include <stdio.h>
#include <stdlib.h>
void printf_direccion_ip(int contador,char *cadena_aux){
    for(int i=0;i<contador;i++)
        printf("%c",cadena_aux[i]);
}
void direccion_ip_BT(char *cadena_numeros,int i,char *cadena_aux,int contador){
    if(contador==i+3){
        printf_direccion_ip(contador,cadena_aux);
    }
    do{
        if(is_valid(cadena_aux,i,contador)){

        }

    }while(cadena_numeros[contador]!='\0');
}
int main(){
    char cadena_numeros[100],cadena_aux[100];
    printf("Ingrese la cadena de numeros que desee utilizar: ");
    scanf("%s",cadena_numeros);
    int i=0;
    printf("La cadena ingresada es: ");
    while(cadena_numeros[i]!='\0'){
        printf("%c",cadena_numeros[i]);
        i++;
    }
    //i siendo la longitud de la cadena de caracteres
    direccion_ip_BT(cadena_numeros,i,cadena_aux,0);
    return 0;
}