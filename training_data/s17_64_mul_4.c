#include "header.h"

int   ia[64] ALIGNED16;

__attribute__((noinline))
void example21(int *in_array, int n) {
  int i, res = 1;

  for (i = n-1; i >= 0; i--)
    res *= in_array[i];

  in_array[0] = res;
}


int main(int argc,char* argv[]){
  init_memory(&ia[0], &ia[64]);
  BENCH("Example21",  example21(ia, 64), Mi/64*512, digest_memory(&ia[0], &ia[64]));
  return 0;
}