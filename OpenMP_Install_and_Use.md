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

Compilation du petit programme **Hello World** dans le fichier `tp1_prog1.c`.

Compilation / Résultat / Exécution / Résultat

```
cd esiee_2023_prog_para_sys_emb/
gcc -fopenmp tp1_prog1.c -o tp1_prog1.out

tree
tp1_prog1.c  tp1_prog1.out

export OMP_NUM_THREADS=4
./tp1_prog1.out

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
gcc -fopenmp tp1_prog2.c -o tp1_prog2.out && tree && ./tp1_prog2.out
```

> `tp1_prog2.c` : ok ✔

Correction

```
gcc -fopenmp tp1_prog3.c -o tp1_prog3.out && tree && ./tp1_prog3.out
```

> `tp1_prog3.c` : ok ✔

#### Partie 2

Mise en parallèle du programme.

```
gcc -fopenmp tp1_prog4.c -o tp1_prog4.out && tree && ./tp1_prog4.out
```

> `tp1_prog4.c` : ok ✔

Correction

```
gcc -fopenmp tp1_prog5.c -o tp1_prog5.out && tree && ./tp1_prog5.out
```

> `tp1_prog5.c` : ok ✔

### TP 1 - Programme 3

▶ les fork

```
gcc -fopenmp tp1_prog6.c -o tp1_prog6.out
tree
tp1_prog6.c  tp1_prog6.out
./tp1_prog6.out

 je suis le pere, monpid = 3374 et le pid de mon fils = 3375 et le gd pere = 2507
 je suis le fils, monpid = 3375 et le pid de mon pere = 3374
valeur retournee par mon fils = 20
```

### TP 1 - Programme 4

Mise en parallèle du programme `tp1_prog7.c` avec réduction.

```
gcc -fopenmp tp1_prog7.c -o tp1_prog7.out && tree && ./tp1_prog7.out
```

> `tp1_prog7.c` : ok ✔

### TP 2 - Programme 1

Superficie de l'ensemble de Mandelbrot :
- [wiki](https://fr.wikipedia.org/wiki/Ensemble_de_Mandelbrot)
- Programme parallèle : `tp2_prog1.c`.

```
gcc -fopenmp tp2_prog1.c -o tp2_prog1.out && ls | grep 'tp2_prog1.out' && ./tp2_prog1.out
```

> `tp2_prog1.c` : ok ✔

### Bonus - Programme 1 - Travailler avec des boucles

```
gcc -fopenmp z_test_1.c -o z_test_1.out && tree && ./z_test_1.out
```

> `z_test_1.c` : presques 😅

## Nettoyer toutes les compilations

```
rm -r *.out
```