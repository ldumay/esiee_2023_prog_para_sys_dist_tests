#include <stdio.h>
#include <math.h>
#include <omp.h>

/*
 * Desciption :
 * 		Ce programme est un petit programme de test avec OpenMP.
 *      Il permet de créer un tableau de 100 éléments et de le remplir
 *     avec la fonction pooth en utilisant la directive #pragma omp parallel.
 * Résultat :
 * 		Il affiche le tableau A rempli avec la fonction pooth.
 */

int main(){
    double A[100]
    omp_set_thread_num(4);

    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        pooth(ID, A);
    }

    // Affichage du tableau A
    for (int i = 0; i < 100; i++){
        printf("%f ", A[i]);
    }
}