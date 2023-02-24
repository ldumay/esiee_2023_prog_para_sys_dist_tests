#include "mpi.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Desciption :
 * 		Ce programme est un petit programme de test avec MPI
 *      ==>  alltoall.c
 *      Il permet d'effectuer [...]
 * Résultat :
 *    	Il affiche :
 *          Moi, processus 0 , j’ai recu 1000. ... 1128. ... 1415.
 *          Moi, processus 2 , j’ai recu 1064. ... 1192. ... 1479.
 *          Moi, processus 1 , j’ai recu 1032. ... 1160. ... 1447.
 *          Moi, processus 3 , j’ai recu 1096. ... 1224. ... 1511.
 */

#define NB_VALEURS 128

int main(int argc, char *argv[]) {
    int rang, nb_procs, longueur_tranche, i;
    float valeurs[NB_VALEURS], donnees[NB_VALEURS];

    MPI_Init (&argc,&argv);
    MPI_Comm_size ( MPI_COMM_WORLD , &nb_procs);
    MPI_Comm_rank ( MPI_COMM_WORLD , &rang);
    
    for (i=0; i<NB_VALEURS; i++) valeurs[i]=(float)(1000+rang*NB_VALEURS+i);
    longueur_tranche=NB_VALEURS/nb_procs;

    MPI_Alltoall (valeurs,longueur_tranche, MPI_FLOAT ,donnees,longueur_tranche, MPI_FLOAT , MPI_COMM_WORLD );
    printf("Moi, processus %d, j’ai recu %.0f, ..., %.0f, ..., %.0f\n", rang, donnees[0],
        donnees[longueur_tranche], donnees[NB_VALEURS-1]);
    MPI_Finalize (); return(0);
}