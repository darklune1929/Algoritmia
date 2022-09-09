#include <stdio.h>
#include <stdlib.h>
void imprimir_char(char* cars,int cant,int counter){
    //tenia un poco de tiempo asi que hice la impresion recursiva
    if(cant==counter) return;
    printf("%s",cars);
    imprimir_char(cars,cant,counter+1);
    return;
}
void llenar_bahia(int N,int M,int A,int colocar,int entrada,int posicion,int asc,int contador){
    //casos de retorno
    // en caso se quiera poner una segunda bahia pero esta este en la ultima posicion permitida
    // se devuelve el programa dado que esto no esta permitido
    if(posicion==A-1 && contador==1) return;
    // en caso se quiera colocar una bahia que exceda el largo maximo permitido
    if(colocar>M && entrada!=posicion) return;
    // en caso se haya salido del ancho del puerto
    if(posicion==A) return;
    // entrada empieza en 0 y se repite cada 2 bahias por lo tanto al agregarle 3 puedo saber donde
    // deberia ir la siguiente bahia, además me sirve para resetear el contador de bahias consecutivas puestas
    if(entrada==posicion){
        printf("Entrada");
        entrada+=3;
        contador=0;
    }else{
        // imprime la cantidad de * que lleva la variable colocar caso aun quede espacio y no sea el tercero consecutivo
        // y aumenta el contador de bahias consecutivas
        imprimir_char("* ",colocar,0);
        //     for(int i=0;i<colocar;i++) printf("* ");
        // en caso no funcione la impresion recursiva usar esto porfa
        contador++;
    }
    printf("\n");
    // variable asc me permite saber en que momento mi recursion en vez de disminuir el largo, va aumentar
    // esto sera cuando el numero de * a colocar sea igual al minimo de largo permitido N
    if(N==colocar){
        asc=1;
    }
    // usando la variable contador que cuenta la cantidad de bahias consecutivas puestas hasta el momento
    // podre saber si aumentar,disminuir o dejar intacto la cantidad de * a poner en la siguiente iteracion
    if(contador==2){
        if(asc){
            llenar_bahia(N,M,A,colocar+1,entrada,posicion+1,asc,contador);
        } else{
            llenar_bahia(N,M,A,colocar-1,entrada,posicion+1,asc,contador);
        }
    } else{
            llenar_bahia(N,M,A,colocar,entrada,posicion+1,asc,contador);   
    }
    // siempre aumento en 1 la posicion para poder llevar cuenta del espacio usado por las bahias y entradas

    return;
}
int main(){
    int N,M,A,colocar,asc=0,limit=28,entrada=0,posicion=0,contador=0;
    //lectura de datos
    printf("Ingrese los datos N, M y A:");
    scanf("%d %d %d",&N,&M,&A);
    printf("Para N=%d M=%d A=%d\n",N,M,A);
    for(int i=0;i<limit;i++){
        printf("=");
    }
    printf("\n");
    colocar = M;
    //funcion recursiva
    llenar_bahia(N,M,A,colocar,entrada,posicion,asc,contador);
    for(int i=0;i<limit;i++){
        printf("=");
    }
    return 0;
}