#include "aux.h"
#include "defs.h"

void
uartinit(void)
{
  *AUX_ENABLES |= 1; /* Enable mini UART */

  *AUX_MU_CNTL_REG = 0;   /* Disable transmitter and receiver during configuration */
  *AUX_MU_LCR_REG = 3;    /* 8-bit mode */
  *AUX_MU_MCR_REG = 0;    /* Disable RTS line */
  *AUX_MU_IER_REG = 0;    /* Disable interrupts */
  *AUX_MU_IIR_REG = 6;    /* Clear receive/transmit FIFO */
  *AUX_MU_BAUD_REG = 270; /* Set baud rate to 115200 */

  *AUX_MU_CNTL_REG = 3;   /* Enable transmitter and receiver */
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
  while(!(*AUX_MU_LSR_REG & 0x20));

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
  while(!(*AUX_MU_LSR_REG & 0x01));

  int c = *AUX_MU_IO_REG;
  c = (c == '\r') ? '\n' : c;
  return c;
}

void
uartflush()
{
  while(*AUX_MU_LSR_REG & 0x01){
    *AUX_MU_IO_REG;
  }
}
