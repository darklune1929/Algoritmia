#include<stdio.h>

int coin_row(int coins[], int n) {
	int F[n+1], aux1;

	F[0] = 0;
	F[1] = coins[0];

	for (int i=2; i<=n; i++){
		aux1 = coins[i-1] + F[i-2];
		F[i] = aux1 > F[i-1] ? aux1 : F[i-1];
	}
	return F[n];
}

int main(){
	int coins[] = {5,1,2,10,6,2};
	int n=6;
	int max_amount = coin_row(coins, n);
	printf("El monto máximo es %d.\n", max_amount);
	return 0;
}