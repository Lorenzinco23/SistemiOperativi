//Bitmap utils
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

uint8_t bitmap_find(size_t size); ///returns the index of the first free slice of memory
bool bitmap_set(size_t index); ///sets the index to used
