#include <stddef.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>

#define PAGE_SIZE sysconf(_SC_PAGESIZE)

void my_free(void *ptr);
void *my_malloc(size_t size);
void my_malloc_init();