#include "defs.h"

#include <stdarg.h>

static char digits[] = "0123456789abcdef";

void
printint(int xx, int base, int sign){
  char buf[16];

  int i, x, neg;

  if(sign && xx < 0){
    neg = 1;
    x = -xx;
  } else {
    x = xx;
  }

  i = 0;
  do {
    buf[i++] = digits[xx % base];
  } while((xx /= base) != 0);

  if(neg){
    buf[i++] = '-';
  }

  while(--i >= 0){
    uartputc(buf[i]);
  }
}

void
printk(char* fmt, ...)
{
  va_list ap;
  char c;
  int i, state;
  char *s;

  va_start(ap, fmt);
  state = 0;
  for(i=0; fmt[i]; i++){
    c = fmt[i];

    if(state == 0){
      if(c == '%'){
        state = '%';
      } else {
        uartputc(c);
      }
    } else if(state == '%'){
      switch(c){
      case 'd':
        printint(va_arg(ap, int), 10, 1);
        break;
      case '%':
        uartputc(c);
        break;
      case 's':
        s = va_arg(ap, char*);
        if(s == 0){
          s = "(null)";
        }
        while(*s != 0){
          uartputc(*s);
          s++;
        }
        break;
      default:
        uartputc('%');
        break;
      }
      state = 0;
    }
  }
}