#include <stdio.h>
#include <stdlib.h>
#define LG 4
#define WG 3
#define HG 2
int calc_peso(int ini,int fin,int meteorito[LG][WG][HG],int max,int eje,int maxeje1,int maxeje2){
    int cont=0;
    int ejebus=ini;
    //estoy calculando de acuerdo al eje seleccionado en los parametros sumando todos los 0 además del 1 donde esta el vibranium
    for(int eje1=0;eje1<maxeje1;eje1++){
        for(int eje2=0;eje2<maxeje2;eje2++){
            for( ejebus=ini;ejebus<=fin;ejebus++){
                if(eje==0){
                    cont += meteorito[ejebus][eje1][eje2];
                    } else if(eje==1){
                    cont += meteorito[eje1][ejebus][eje2];
                    } else {
                    cont += meteorito[eje1][eje2][ejebus];
                    }
            }   
        }
    }
    return cont;
}
int buscarVibranium(int ini,int fin,int meteorito[LG][WG][HG],int *cortes,int max,int maxeje1,int maxeje2,int eje){
    //dado que solo hay un cubo de 1 x 1 x 1 de vibranium acabare cuando encuentre la hilera de dimension respectiva
    //que lo contenga
    if (ini==fin) {
        return ini;
    }
    int currentMidPos = (ini+fin)/2;
    //izquierdo y derecho hacen referencia que al momento de cortar sin importar el eje si lo ves desde ese eje 
    // se tiene un lado izquiero y uno derecho
    int peso_izq = calc_peso(ini,currentMidPos,meteorito,max,eje,maxeje1,maxeje2);
    int peso_der = calc_peso(currentMidPos+1,fin,meteorito,max,eje,maxeje1,maxeje2);
    //printf("%d %d",peso_izq,peso_der);
    //printf("%d",eje);

    //incremento la cantidad de cortes cada vez que pasa por aca asi llevando cuenta de esto
    (*cortes)++;
    if (peso_izq>peso_der) {
        return buscarVibranium(ini,currentMidPos,meteorito,cortes,max,maxeje1,maxeje2,eje);
    } else{
        return buscarVibranium(currentMidPos+1,fin,meteorito,cortes,max,maxeje1,maxeje2,eje);
    }
    //printf("%d",*(cortes));

}
int main(){
    int L,W,H;
    int cortes=0;
    printf("Ingrese L,W,H:");
    scanf("%d %d %d",&L,&W,&H);
    int meteorito[L][W][H];
    printf("Ingrese los datos del meteorito:");
    for(int k=0;k<H;k++){
        for(int j=0;j<W;j++){
            for(int i=0;i<L;i++){
                scanf("%d",&meteorito[i][j][k]);
            }
        }
    }
    /*for(int k=0;k<H;k++){
        for(int j=0;j<W;j++){
            printf("\n");
            for(int i=0;i<L;i++){
                printf("%d ",meteorito[i][j][k]);
            }
        }
        printf("\n");
        printf("===========");
    }*/
    //busco la posicion en cada eje en la que se encuentre la "linea" más pesada donde se encuentre el vibranium
    // dando como parametros en donde deberia empezar a buscar y donde acabe, los datos del meteorito, la direccion de memoria
    //para contar los cortes además de los maximos de todos los ejes y por ultimo una variable que me dice en que eje estoy buscando
    // para que en  la funcion de calcular peso no tener que hacer un triple for por cada eje.
    int posx = buscarVibranium(0,L-1,meteorito,&cortes,L,W,H,0);
    int posy = buscarVibranium(0,W-1,meteorito,&cortes,W,L,H,1);
    //el programa tiene un problema al calcular z dado que solo son 2 filas z al entrar en la funcion
    //calc_peso no entra al ultimo for dado que ini seria 0 y fin tambien seria 0 por como esta la logica
    // se arregla con cambiar H-1 por H pero asi no tendria logica para el resto de casos
    int posz = buscarVibranium(0,H-1,meteorito,&cortes,H,L,W,2);
    printf("Posicion del cubo de vibranio: (%d,%d,%d)\n",posx,posy,posz);
    // tampoco sé porque no esta sumando la cantidad de cortes aunque paso la direccion de memoria para poder modificarlo
    //en la funcion principal de buscarVibranium
    printf("Dinero invertido en cortes (en millones de USD): %d\n",cortes); 
    return 0;
}
