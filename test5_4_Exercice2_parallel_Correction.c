#include <stdio.h>
#include <omp.h>

/*
 * Desciption :
 * 		Ce programme est un petit programme de test avec OpenMP.
 *      Il permet de calculer PI en tant que moyenne d'une fonction f
 *      sur un intervalle [0,1] avec une précision de 100 pas (num_steps)
 *      et une fonction f(x) = 4 / (1 + x²)
 *      et d'utiliser la directive #pragma omp parallel.
 * Résultat :
 * 		Il affiche PI.
 */

#define NUM_THREADS 2

static long num_steps = 100000;
double step;

void main(){
    int i, nthreads; 
    double pi, sum[NUM_THREADS];
    step = 1.0/(double) num_steps;
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        int id, nthrds;
        double  x;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if(id == 0)nthreads = nthrds;
        for(i=id, sum[id]=0.0; i<num_steps; i=i+nthrds){
            x=step*(i+0.5);
            sum[id]+=4.0/(1.0+x*x);
        }
    }
    for(i=0, pi=0.0; i<nthreads;i++)pi+=sum[i]*step;
    //-
    printf("[PI:(%f)]\n", pi);
}