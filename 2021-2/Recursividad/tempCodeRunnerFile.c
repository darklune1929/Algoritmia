void hanoi(int N,char A,char B,char C){
    if(N == 0)return ;

    hanoi(N-1,A,B,C);
    printf("Mover de %c a %c N=%d\n",A,B,N);
    hanoi(N-1,C,B,A);
    printf("Mover de %c a %c N=%d\n",B,C,N);
    hanoi(N-1,A,B,C);

}

int main(){
    hanoi(2,'A','B','C');
    return 0;
}