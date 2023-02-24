#include "mpi.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Desciption :
 * 		Ce programme est un petit programme de test avec MPI
 *      ==>  reduce.c
 *      Il permet d'effectuer [...]
 * Résultat :
 *    	Il affiche :
 *          Moi, processus 0 , j’ai pour valeur de la somme globale 1021
 */

int main(int argc, char *argv[]) {
    int rang, valeur, somme;

    MPI_Init (&argc,&argv);
    MPI_Comm_rank ( MPI_COMM_WORLD , &rang);

    if (rang == 0) valeur=1000; else valeur=rang;
    MPI_Reduce (&valeur,&somme,1, MPI_INT , MPI_SUM ,0, MPI_COMM_WORLD );

    if (rang == 0)
    printf("Moi, processus 0, j’ai pour valeur de la somme globale %d\n",somme); 
    MPI_Finalize (); return(0);
}