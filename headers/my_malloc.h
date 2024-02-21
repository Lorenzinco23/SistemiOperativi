#include <stddef.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>

#define PAGE_SIZE sysconf(_SC_PAGESIZE)
#define ALLOCATED 1
#define FREE 0
#define MEGABYTE 1024 * 1024

typedef struct block {
  size_t prev_size;
  size_t size;
  struct block *next;
  struct block *prev;
} block_t;


void buddy_init();
void *buddy_malloc(size_t size);
block_t *buddy_find(size_t size);
void *buddy_split(block_t *block, size_t size);
void buddy_free(void* ptr);
void my_free(void *ptr);
void *my_malloc(size_t size);
