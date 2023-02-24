#include "mpi.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Desciption :
 * 		Ce programme est un petit programme de test avec MPI
 *      ==>  allreduce.c
 *      Il permet d'effectuer [...]
 * Résultat :
 *    	Il affiche :
 *          Moi, processus 0, j’ai pour valeur de la somme globale 1006
 *          Moi, processus 1, j’ai pour valeur de la somme globale 1006
 *          Moi, processus 2, j’ai pour valeur de la somme globale 1006
 *          Moi, processus 3, j’ai pour valeur de la somme globale 1006
 */

int main(int argc, char *argv[]) {
    int rang, valeur, somme;

    MPI_Init (&argc,&argv);
    MPI_Comm_rank ( MPI_COMM_WORLD , &rang);

    if (rang == 0) valeur=1000; else valeur=rang;
    MPI_Allreduce (&valeur,&somme,1, MPI_INT , MPI_SUM , MPI_COMM_WORLD );
    
    printf("Moi, processus %d, j’ai pour valeur de la somme globale %d\n", rang, somme);
    MPI_Finalize (); return(0);
}