/* ARM aux peripheral physical address start */
#define BASE_ADDRESS 0x3f000000

#define AUX_IRQ           (volatile unsigned int*) (0x7E215000 - BASE_ADDRESS)
#define AUX_ENABLES       (volatile unsigned int*) (0x7E215004 - BASE_ADDRESS)
#define AUX_MU_IO_REG     (volatile unsigned int*) (0x7E215040 - BASE_ADDRESS)
#define AUX_MU_IER_REG    (volatile unsigned int*) (0x7E215044 - BASE_ADDRESS)
#define AUX_MU_IIR_REG    (volatile unsigned int*) (0x7E215048 - BASE_ADDRESS)
#define AUX_MU_LCR_REG    (volatile unsigned int*) (0x7E21504C - BASE_ADDRESS)
#define AUX_MU_MCR_REG    (volatile unsigned int*) (0x7E215050 - BASE_ADDRESS)
#define AUX_MU_LSR_REG    (volatile unsigned int*) (0x7E215054 - BASE_ADDRESS)
#define AUX_MU_MSR_REG    (volatile unsigned int*) (0x7E215058 - BASE_ADDRESS)
#define AUX_MU_SCRATCH    (volatile unsigned int*) (0x7E21505C - BASE_ADDRESS)
#define AUX_MU_CNTL_REG   (volatile unsigned int*) (0x7E215060 - BASE_ADDRESS)
#define AUX_MU_STAT_REG   (volatile unsigned int*) (0x7E215064 - BASE_ADDRESS)
#define AUX_MU_BAUD_REG   (volatile unsigned int*) (0x7E215068 - BASE_ADDRESS)