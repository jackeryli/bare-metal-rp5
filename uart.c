#include "aux.h"
#include "uart.h"

void
uartinit(void)
{
  *AUX_ENABLES |= 1; /* Enable mini UART */

  *AUX_MU_CNTL_REG = 0;
  *AUX_MU_LCR_REG = 3;
  *AUX_MU_MCR_REG = 0;
  *AUX_MU_IER_REG = 0;
  *AUX_MU_IIR_REG = 6;  /* clear receive/transmit FIFO */
  *AUX_MU_BAUD_REG = 270;

  *AUX_MU_CNTL_REG = 3;    /* Enable tx/rx */
}

/**
 * Write to uart
 * 
 * Check AUX_MU_LSR_REG’s Transmitter empty field.
 * If set, write to AUX_MU_IO_REG
*/
void
uartputc(int c)
{
  while(!(*AUX_MU_LSR_REG & 0x20)){
    asm volatile("nop");
  }
  *AUX_MU_IO_REG = c;
}

/**
 * Read from uart
 * 
 * Check AUX_MU_LSR_REG’s data ready field.
 * If set, read from AUX_MU_IO_REG
*/
int
uartgetc(void)
{
  while(!AUX_MU_LSR_REG & 0x1){
    asm volatile("nop");
  }

  int c = *AUX_MU_IO_REG;
  c = (c == '\r') ? '\n' : c;
  return c;
}
