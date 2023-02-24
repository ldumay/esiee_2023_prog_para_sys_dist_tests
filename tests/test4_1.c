#include <stdio.h>
#include <math.h>
#include <omp.h>

/*
 * Desciption :
 * 		Ce programme est un petit programme de test.
 *      Il permet de ...
 * Résultat :
 * 		Il affiche ...
 */

void thunk(){
    foobar();
}

int main(){
    pthread_t tid[4];

    for(int 1 = 0; i < 4; i++){
        pthread_create(&tid[i], 0, thunk, 0);
    }

    thunk();

    for(int i = 0; i < 4; i++){
        pthread_join(tid[i]);
    }
}