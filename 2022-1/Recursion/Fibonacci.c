#include <stdio.h>

int fibonacci(int number);

int main() {
    int number;
    printf("Ingresar numero: ");
    scanf("%d",&number);
    
    int fnumber = fibonacci(number);
    printf("El termino %d de la serie Fibonacci es %d",number,fnumber);

    return 0;
}

int fibonacci(int number) {
    if (number==0) {
        return 0;
    } else if (number==1) {
        return 1;
    }

    return fibonacci(number-1)+fibonacci(number-2);
}