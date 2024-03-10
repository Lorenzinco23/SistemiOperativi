#include "../headers/mmap_allocator.h"

mmap_block mmap_allocations[MAX_MMAP_ALLOCATIONS];

void mmap_init(){
    for (uint32_t i = 0; i < MAX_MMAP_ALLOCATIONS; i++){
        mmap_allocations[i].addr = NULL;
        mmap_allocations[i].size = 0;
    }
}

size_t mmap_get_size(void * ptr){
    for (uint32_t i = 0; i < MAX_MMAP_ALLOCATIONS; i++){
        if (mmap_allocations[i].addr == ptr){
            return mmap_allocations[i].size;
        }
    }
    return 0;
}

void * mmap_allocate(size_t size){
    for (uint32_t i = 0; i < MAX_MMAP_ALLOCATIONS; i++){
        if (mmap_allocations[i].addr == NULL){
            mmap_allocations[i].addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);;
            mmap_allocations[i].size = size;
            return mmap_allocations[i].addr;
        }
    }
    return NULL;
}

int mmap_deallocate(void * ptr){
    size_t size = mmap_get_size(ptr);
    return size ? munmap(ptr,size) : -1;
}