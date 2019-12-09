#include "header.h"

int   ia[4];
int G[128][256];
int G2[128+4][256];

__attribute__((noinline))
void example14(int in[][256], int coeff[][256], int *out) {
  int k,j,i=0;
  for (k = 0; k < 4; k++) {
    int result = 0;
    for (i = 0; i < 128; i++)
        for (j = 0; j < 256; j++)
          result += in[i+k][j] * coeff[i][j];

    out[k] = result;
  }
}

int main(int argc,char* argv[]){
  init_memory(&ia[0], &ia[4]);
  init_memory(&G[0][0], &G[0][256]);
  init_memory(&G2[0][0],&G2[0][256]);
  BENCH("Example14",  example14(G2,G,ia), 16384, digest_memory(&ia[0], &ia[4]));
  return 0;
}