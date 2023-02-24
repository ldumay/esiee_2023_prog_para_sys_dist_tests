#include <stdio.h>
#include <math.h>
#include <omp.h>

/*
 * Desciption :
 * 		Ce programme est un petit programme de test avec OpenMP.
 *      Il permet de calculer PI en tant que moyenne d'une fonction f
 *      sur un intervalle [0,1] avec une précision de 100 pas (num_steps)
 *      et une fonction f(x) = 4 / (1 + x²).
 *      et d'utiliser la directive #pragma omp parallel.
 * Résultat :
 * 		Il affiche PI.
 */

#define NB_THREADS 10

int main()
{
    //-prepare
    long num_steps = 10000;
    int i, nthreads; double step, x, pi, sum[NB_THREADS];
    step = 1.0 / (double) num_steps;
    //-
    omp_set_num_threads(NB_THREADS);
    //-
	#pragma omp parallel
	{
        //-init
		int get_NB_THREADS = omp_get_num_threads();
        int get_ID = omp_get_thread_num();
        int get_TIME = omp_get_wtime();
        printf("\nThreads");
		printf("[Nb threads:(%d)]", get_NB_THREADS);
        printf("[Id thread:(%d)]", get_ID);
        printf("[TIME:(%d)]", get_TIME);
        //-
        if(get_ID == 0) nthreads = get_NB_THREADS;
        for(i=0, sum[get_ID]=0.0; i<num_steps; i+get_NB_THREADS){
            x = (i+0.5) * step;
            sum[get_ID] += 4.0 / (1.0 + x * x);
        }
        //-
        for(i=0; i<NB_THREADS; i++){
            pi += step * sum[i];
        }
        //-
        printf("[PI:(%f)]\n", pi);
	}
}