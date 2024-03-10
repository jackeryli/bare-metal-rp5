#include "defs.h"
#include "types.h"

/**
 * ref: xv6
*/
void*
memset(void *dst, int c, uint n)
{
  char* cdst = (char*) dst;
  int i;
  for(i=0; i<n; i++){
    cdst[i] = c;
  }
  return dst;
}

int
strncmp(const char* p, const char* q, uint n)
{
  while(n > 0 && *p && *p == *q){
    n--, p++, q++;
  }
  if(n == 0) return 0;
  return (uchar)*p - (uchar)*q;
}