/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: cueva
 *
 * Created on 17 de octubre de 2021, 11:14 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Colas.h"
/*
 * 
 */
int main(int argc, char** argv) {
    TCola ptrcola;
    
    crea_cola(&ptrcola);
    encolarp(&ptrcola,3,"Alex Valencia");
    encolarp(&ptrcola,2,"Rony Cueva");
    encolarp(&ptrcola,2,"Cesar Aguilera");
    encolarp(&ptrcola,1,"Miguel Guanira");
    encolarp(&ptrcola,3,"Sr Bartra");
    encolarp(&ptrcola,1,"Viktor K");
    encolarp(&ptrcola,2,"Prof. Bonito");
    
    
    imprimecola(ptrcola);
    
    
    TCola ptrcola2;
    
    crea_cola(&ptrcola2);
    encolar(&ptrcola2,31,"Alex Valencia");
    encolar(&ptrcola2,22,"Rony Cueva");
    encolar(&ptrcola2,23,"Cesar Aguilera");
    encolar(&ptrcola2,14,"Miguel Guanira");
    encolar(&ptrcola2,35,"Sr Bartra");
    encolar(&ptrcola2,16,"Viktor K");
    encolar(&ptrcola2,27,"Prof. Bonito");
    ordenacolarecp(&ptrcola2,7);
    
    imprimecola(ptrcola2);
    
    
    return (EXIT_SUCCESS);
}

