#include <stdio.h>
#include <omp.h>

/*
 * Desciption :
 * 		Ce programme est un petit programme de test avec OpenMP.
 *      Il permet d'utiliser la directive #pragma omp parallel.
 * Résultat :
 * 		Il affiche "hello(0)world(0)".
 */


int main(){
    #pragma omp parallel
    {
        int ID = 4;
        printf("hello(%d)", ID);
        printf("world(%d)\n", ID);
    }
}