#include "main.h"
#include "stdio.h"
#define FLASHBASEADDRESS NULL
uint32_t flexspibellek[4096];
uint8_t *ptrflexspibellek=&flexspibellek;
    Flash_t bellek;
    volatile int i=0;
    volatile int j=0;
      void flexspi_nor_flash_page_program(const int* BASEADDRESS,uint32_t address,const uint32_t *buffer)
{
	
    for(int i=0;i<64;i++)
    {
        *(ptrflexspibellek+address+4)=buffer[i];
    
    }
	
}




void flash_func_write_word(uint32_t address, uint32_t word)
{
   int pageIndex=address/256;
   int wordIndex=address%256;
   bellek.BUFFER[pageIndex][wordIndex]=word;


if((address!=0x00)&&((address&0xFF)==0x00)&&(i==16))
{
    i=0;
    j=0;
    for(i=0;i<16;i++)
    {
        flexspi_nor_flash_page_program(FLASHBASEADDRESS,address,&bellek.BUFFER[i][j]);
    
    }
    
}


}


int main()
{
    uint32_t address=0x0000;
    uint32_t uartcomeinword=0x0a0b0c0d;
    for(int i=0;i<64*16;i++)
 {  
    flash_func_write_word(address,uartcomeinword);
    uartcomeinword++;
    address+=4;

   

}




}