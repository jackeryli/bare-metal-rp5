#include "defs.h"

void
printk(char* s)
{
  char *c = s;
  while(*c != '\0'){
    if(*c == '\n')  uartputc('\r');
    uartputc(*c++);
  }
}