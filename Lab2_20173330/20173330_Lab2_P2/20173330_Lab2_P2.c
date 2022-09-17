#include <stdio.h>
#include <stdlib.h>
#define menor(x,y) (y>x)? x:y
/* no se porque se saltea la segunda columna cuando quiero llenar la cantidad de pasos*/
void contarPasos(char** campo,int** resultado,int posx,int posy,int* move_x,int* move_y,int n,int m){
    if(campo[posx][posy]=='*') return;
    if(posx>=n || posy>=m) return;
    if((posx-1)>=0 && (posy-1)>=0){
        resultado[posx][posy] = menor(resultado[posx-1][posy-1],menor(resultado[posx-1][posy],resultado[posx][posy-1]))+1;
    }else if((posx-1)>=0){
        resultado[posx][posy] = resultado[posx-1][posy] + 1;
    }else if((posy-1)>=0){
        resultado[posx][posy] = resultado[posx][posy-1] + 1;
    } else {
    }
    if(posx==(n-1) && posy==(m-1)) {
        return;
    }
    int nextx,nexty;
    for(int i=0;i<3;i++){
        nextx = posx + move_x[i];
        nexty = posy + move_y[i];
        contarPasos(campo,resultado,nextx,nexty,move_x,move_y,n,m);
    }
}
int main(){
    int n,m;
    printf("Ingrese las variables n y m: ");
    scanf("%d %d",&n,&m);
    char **campo = (char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++){
        campo[i] = (char*)malloc(sizeof(char)*m);
        for(int j=0;j<m;j++){
            scanf(" %c",&(campo[i][j]));
        }
    }
    printf("\nDatos del campo:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%c ",campo[i][j]);
        }
        printf("\n");
    }
    int **resultado = (int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        resultado[i] = (int*)malloc(sizeof(int)*m);
        for(int j=0;j<m;j++){
            resultado[i][j] = 0;
        }
    }
    int move_x[3] = {1,1,0};
    int move_y[3] = {0,1,1};
    for(int i=0;i<n;i++){
        if(campo[i][0]=='*') break;
        resultado[i][0] = i;
    }
        
    for(int i=0;i<m;i++){
        if(campo[0][i]=='*') break;
        resultado[0][i] = i;
    }

    contarPasos(campo,resultado,0,0,move_x,move_y,n,m);
    printf("La minima cantidad de paso a dar es: %d\n",resultado[n-1][m-1]);
    printf("\nDatos del resultado:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",resultado[i][j]);
        }
        printf("\n");
    }
    return 0;
}
    