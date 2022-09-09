#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);
/* int fibonacci(int n,int* prevValues,int prevN); */

int main() {
    int n;
    printf("Ingresar numero: ");
    scanf("%d",&n);

    int result = fibonacci(n);
    printf("\nEl termino %d de la secuencia es: %d\n",n,result);

    int result2 = fibonacci(20); //??
    printf("\nEl termino %d de la secuencia es: %d",20,result2);

    return 0;
}

int fibonacci(int n) {
    int* sequence = (int*)malloc((n+1)*sizeof(int));
    sequence[0] = 0;
    sequence[1] = 1;
    for (int i=0;i<=n;i++) {
        if (i>=2) {
            sequence[i] = sequence[i-1]+sequence[i-2];
        }
        printf("%d ",sequence[i]);
    }

    return sequence[n];
}

int fibonacci(int n,int* prevValues,int prevN) {
    if (n<=prevN) {
        return prevValues[n];
    }

    // for() ...
}