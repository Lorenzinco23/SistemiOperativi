#include "../headers/utils.h"
#include <string.h>

uint8_t bitmap[MEGABYTE/8];

void bitmap_init(){
    memset(bitmap,0,MEGABYTE/8);
}

int bitmap_set(size_t index){
    ///sets the bit at index to the negative of its current value, returning the val
    if(index > MEGABYTE/8){
        return -1;
    }

}
