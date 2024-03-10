#include "types.h"

static inline uint64
r_cntfrq_el0()
{
  uint64 x;
  asm volatile("mrs %0, cntfrq_el0": "=r" (x) );
  return x;
}

static inline uint64
r_cntpct_el0()
{
  uint64 x;
  asm volatile("mrs %0, cntpct_el0": "=r" (x) );
  return x;
}

