#include <stdio.h>
#define N 6
#define M 6

int robot_almacenero(int alm[N][M],int p,int q){
	int sol[p][q];
	sol[0][0] = alm[0][0];
	
	int i,j;
	for(i=1;i<p;i++)
		sol[i][0] = sol[i-1][0]+alm[i][0];
	for(i=1;i<q;i++)
		sol[0][i] = sol[0][i-1]+alm[0][i];
		
	int iz,ar;
	for(i=1;i<p;i++)
		for(j=1;j<q;j++){
			ar = sol[i-1][j]+alm[i][j];
			iz = sol[i][j-1]+alm[i][j];
			if(ar>=iz) sol[i][j] = ar;
			else sol[i][j]=iz;
		}
	
	for(i=0;i<p;i++){
		for(j=0;j<q;j++)
			printf("%02d ",sol[i][j]);
		printf("\n");
	}
	
	return sol[p-1][q-1];
}

int main(){
	int alm[N][M] = {{1,2,9,1,2,3},
					 {5,1,7,1,2,1},
					 {1,7,1,3,8,1},
					 {2,2,6,1,2,2},
					 {3,6,9,5,1,5},
					 {1,1,4,1,9,1}};
	
	int p = 2,q = 3;
	printf("Si el area es p=%d y q=%d \n",p,q);
	printf("La solucion es de %d \n\n\n",robot_almacenero(alm,p,q));
	p = 3;
	q = 3;
	printf("Si el area es p=%d y q=%d \n",p,q);
	printf("La solucion es de %d \n\n\n",robot_almacenero(alm,p,q));
	p = 6;
	q = 6;
	printf("Si el area es p=%d y q=%d \n",p,q);
	printf("La solucion es de %d \n\n\n",robot_almacenero(alm,p,q));
	
	return 0;
}








