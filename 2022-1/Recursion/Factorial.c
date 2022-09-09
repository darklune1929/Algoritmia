#include <stdio.h>

int factorial(int number);

int main() {
    int number;
    printf("Ingresar numero: ");
    scanf("%d",&number);
    
    int fnumber = factorial(number);
    printf("El factorial de %d es %d",number,fnumber);

    return 0;
}

int factorial(int number) {
    if ((number==0) || (number==1)) {
        return 1;
    }

    return number*factorial(number-1);
}