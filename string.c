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

int
strlen(const char* c)
{
  int n;
  for(n=0; c[n]; n++)
    ;
  return n;
}

void
strreverse(char* p, uint start, uint end)
{
  int n = strlen(p);
  if(n == 0) return;
  if(start >= n || end >= n) return;
  
  char tmp;
  while(start < end){
    tmp = p[start];
    p[start] = p[end];
    p[end] = tmp;
    start++;
    end--;
  }
}
