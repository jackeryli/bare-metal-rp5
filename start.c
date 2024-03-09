#include "uart.h"

void start()
{
	uartinit();
	uartputc('j');
	uartputc('a');
	uartputc('c');
	uartputc('k');
}
