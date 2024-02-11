#include "main.h"
#include "stdio.h"
#define PAGESIZE 16
#define WORDSIZE 64 
#define FLASHBASEADDRESS NULL
uint32_t flexspibellek[4096];
uint32_t *ptrflexspibellek=flexspibellek;
Flash_t bellek;
      void flexspi_nor_flash_page_program(const int* BASEADDRESS,uint32_t address,const uint32_t *buffer)
{
	
    for(int i=0;i<64;i++)
    {
        *(ptrflexspibellek+address+4)=buffer[i];
    
    }
	
}




void flash_func_write_word(uint32_t address, uint32_t word)
{
   int pageIndex=((address&(0xFFF)))/256;// address come into upper layer.started 0x00.Masked 0xFFF if come into 4096(0x1000) 
   int wordIndex=((address)%256)/4; // diveded 4 because that adress come into added +4...
   bellek.BUFFER[pageIndex][wordIndex]=word; //
   
   

        if(wordIndex==63) /**one page receiving was completed*/
       {
       flexspi_nor_flash_page_program(FLASHBASEADDRESS,address-0x100,&bellek.BUFFER[pageIndex][wordIndex]);
       /**
        * address-256 -> if one page receiving was completed, adress have 0x0000+(4*64) and we want to write start address its.
        * if start adress 0x100 page index = 1 and word index =0 and  buffer[1][0] its mean that we start to write another page.
        * so that another page start adress is 0x100 and we fill another page we have new adress 0x100+0x100 and our start adress of 1.page is
        * 0x100 and we handle it 0x200-0x100
        * 
       */
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