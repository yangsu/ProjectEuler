#include <stdio.h>
unsigned int factorCountOfNthTriNum(unsigned int n) {
  unsigned int trinum = (1 + n) * n/2;
  unsigned int factorCount = 1;
  for (unsigned int j = 2; j <= trinum; ++j) {
    if (trinum%j == 0) ++factorCount;
  }
  printf("%d %d\n", trinum, factorCount);
  return factorCount;
}
int main (int argc, char const *argv[]) {
  unsigned int fn = 0, n = 1;
  do {
    fn = factorCountOfNthTriNum(n);
    ++n;
  } while(fn < 500);
  printf("%d\n", fn);
  return 0;
}