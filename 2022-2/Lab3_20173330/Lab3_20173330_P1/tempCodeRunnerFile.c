    //contador para llevar cuantos dias consecutivos va el menor peso y modo para ayudar a saber si iba contando consecutivos o no
    // e indice para poder guardar el ultimo indice en el que se tuvo el menor valor despues de romper una cadena de días consecutivos
    int contador=0,modo=0,indice;
    //recorro el arreglo buscando el menor peso y si lo encuentro cambia a modo 1 y empieza a contar cuantos dias se repite este numero
    //en caso se encuentre un numero diferente y ya he estado contando consecutivos calcula si el contador es mayor que la cantidad de dias 
    // consecutivos maxima anterior y copia el indice para su retorno
    for(int i=ini;i<=fin;i++){
        if(arr[i]==menor){
            modo=1;
            contador++;
        } else if(arr[i]!=menor && modo==1){
            if(contador>=(*dias_consecutivos)){
                (*dias_consecutivos)=contador;
                indice = i-1;
            }
            modo=0;
            contador=0;
        }
    }
    // para resolver el caso en que los dias consecutivos sean los ultimos del mes 
    // dado que en este caso no entraria en el else if y no me daria el resultado querido en caso salga del for sin actualizar 
    // los dias consecutivos ni el indice
    if(contador>=(*dias_consecutivos)){
        (*dias_consecutivos) == contador;
        indice=fin;
    } 
    return indice;