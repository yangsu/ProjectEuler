#include <stdlib.h>
int main (int argc, char const *argv[])
{
  unsigned int sumsquares = 0;
  unsigned int squaressum = 0;
  unsigned int max = 100;
  for(size_t i = 1; i <= 100; ++i)
  {
    sumsquares += (i * i);
    squaressum += i;
  }
  squaressum *= squaressum;
  printf("the difference between the diff of the squares of the %d hundred \
          natural numbers and the square of the diff: %d\n", max, 
          squaressum - sumsquares);
  return 0;
}