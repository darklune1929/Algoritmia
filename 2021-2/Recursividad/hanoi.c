#include <stdio.h>
void hanoi(int n,char tA,char tB,char tC){
    if(n==0) return;
    hanoi(n-1,tA,tC,tB);
    printf("Mover un disco de %c a %c N: %d \n",tA,tC,n);
    hanoi(n-1,tB,tA,tC);

}

int main(){
    hanoi(3,'A','B','C');
    return 0;
}
