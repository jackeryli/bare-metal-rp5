#include "defs.h"

void
start()
{
	uartinit();
	printk("starting\n");

	runsh();
}
