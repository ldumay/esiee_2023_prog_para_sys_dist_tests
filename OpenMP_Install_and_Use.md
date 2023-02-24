[Retour](../../)

# OpenMPI - Installation et utilisation

> **NB** : Penser à vous déplacer dans le sous-dossier **open-mp** du projet.

## Installation de OpenMPI

### Linux

```
sudo apt install libomp-dev
```

### MacOS

```
brew install libomp
```

## Utilisation de OpenMPI

### Compilation

```
gcc -fopenmp test1.c -o test1.out
```

### Exécution

```
./test1.out
```

## Tests et programmes

Basé sur le PDF du cours.

Bien entendu, celui-ci est privé mais il est basé sur ce document officiel de Intel Corp. :
- [▶ICI - PDF direct◀](docs/omp-hands-on-SC08.pdf)
- [▶ICI - PDF de OpenMp.org](https://www.openmp.org/wp-content/uploads/omp-hands-on-SC08.pdf).

### TP 1 - Programme 1 - Hello World

Compilation du petit programme **Hello World** dans le fichier `test1.c`.

Compilation / Résultat / Exécution / Résultat

```
cd esiee_2023_prog_para_sys_emb/
gcc -fopenmp test1.c -o test1.out

tree
test1.c  test1.out

export OMP_NUM_THREADS=4
./test1.out

hello(3)world(3) 
hello(0)world(0) 
hello(1)world(1) 
hello(2)world(2) 
```

### TP 1 - Programme 2 - [...]

#### Partie 1

**CF** : PDF Exercice 2 - Intégration numérique

Programmation des fonctions mathématiques en **C**.

```
gcc -fopenmp test5_1_Exercice2.c -o test5_1_Exercice2.out && tree && ./test5_1_Exercice2.out
```

> `test5_1_Exercice2.c` : ok ✔

Correction

```
gcc -fopenmp test5_2_Exercice2_Correction.c -o test5_2_Exercice2_Correction.out && tree && ./test5_2_Exercice2_Correction.out
```

> `test5_2_Exercice2_Correction.c` : ok ✔

#### Partie 2

Mise en parallèle du programme.

```
gcc -fopenmp test9_1_Exercice3.c -o test9_1_Exercice3.out && tree && ./test9_1_Exercice3.out
```

> `test9_1_Exercice3.c` : ok ✔

Correction

```
gcc -fopenmp test5_4_Exercice2_parallel_Correction.c -o test5_4_Exercice2_parallel_Correction.out && tree && ./test5_4_Exercice2_parallel_Correction.out
```

> `test5_4_Exercice2_parallel_Correction.c` : ok ✔

### TP 1 - Programme 3

▶ les fork

```
gcc -fopenmp z_test_1.c -o z_test_1.out
tree
z_test_1.c  z_test_1.out
./z_test_1.out

 je suis le pere, monpid = 3374 et le pid de mon fils = 3375 et le gd pere = 2507
 je suis le fils, monpid = 3375 et le pid de mon pere = 3374
valeur retournee par mon fils = 20
```

### TP 1 - Programme 4

Mise en parallèle du programme `test9_2_Exercice3_Correction.c` avec réduction.

```
gcc -fopenmp test9_1_Exercice3.c -o test9_1_Exercice3.out && tree && ./test9_1_Exercice3.out
```

> `test9_1_Exercice3.c` : ok ✔

```
gcc -fopenmp test9_2_Exercice3_Correction.c -o test9_2_Exercice3_Correction.out && tree && ./test9_2_Exercice3_Correction.out
```

> `test9_2_Exercice3_Correction.c` : ok ✔

### TP 2 - Programme 1

Superficie de l'ensemble de Mandelbrot :
- [wiki](https://fr.wikipedia.org/wiki/Ensemble_de_Mandelbrot)
- Programme parallèle : `z_test_0.c`.

```
gcc -fopenmp z_test_0.c -o z_test_0.out && ls | grep 'z_test_0.out' && ./z_test_0.out
```

> `z_test_0.c` : ok ✔

### Bonus - Programme 1 - Travailler avec des boucles

```
gcc -fopenmp z_test_2.c -o z_test_2.out && tree && ./z_test_2.out
```

> `z_test_2.c` : presques 😅

## Nettoyer toutes les compilations

```
rm -r *.out
```