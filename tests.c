#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gen_qsort.h"

typedef struct{
  double x;
  double y;
} point;


/**
 * Compare des points selon leur module
 */
int compare_point(const void* p1, const void* p2)
{
  point* pp1 = (point*)p1;
  point* pp2 = (point*)p2;

  double m1 = sqrt(pp1->x * pp1->x + pp1->y * pp1->y);
  double m2 = sqrt(pp2->x * pp2->x + pp2->y * pp2->y);

  if (m1 < m2)
    return -1;
  else if (m1 >  m2)
    return 1;
  else
    return 0;
}


int main(int argc, char* argv[]){

  char red[11] = "\033[0;31m";
  char green[11] = "\033[0;32m";
  char nocl[8] = "\033[0m";

  int i, b;
  int N=11;
  int ti[11] = {1, 5, 3, 8, 6, 0, -5, -3, 4, -7, 12};
  int ri[11] = {-7, -5, -3, 0, 1, 3, 4, 5, 6, 8, 12};

  /****************************************/
  printf("Test 1 : int sample data \n");
  gen_qsort(ti, N, sizeof(int), compare_int);
  
  b = 1;
  for (i=0; i<N; i++){
    printf("%i ", ti[i]);
    if (ti[i] != ri[i])
      b = 0;
  }
  if (b){ printf("\n %s SUCCESS %s\n", green, nocl); }
  else  { printf("\n %s FAILURE %s\n", red, nocl); }
  printf("\n");
  
  
  
  /****************************************/

  int ti2[] = {-5, -6, -85, -1, -9, -3, -54, -63, -4, -44, -51};
  int ri2[] = {-85, -63, -54, -51, -44, -9, -6, -5, -4, -3, -1};
  memcpy(ti, ti2, N*sizeof(int));
  memcpy(ri, ri2, N*sizeof(int));

  printf("Test 2 : int all negative \n");
  gen_qsort(ti, N, sizeof(int), compare_int);
  
  b = 1;
  for (i=0; i<N; i++){
    printf("%i ", ti[i]);
    if (ti[i] != ri[i])
      b = 0;
  }
  if (b){ printf("\n %s SUCCESS %s\n", green, nocl); }
  else  { printf("\n %s FAILURE %s\n", red, nocl); }
  printf("\n");


  /****************************************/

  int ti3[] = {-7, -5, -3, 0, 1, 3, 4, 5, 6, 8, 12};
  memcpy(ti, ti3, N*sizeof(int));
  memcpy(ri, ti3, N*sizeof(int));

  printf("Test 3 : int already ordered \n");
  gen_qsort(ti, N, sizeof(int), compare_int);
  
  b = 1;
  for (i=0; i<N; i++){
    printf("%i ", ti[i]);
    if (ti[i] != ri[i])
      b = 0;
  }
  if (b){ printf("\n %s SUCCESS %s\n", green, nocl); }
  else  { printf("\n %s FAILURE %s\n", red, nocl); }
  printf("\n");


  /****************************************/

  int ti4[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
  memcpy(ti, ti4, N*sizeof(int));
  memcpy(ri, ti4, N*sizeof(int));

  printf("Test 4 : all -1 \n");
  gen_qsort(ti, N, sizeof(int), compare_int);
  
  b = 1;
  for (i=0; i<N; i++){
    printf("%i ", ti[i]);
    if (ti[i] != ri[i])
      b = 0;
  }
  if (b){ printf("\n %s SUCCESS %s\n", green, nocl); }
  else  { printf("\n %s FAILURE %s\n", red, nocl); }
  printf("\n");


  /****************************************/

  printf("Test 5 : empty \n");
  gen_qsort(ti, 0, sizeof(int), compare_int);
  
  b = 1;
  for (i=0; i<0; i++){
    printf("%i ", ti[i]);
    if (ti[i] != ri[i])
      b = 0;
  }
  if (b){ printf("\n %s SUCCESS %s\n", green, nocl); }
  else  { printf("\n %s FAILURE %s\n", red, nocl); }
  printf("\n");


  /****************************************/

  double td[] = {-5.3, -6.4, -85.4, -1.5, -9.8, -3.8, -54.6, -63.33, -4.7, -44.1, -51.0};
  double rd[] = {-85.4, -63.33, -54.6, -51.0, -44.1, -9.8, -6.4, -5.3, -4.7, -3.8, -1.5};


  printf("Test 6 : double all negative \n");
  gen_qsort(td, N, sizeof(double), compare_double);
  
  b = 1;
  for (i=0; i<N; i++){
    printf("%f ", td[i]);
    if (td[i] != rd[i])
      b = 0;
  }
  if (b){ printf("\n %s SUCCESS %s\n", green, nocl); }
  else  { printf("\n %s FAILURE %s\n", red, nocl); }
  printf("\n");

  /****************************************/

  point tp[4] = {{5.3,-2.3}, {1.0,1.0}, {0.3,6.4}, {2.5, 4.1}};
  point rp[4] = {{1.0,1.0}, {2.5, 4.1}, {5.3,-2.3}, {0.3,6.4}};

  printf("Test 7 : 2D points by module \n");
  gen_qsort(tp, 4, sizeof(point), compare_point);
  
  b = 1;
  for (i=0; i<4; i++){
    printf("{%f, %f} ", (tp[i]).x, (tp[i]).y);
    if (tp[i].x != rp[i].x || tp[i].y != rp[i].y)
      b = 0;
  }
  if (b){ printf("\n %s SUCCESS %s\n", green, nocl); }
  else  { printf("\n %s FAILURE %s\n", red, nocl); }
  printf("\n");

  return b;

}
