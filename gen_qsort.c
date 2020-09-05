#include "gen_qsort.h"

void swap(void* mem1, void* mem2, size_t size)
{
  char* m = malloc(size);
  memcpy(m, mem1, size);
  memcpy(mem1, mem2, size);
  memcpy(mem2, m, size);
  free(m);
}

int part(void* tab, size_t i1, size_t i2, size_t p, size_t size, int (*compar)(const void*, const void*))
{
  char* ctab = (char*)tab;
  swap(ctab+(p*size), ctab+(i2*size), size);
  
  int j=i1;
  int i;
  for (i=i1; i<i2; i++){
    if (compar(ctab+(i*size), ctab+(i2*size)) <= 0){
      swap(ctab+(i*size), ctab+(j*size), size);
      j++;
    }
  }
  
  swap(ctab+(i2*size), ctab+(j*size), size);
  return j;
}

void gen_qsort(void* tab, size_t n, size_t size, int (*compar)(const void*, const void*))
{
  if (n > 0)
    gen_qsort_r(tab, 0, n-1, size, compar);
}


void gen_qsort_r(void* tab, size_t first, size_t last, size_t size, int (*compar)(const void*, const void*))
{
  if (first < last){
    int i;
    size_t p = first;
    p = part(tab, first, last, p, size, compar);
    if (p > 0)
      gen_qsort_r(tab, first, p-1, size, compar);
    gen_qsort_r(tab, p+1, last, size, compar);
  }
}


int compare_int(const void* a, const void* b)
{
  int* ca = (int*)(a);
  int* cb = (int*)(b);
  return (*ca - *cb);
}



int compare_double(const void* a, const void* b)
{
  double* ca = (double*)(a);
  double* cb = (double*)(b);
  if (*ca - *cb < .0f) return -1;
  else if(*ca - *cb > .0f) return 1;
  else return 0;
}

