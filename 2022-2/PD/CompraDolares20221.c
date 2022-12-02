
#include <limits.h>
#include <stdio.h>

int max(int a,int b){
    if (a>b) return a;
    return b;
    
}

int maxganancia(int precios[], int n, int k)
{ int i,j,m;

  int ganancia[k + 1][n + 1];

  for (i = 0; i <= k; i++)
    ganancia[i][0] = 0;


  for ( j = 0; j <= n; j++)
    ganancia[0][j] = 0;

  for ( i = 1; i <= k; i++) {
    for ( j = 1; j < n; j++) {
      int maximo = INT_MIN;

      for ( m = 0; m < j; m++)
        maximo = max(maximo,
                precios[j] - precios[m] + ganancia[i - 1][m]);

      ganancia[i][j] = max(ganancia[i][j - 1], maximo);
      printf(" %3.0d ",ganancia[i][j]);
    }
    printf("\n");
  }


  return ganancia[k][n - 1];
}

int main()
{
  int k = 3;
  int precios[] = { 315, 322, 385, 375, 365, 380 };
  int n = sizeof(precios) / sizeof(precios[0]);

	printf("El maxima ganancia es:%d",maxganancia(precios, n, k));

  return 0;
}











