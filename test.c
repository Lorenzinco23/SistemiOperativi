#include "headers/my_malloc.h"
#include <stdio.h>
#include <assert.h>

#define MEGABYTE 1024*1024

typedef struct{
  int a;
  int b;
  int c;
} complex_struct;

int main() {
  
  //buddy allocator tests
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

  //mmap allocator tests
  void *ptr2 = my_malloc(MEGABYTE * 2);
  printf("%p\n", ptr2);
  my_free(ptr2);

  //max size allocation after free test
  //this test is to check if the allocator can allocate the maximum size after a free
  void *ptr3 = my_malloc(MEGABYTE-1);
  printf("%p\n", ptr3);
  assert(ptr3 == ptr);
}
