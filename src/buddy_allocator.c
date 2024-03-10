#include "../headers/buddy_allocator.h"
#include "../headers/utils.h"
#include "../headers/mmap_allocator.h"

uint8_t heap[MEGABYTE];

void buddy_init(){
    bitmap_init();
    size_init();
    memset(heap,0,MEGABYTE);
}

void * buddy_find(size_t size){
    int32_t address = bitmap_find(size);
    if(address == -1) return mmap_allocate(size); //TODO CALL THE MMAP ALLOCATOR

    bitmap_allocate(address,size);
    return (void *)&heap[address];
}

void buddy_deallocate(void * ptr){
    size_t address = (uint8_t *)ptr - heap;
    if (address < 0 || address > MEGABYTE){
        mmap_deallocate(ptr);
        return;
    }
    size_t len = size_unset(address);
    bitmap_deallocate(address,len);
}
