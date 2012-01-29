#include <stdlib.h>
#include <string.h>
#include <stdio.h>
const char* nums[] = {
  "00005",
  "00006",
  "00101"
};
char sumstr[] = "0000000";
#define MAX 4
unsigned int numDigits(unsigned int number) {
  unsigned int digits = 0;
  while (number) {
    number /= 10;
    digits++;
  }
  return digits;
}

void addToSum(unsigned int number, unsigned int pos) {
  unsigned int n = numDigits(number);
  printf("adding %u, %u digits at %u\n", number, n, pos);
  char part[MAX];
  memset(part,0,MAX);
  memcpy(part, sumstr+pos-MAX+1, MAX);
  unsigned int sum = atoi(part);
  printf("sum before: %d digits %d-%d\n", sum, pos-n+1, pos+1);
  sum += number;
  n = numDigits(sum);
  sprintf(part+MAX-n, "%d",sum);
  memcpy(sumstr+pos-MAX+1, part, MAX);
  printf("sum after: %s %s\n", part, sumstr);
}

int main(int argc, char const *argv[]) {
  int ndigits = strlen(nums[0]);
  unsigned int sumpos = strlen(sumstr)-1;
  char l;
  for (int i = ndigits-1; i >= 0; --i) {
    unsigned int sum = 0;
    for (unsigned int j = 0; j < sizeof(nums)/sizeof(char*); ++j) {
      l = nums[j][i];
      int d = atoi(&l);
      sum += d;
    }
    addToSum(sum, sumpos);
    --sumpos;
  }
  return 0;
}