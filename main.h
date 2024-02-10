#ifndef __HEADER__
#define __HEADER__
#include<stdint.h>
#include<string.h>
#define FLASHSIZE 4096
typedef struct Flash_t
{
    uint32_t BUFFER[16][64];
}Flash_t;

void FlashInit(Flash_t *flash){
    memset(&flash->BUFFER,0xFF,FLASHSIZE);

}




#endif