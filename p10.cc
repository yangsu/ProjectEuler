#include <stdio.h>
#include <string.h>
#define MAX 2000000
using namespace std;

bool test(char* bits, int index) {
  return bits[index/8] & 0x1 << (index%8);
}

void set(char* bits, int index) {
  bits[index/8] |= 0x1 << (index%8);
}

int main(int argc, char const *argv[]) {
  char bits[MAX/8+1];
  memset(bits, 0, MAX/8+1); //Clear Memory
  
  unsigned int count = 0, i = 2;
  unsigned long sum = 0, temp;
  while (i < MAX) {
    if (!test(bits, i)) { // Not present in the bitfield => Prime
      sum += i;
      count += 1;
      // Populate Multiples
      temp = i;
      while (temp < MAX) {
        set(bits, temp);
        temp += i;
      }
    }
    i += 1;
  }
  printf("%u primes, sum %lu\n", count, sum);
  return 0;
}