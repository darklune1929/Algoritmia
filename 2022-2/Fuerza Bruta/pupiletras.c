#include <stdio.h>
#define MAXCOL 5
#define MAXFIL 4

int m[8][2];

void movimientos(){
	m[0][0]= -1;  m[0][1] =  -1;
	m[1][0]=  0;  m[1][1] = -1;
	m[2][0]=  1;  m[2][1] = -1;
	m[3][0]= -1;  m[3][1] =  0;
	m[4][0]=  1;  m[4][1] =  0;
	m[5][0]= -1;  m[5][1] =  1;
	m[6][0]=  0;  m[6][1] =  1;	
	m[7][0]=  1;  m[7][1] =  1;
}

void impresion_result(char result[][MAXCOL], 
	char palabra[], int row, int col, int m){
    int i, j;
    printf("\n");
    for(i=0; i<MAXFIL; i++){
        for(j=0; j<MAXCOL; j++){
            printf("| %c ", result[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

int  busca(char tabla[][MAXCOL],char resultado[][MAXCOL],
	char palabra[],int row,int col,int n){
		int i,j,k,l,s,nrow,ncol;
		if(tabla[row][col]!=palabra[0]) return 0;
				
		for(i=0;i<8;i++){ //buscando direccion
			nrow = row + m[i][0];
			ncol = col + m[i][1];
			for(j=1;j<n;j++){ //dentro de la palabra
				if(nrow>=MAXFIL || nrow <0 || ncol>=MAXCOL || ncol<0)
					break;
				if(tabla[nrow][ncol]!=palabra[j])
					break;		
				nrow = nrow + m[i][0];
				ncol = ncol + m[i][1];
			}
			if(j==n){
				for(k=0,l=0,s=0; s<n; k+=m[i][0],l+=m[i][1],s++)
					resultado[row+k][col+l] = palabra[s];
				return 1;
			}
		}
		return 0;
		
}


void pupiletras(char tabla[][MAXCOL],char palabra[],
	char resultado[][MAXCOL],int m){

int i,j;
	for(i=0;i<MAXFIL;i++)
		for(j=0;j<MAXCOL;j++)
			if(busca(tabla,resultado,palabra,i,j,m))
				printf("La palabra empieza: %d %d\n",i,j);	
	
	impresion_result(resultado,palabra,i,j,m);
}
	

int main(){
	int m = 3;
	char tabla[][MAXCOL]={
	{'G','B','S','O','P'},
	{'E','H','S','O','L'},
	{'S','O','L','O','L'},
	{'P','H','S','A','L'}
	};
	char resultado[][MAXCOL]={
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '}
	};
	
	char palabra[]={'S','O','L'};
	movimientos();
	pupiletras(tabla,palabra,resultado,m);
	
	
	
	return 0;	
}



