#include <stdlib.h>
int main (int argc, char const *argv[])
{
  int sum = 0;
  int fib1 = 1;
  int fib2 = 2;
  int temp = 0;
  int max = 4000000;
  while (fib2 <= max) {
    if (!(fib2 & 0x1)) sum += fib2;
    temp = fib1 + fib2;
    fib1 = fib2;
    fib2 = temp;
  }
  printf("sum of the even-valued terms of Fibonacci (n < %d): %d\n", max, sum);
  return 0;
}