#include <stdio.h>
#define M 9
#define N 7
/*Revisemos solo horizontal y vertical*/
			            //1 2 3 4 5 6 7 8 9
    int cuadro[N][M] =  {{0,0,0,0,0,0,0,0,0},//1
                         {0,0,0,0,0,0,0,0,0},//2
                         {0,0,0,0,0,0,0,0,0},//3
                         {0,0,0,0,0,0,0,0,0},//4
                         {0,0,0,0,0,0,0,0,0},//5
                         {0,0,0,0,0,0,0,0,0},//6
                         {0,0,0,0,0,0,0,0,0}};//7




int calcular_cluster(int x,int y,int tablero[][M]){
  int arriba=0,abajo=0,derecha=0,izquierda=0;
  
  if(tablero[x][y]==0 || cuadro[x][y]==1) 
  	return 0;
  if(x==N && y==M) return 0;
  
  cuadro[x][y]=1;
  
  if(x+1<N)
  	abajo = calcular_cluster(x+1,y,tablero);
  if(x-1>=0)
  	arriba = calcular_cluster(x-1,y,tablero);
  if(y+1<M)
  	derecha = calcular_cluster(x,y+1,tablero);
  if(y-1>=0)
  	izquierda = calcular_cluster(x,y-1,tablero);
    
	
	return derecha+izquierda+abajo+arriba+1;    
}

int main(){             //1 2 3 4 5 6 7 8 9
    int tablero[N][M] = {{0,0,0,0,0,0,0,0,0},//1
                         {1,0,0,1,0,0,0,1,0},//2
                         {0,1,0,0,0,0,0,1,0},//3
                         {0,1,0,0,0,1,0,1,0},//4
                         {0,1,0,0,0,0,1,1,0},//5
                         {0,1,1,1,0,0,0,1,1},//6
                         {0,0,0,0,0,0,0,1,1}};//7
    int x,y;
    printf("Ingrese una coordenada: ");
    scanf("%d %d",&x,&y);
    printf("El tamano del cluster es: %d\n",
		calcular_cluster(x-1,y-1,tablero));
    return 0;
}
