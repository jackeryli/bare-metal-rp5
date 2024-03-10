#include "types.h"

/* uart.c */
void      uartinit(void);
void      uartputc(int);
int       uartgetc(void);
void      uartflush(void);

/* printk.c */
void      printk(char*);

/* string.c */
void*     memset(void *, int, uint);
int       strncmp(const char*, const char*, uint);

/* sh.c */
void      runsh(void);