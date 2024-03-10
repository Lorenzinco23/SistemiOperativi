//Bitmap utils
#include <stdint.h>
#include <stddef.h>

#define ALLOCATED 1
#define FREE 0
#define MEGABYTE 1024 * 1024

int bitmap_find(size_t size); ///returns the index of the first free slice of memory
int bitmap_set(size_t index); ///sets the index to used
void bitmap_allocate(size_t index, size_t size); ///sets the index to used
void bitmap_deallocate(size_t index, size_t size); ///sets the index to free
void bitmap_init(); ///initializes the bitmap
void size_init();
int size_set(size_t index, size_t len);
size_t size_unset(uint32_t index);
