#include <stdio.h>
#include <math.h>
#include <omp.h>

/*
 * Desciption :
 * 		Ce programme est un petit programme de test avec OpenMP.
 *      Mise en parallèle avec le paramètre : barrier
 *      Il permet de ...
 * Résultat :
 * 		Il affiche ...
 */

int main()
{
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        A[id] = big_calc1(id);

        #pragma omp barrier
        //barrier : ici, attends la fin des lignes (threads) précédentes
        B[id] = big_calc2(id, A);
    }
}