#include <stdio.h>
#include <math.h>
#include <omp.h>

/*
 * Desciption :
 * 		Ce programme est un petit programme de test avec OpenMP.
 *      Il permet de ...
 * Résultat :
 * 		Il affiche ...
 */

int main(){
    #pragma omp parallel num_threads(4)
    {
        foobar();
    }
}