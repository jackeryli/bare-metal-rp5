#include "defs.h"

void
printk(char* s)
{
  char *c = s;
  while(*c){
    if(*c == '\n')  uartputc('\r');
    uartputc(*c++);
  }
}