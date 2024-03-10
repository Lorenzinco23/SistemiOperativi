#include "../headers/utils.h"
#include <string.h>
#include <stdio.h>

uint8_t bitmap[MEGABYTE/8];
uint8_t size[MEGABYTE/8];

void bitmap_init(){
    //sets the memory to free
    memset(bitmap,FREE,MEGABYTE/8);
}

void size_init(){
    //sets the memory to free
    memset(size,FREE,MEGABYTE/8);
}

int bitmap_set(size_t index){
    ///sets the bit at index to the negative of its current value, returning the val
    if(index > MEGABYTE/8){
        return -1;
    }

    uint8_t mask = 1<<7;
    mask = mask >> (index%8);
    bitmap[index/8] ^= mask;
    return bitmap[index/8] & mask;
}

int size_set(size_t index, size_t len){
    ///set to 1 the bits at the start of the memory block and at the end
    if(index > MEGABYTE/8){
        return -1;
    }

    uint8_t mask = 1<<7;
    mask = mask >> (index%8);
    size[index/8] ^= mask;
    mask = 1<<7;
    mask = mask >> ((index+len)%8);
    size[(index+len)/8] ^= mask;
    return size[index/8] & mask;
}

int bitmap_find(size_t size){
    ///returns the index of the first slice of memory that is free
    uint8_t mask = 1<<7;
    size_t contigous_free = 0;

    for(uint32_t i = 0; i < MEGABYTE/8; i++){
        for(uint8_t j = 0; j < 8; j++){
            //if the bit is zero increment the contigous_free counter
            if((bitmap[i] & mask>>j) == FREE) contigous_free++;
            //else reset the counter and start counting from 0
            else contigous_free = 0;

            //if the counter is equal to the size return the index
            if(contigous_free == size)return i*8+j-size+1;
        }
    }
    //if no contigous memory is found return -1 and let the caller handle the error
    return -1;
}

void bitmap_allocate(size_t index, size_t size){
    ///sets the index to used
    for(size_t i = 0; i < size; i++){
        bitmap_set(index+i);
    }
    size_set(index,size);
}

void bitmap_deallocate(size_t index, size_t size){
    ///sets the index to free
    for(size_t i = 0; i < size; i++){
        bitmap_set(index+i);
        
    }
    size_unset(index);
}

size_t size_unset(uint32_t index){
    ///finds the size of the memory block cycling through the size bitmap bit by bit until it finds a 1
    size_t len = 1;
    uint8_t mask = 1<<7;
    mask = mask >> (index%8);
    size[index/8] ^= mask;
    
    for(uint32_t i = index; i < MEGABYTE/8; i++){
        for(uint8_t j = 0; j < 8; j++){
            if((size[i] & 1<<j) == 0)len++;
            else{
                //bitflip the bit and return the length
                size[i] ^= 1<<j;
                return len;
            }
        }
    }
    return 0;
}

void debug_print_sizes(){
    ///prints the size bitmap
    for(uint32_t i = 0; i < MEGABYTE/8; i++){
        for(uint8_t j = 0; j < 8; j++){
            if(size[i] & 1<<j)
                printf("s[%d]%d\n",i,size[i] & 1<<j);
        }
    }
    printf("\n");
}

void debug_print_bitmap(){
    ///prints the bitmap
    for(uint32_t i = 0; i < MEGABYTE/8; i++){
        for(uint8_t j = 0; j < 8; j++){
            if(bitmap[i] & 1<<j)
                printf("b[%d]%d\n",i,bitmap[i] & 1<<j);
        }
    }
    printf("\n");
}