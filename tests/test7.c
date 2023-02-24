#include <stdio.h>
#include <math.h>
#include <omp.h>

/*
 * Desciption :
 * 		Ce programme est un petit programme de test avec OpenMP.$
 *      Mise en parallèle avec le paramètre : critical
 *      Il permet de ...
 * Résultat :
 * 		Il affiche ...
 */

int main()
{
    float res;

    #pragma omp parallel
    {
        float B;
        int i, id, nthrds;
        
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();

        for(i=id; i<niters; i+=nthrds){
            B += big_job(i);

            #pragma omp critical
            //critical : ici, les threads s'exécutent 1 à 1
            res += consume(B);
        }
    }
}