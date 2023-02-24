#include <stdio.h>
#include <math.h>
#include <omp.h>

/*
 * Desciption :
 * 		Ce programme est un petit programme de test avec OpenMP.
 *      Mise en parallèle avec le paramètre : actomic
 *      Il permet de ...
 * Résultat :
 * 		Il affiche ...
 */

int main()
{
    #pragma omp parallel
    {
        double tmp, B;
        B = doit();
        tmp = big_ugly(B);

        #pragma omp actomic
        //actomic : ici, il y a exécution que si il y une modification de la mémoire.
        X += tmp;
    }
}