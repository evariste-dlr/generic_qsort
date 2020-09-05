# Qsort Générique en C

Un code utilisé avec mes étudiants comme support de TP pour illustrer et travailler en C :

* La généricité
* L'utilisation de pointeurs de fonctions pour les callbacks
* La gestion de la mémoire
* L'algorithme de tri rapide

## Compilation

```
$ make
```

## Lancer les Tests

```
$ ./tests
```

## Exemple de sortie

```
kali@kali:~/Bureau/qsort$ ./tests

Test 1 : int sample data 
-7 -5 -3 0 1 3 4 5 6 8 12 
  SUCCESS 

Test 2 : int all negative 
-85 -63 -54 -51 -44 -9 -6 -5 -4 -3 -1 
  SUCCESS 

Test 3 : int already ordered 
-7 -5 -3 0 1 3 4 5 6 8 12 
  SUCCESS 

Test 4 : all -1 
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
  SUCCESS 

Test 5 : empty 

  SUCCESS 

Test 6 : double all negative 
-85.400000 -63.330000 -54.600000 -51.000000 -44.100000 -9.800000 -6.400000 -5.300000 -4.700000 -3.800000 -1.500000 
  SUCCESS 

Test 7 : 2D points by module 
{1.000000, 1.000000} {2.500000, 4.100000} {5.300000, -2.300000} {0.300000, 6.400000} 
  SUCCESS 
```

