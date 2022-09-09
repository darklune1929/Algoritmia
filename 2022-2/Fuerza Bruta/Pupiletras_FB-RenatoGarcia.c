#include<stdio.h>
#include<stdlib.h>
#define MOV 8
#define M 5
//Renatto Garcia Arce
int mov[MOV][2];

void movimientos(){
	mov[0][0]=-1;mov[0][1]=-1;
	mov[1][0]=0	;mov[1][1]=-1;
	mov[2][0]=1	;mov[2][1]=-1;
	mov[3][0]=-1;mov[3][1]=0;
	mov[4][0]=1	;mov[4][1]=0;
	mov[5][0]=-1;mov[5][1]=1;
	mov[6][0]=0	;mov[6][1]=1;
	mov[7][0]=1	;mov[7][1]=1;
}
int encontrar_resto(char tablero[][M],int x,int y,char palabra[],char solucion[][M],int longitud){
	int i,k,nuevo_x,nuevo_y;
	int validar;
	for(i=0;i<MOV;i++){
		nuevo_x=x+mov[i][1];
		nuevo_y=y+mov[i][0];
		
		if(tablero[nuevo_x][nuevo_y]==palabra[1]){
			for(k=2;k<longitud;k++){
				nuevo_x+=mov[i][1];
				nuevo_y+=mov[i][0];
				
				if(tablero[nuevo_x][nuevo_y]==palabra[k] && nuevo_x<M && nuevo_y<M && nuevo_x>=0&&nuevo_x>=0){
					validar=1;
				}else{
					validar=0;
					break;
				}
			}
			if(validar){
				for(k=longitud-1;k>=0;k--){
						solucion[nuevo_x][nuevo_y]=tablero[nuevo_x][nuevo_y];
						nuevo_x-=mov[i][1];
						nuevo_y-=mov[i][0];
				}
				return validar;
			}
		}
	}
	return 0;
}
void resuelve_pupiletras(char tablero[][M],char palabra[],char solucion[][M],int longitud){
	printf("Impresion:\n");
	int i,j;
	for(i=0;i<M;i++)
		for(j=0;j<M;j++)
			if(tablero[i][j]==palabra[0])
				if(encontrar_resto(tablero,i,j,palabra,solucion,longitud))
					printf("Encontramos la palabra en la fila %d y en la columna %d\n",i+1,j+1);	
					
	for(i=0;i<M;i++){
		for(j=0;j<M;j++) printf("%c|",solucion[i][j]);
		printf("\n");
	}
}
int main(){
	char tablero[][M]={{'G','B','S','O','A'},
					{'E','H','S','O','L'},
					{'S','O','L','T','L'},
					{'Y','O','K','O','L'},
					{'S','O','L','O','S'}};
	char palabra[]={'S','O','L'};
	int longitud=3;
	char solucion[][M]={{'X','X','X','X','X'},
					{'X','X','X','X','X'},
					{'X','X','X','X','X'},
					{'X','X','X','X','X'},
					{'X','X','X','X','X'}};
	movimientos();
	resuelve_pupiletras(tablero,palabra,solucion,longitud);
	return 0;
}
