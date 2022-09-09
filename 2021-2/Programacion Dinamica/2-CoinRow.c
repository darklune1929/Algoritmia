#include <stdio.h>

int coin_row(int coins[], int n);

int main(){
	int coins[]= {5,1,2,10,6,2};
	int n = 6;
	
	int max_amount = coin_row(coins, n);
	printf("El monto máximo es %d.\n", max_amount);
	return 0;
}

int coin_row(int coins[], int n){
	int F[n+1];
	int i, max, aux1, aux2;
	
	F[0] = 0;
	F[1] = coins[0];
	
	
	for (i=2; i<=n; i++){
		aux1 = coins[i] + F[i-2];
		aux2 = F[i-1];
		if (aux1 > aux2) {
			max = aux1;	
		} else {
			max = aux2;
		}
		F[i] = max;
	}
	
	printf("\n");
	return F[n];
}
