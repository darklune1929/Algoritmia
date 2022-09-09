#include <stdio.h>
int print_binary(int n){
    if(n!=0){
        print_binary(n/2);
        printf("%d",n%2);
    }

}

int main(){
    int num;
    printf("Ingrese un numero: ");
    scanf("%d",&num);

    print_binary(num);
    printf("\n");
    return 0;
}