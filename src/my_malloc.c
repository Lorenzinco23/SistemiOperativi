#include "../headers/buddy_allocator.h"
#include "../headers/my_malloc.h"
#include "../headers/mmap_allocator.h"
#include "../headers/utils.h"
#include <stdbool.h>

extern uint8_t heap[MEGABYTE];
bool initialized = false;



void * my_malloc(size_t size){
    if (!initialized) my_malloc_init();
    if(size > MEGABYTE) return mmap_allocate(size);
    return buddy_find(size);
}

void my_free(void * ptr){
    if (!initialized) return;
    if ((uint8_t *)ptr < heap || (uint8_t *)ptr > heap + MEGABYTE) mmap_deallocate(ptr);
    else buddy_deallocate(ptr);
}

void my_malloc_init(){
    buddy_init();
    mmap_init();
    initialized = true;
}