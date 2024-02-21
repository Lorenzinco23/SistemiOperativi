#include "../headers/my_malloc.h"

uint8_t heap[MEGABYTE];

void buddy_init(){
    block_t * buddy_heap = (block_t *)heap;
    buddy_heap->size = MEGABYTE-sizeof(block_t);
    buddy_heap->prev_size = 0;
    buddy_heap->next = NULL;
    buddy_heap->prev = NULL;
}

block_t* buddy_find(size_t size){
    block_t * buddy_heap = (block_t *)heap;
    while(buddy_heap->next)
}
