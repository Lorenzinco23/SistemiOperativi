#include <sys/mman.h>
#include <stdlib.h>

#define MAX_MMAP_ALLOCATIONS 1000

typedef struct mmap_block {
    void * addr;
    size_t size;
    struct mmap_block * next;
}mmap_block;

void * mmap_allocate(size_t size);
int mmap_deallocate(void * ptr);
size_t mmap_allocated_size(void * ptr);
void mmap_init();