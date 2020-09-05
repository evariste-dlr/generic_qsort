#ifndef __GEN_QSORT_H__
#define __GEN_QSORT_H__

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

/**
 * Permute les données des zones mémoire mem1 et mem2 et de taille size
 */
void swap(void* mem1, void* mem2, size_t size);

/**
 * Partitionne une portion du tableau
 *
 * @param tab       pointeur vers le début du tableau
 * @param i1        premier indice de la protion à partitionner
 * @param i2        dernier indice de la poriton à partitionner
 * @param p         pivot
 * @param size      taille d'un élément
 * @param compar    fonction de callback permettant de comparer deux éléments du tableau
 */
int part(void* tab, size_t i1, size_t i2, size_t p, size_t size, int (*compar)(const void*, const void*));


/**
 * Point d'entrée de l'algorithme qsort
 * Teste que le tableau n'est pas vide
 *
 * @param tab       le tableau à trier
 * @param n         taille du tableau en nombre d'éléments
 * @param compar    fonction de callback permettant de comparer deux éléments
 */
void gen_qsort(void* tab, size_t n, size_t size, int (*compar)(const void*, const void*));

/**
 * Algorithme qsort sur la portion de tableau [first; last]
 */
void gen_qsort_r(void* tab, size_t first, size_t last, size_t size, int (*compar)(const void*, const void*));


int compare_int(const void* a, const void* b);
int compare_double(const void* a, const void* b);


#endif

