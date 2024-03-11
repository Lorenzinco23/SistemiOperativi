# SistemiOperativi - Malloc

A simple allocator writte for the Operating Systems course at Sapienza Universita' di Roma.

## Usage:
Include the header file my_malloc.h in your project and use the functions `my_malloc` and `my_free` to allocate and deallocate memory.

```c
#include "my_malloc.h"

int main() {
    int *a = my_malloc(sizeof(int));
    *a = 5;
    my_free(a);
    return 0;
}
```

`void * my_malloc(size_t size)` and `void my_free(void * ptr)` respectively allocate and deallocate memory. 

Interally memory with size below MegaByte gets allocated using a buddy allocator until the total MegaByte limit is reached. After that, memory is allocated using the system's `mmap` and freed using `munmap` functions.

Due to the nature of the mmap and munmap functions, the allocator supports up to `MAX_MMAP_ALLOCATIONS` allocations, defined and customizable in the mmap_allocator.h file.

## Return values:
`my_malloc` returns a pointer to the allocated memory, or NULL if the allocation failed.

`my_free` returns nothing.

## Compiling
To compile the allocator and run the tests, use the following commands:

```bash
make
./malloc
```
This will stack all of the objects generated at compile time under the build directory.

If you wish to delete the build directory and compile from scratch, simply run `make clean` and then `make` again.



