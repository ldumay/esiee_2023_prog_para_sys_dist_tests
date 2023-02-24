#include <stdio.h>
#include <math.h>
#include <omp.h>

/*
 * Desciption :
 * 		Ce programme est un petit programme de test.
 *      Il permet de calculer PI en tant que moyenne d'une fonction f
 *      sur un intervalle [0,1] avec une précision de 100 pas (num_steps)
 *      et une fonction f(x) = 4 / (1 + x²).
 * Résultat :
 * 		Il affiche PI.
 */

int num_steps = 100;
float x, moyenne, f, sum, step = 0.0;

int main()
{
    printf("steps : %d\n", num_steps);
    //
    step = 1.0 / (double) num_steps;
    //Somme des fonctions f
    for(int i=0; i<num_steps; i++){
        //déplacement d'intervale
        x = (i+0.5) * step;
        //fonction f
        f = 4.0 / ( 1.0 + x * x);
        //Somme du périmètre
        printf("[f:%f]", f);
        sum += f;
    }
    //-
    printf("\nsum : %f\n", sum);
    //-
    moyenne = sum * step;
    printf("\nResultat : moyenne=%f\n", moyenne);
}