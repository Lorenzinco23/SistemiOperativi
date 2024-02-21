#include "headers/my_malloc.h"
#include <stdio.h>

int main() {
  int *ptr = my_malloc(sizeof(int));
  *ptr = 42;
  printf("%d\n", *ptr);
}
