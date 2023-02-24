#include "mpi.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Desciption :
 * 		Ce programme est un petit programme de test avec MPI
 *      ==>  bcast.c
 *      Il permet d'effectuer [...]
 * Résultat :
 *    	Il affiche :
 *          Moi, processus 2, j’ai recu 1002 du processus 2
 *          Moi, processus 0, j’ai recu 1002 du processus 2
 *          Moi, processus 3, j’ai recu 1002 du processus 2
 *          Moi, processus 1, j’ai recu 1002 du processus 2
 */

int main(int argc, char *argv[]) {
    int rang, valeur;
    
	MPI_Init (&argc,&argv);
	MPI_Comm_rank ( MPI_COMM_WORLD , &rang);
	
	if (rang == 2) valeur=rang+1000;
	
	MPI_Bcast (&valeur,1, MPI_INT , 2, MPI_COMM_WORLD );
	
	printf("Moi, processus %d, j’ai recu %d du processus 2\n",rang, valeur); MPI_Finalize ();
	return(0);
}