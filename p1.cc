#include <stdlib.h>
int main (int argc, char const *argv[])
{
  unsigned int sum = 0;
  unsigned int max = 1000;
  for(size_t i = 1; i < max; ++i)
  {
    if (i%3 == 0 || i%5 == 0)
      sum = sum + i;
  }
  printf("sum of all the multiples of 3 or 5 below %d: %d\n", max, sum);
  return 0;
}