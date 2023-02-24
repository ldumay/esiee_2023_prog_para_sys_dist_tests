#include "mpi.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Desciption :
 * 		Ce programme est un petit programme de test avec MPI
 *      ==>  scatter.c
 *      Il permet d'effectuer [...]
 * Résultat :
 *    	Il affiche :
 *          Moi, processus 0 , j’ai recu 1000. à 1031. du processus 2
 *          Moi, processus 1 , j’ai recu 1032. à 1063. du processus 2
 *          Moi, processus 3 , j’ai recu 1096. à 1127. du processus 2
 *          Moi, processus 2 , j’ai recu 1064. à 1095. du processus 2
 */

#define NB_VALEURS 128

int main(int argc, char *argv[]) {
    
    int rang, nb_procs, longueur_tranche, i;
    float *valeurs, *donnees;

    MPI_Init (&argc,&argv);
    MPI_Comm_size ( MPI_COMM_WORLD , &nb_procs);
    MPI_Comm_rank ( MPI_COMM_WORLD , &rang);
    
    longueur_tranche=NB_VALEURS/nb_procs;
    donnees=(float*)malloc(longueur_tranche*sizeof(float));
    
    if (rang == 2) {
        valeurs=(float*) malloc(NB_VALEURS*sizeof(float));
    }
    
    for (i=0; i<NB_VALEURS; i++) valeurs[i]=(float)(1000+i);
    
    MPI_Scatter (valeurs,longueur_tranche, MPI_FLOAT ,donnees,longueur_tranche, MPI_FLOAT ,2, MPI_COMM_WORLD );
    
    printf("Moi, processus %d, j’ai recu %.0f à %.0f du processus 2\n",
    rang, donnees[0], donnees[longueur_tranche-1]);
    if (rang == 2) free(valeurs); free(donnees); MPI_Finalize (); return(0);
}