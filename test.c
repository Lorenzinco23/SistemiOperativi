#include "headers/my_malloc.h"
#include <stdio.h>

typedef struct{
  int a;
  int b;
  int c;
} complex_struct;

int main() {
  
  int *ptr = (int *)my_malloc(sizeof(int));
  *ptr = 42;
  printf("%d\n", *ptr);
  complex_struct *my_struct = (complex_struct *)my_malloc(sizeof(complex_struct));
  my_struct->a = 42;
  my_struct->b = 43;
  my_struct->c = 44;
  printf("%d %d %d\n", my_struct->a, my_struct->b, my_struct->c);

  my_free(ptr);
  my_free(my_struct);
}
