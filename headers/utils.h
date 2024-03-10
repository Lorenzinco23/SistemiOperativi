//Bitmap utils
#include <stdint.h>
#include <stddef.h>

#define ALLOCATED 1
#define FREE 0
#define MEGABYTE 1024 * 1024

uint8_t bitmap_find(size_t size); ///returns the index of the first free slice of memory
int bitmap_set(size_t index); ///sets the index to used
void bitmap_init();///initializes the bitmap
