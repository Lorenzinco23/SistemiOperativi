#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>

void buddy_init();
void *buddy_find(size_t size);
void buddy_deallocate(void* ptr);