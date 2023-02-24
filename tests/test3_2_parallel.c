#include <stdio.h>
#include <math.h>
#include <omp.h>

/*
 * Desciption :
 * 		Ce programme est un petit programme de test avec OpenMP.
 *      Il permet de créer un tableau de 100 éléments et de le remplir
 *      avec la fonction pooth en utilisant la directive #pragma omp parallel
 *      intégrant la clause num_threads.
 * Résultat :
 * 		Il affiche le tableau A rempli avec la fonction pooth.
 */

int main(){
    double A[100]
    
    #pragma omp parallel num_threads(4)
    {
        int ID = omp_get_thread_num();
        pooth(ID, A);
    }
}