#define NDIGITS 320 
unsigned int digits[NDIGITS];
void addNumAtLoc(unsigned int num, unsigned int i) {
  int offset = 0;
  while (num) {
    if (offset == 0)
      digits[i] = num%10;
    else {
      digits[i - offset] += num%10;
      if (digits[i - offset] >= 10)          
        addNumAtLoc(digits[i - offset], i - offset);
    }
    num /= 10;
    offset++;
  }
}
int main(int argc, char const *argv[]) {
 
  for (unsigned int j = 1; j < NDIGITS; ++j) {
    digits[j] = 0;
  }
  digits[NDIGITS-1] = 1;
  for (unsigned int i = 1; i <= 100; ++i) {
    for (int j = 0; j < NDIGITS; ++j) {
      if(digits[j] == 0) continue;
      unsigned int temp = digits[j] * i;
      addNumAtLoc(temp, j);
    }
    unsigned int sum = 0;
    printf("%d!\t", i);
    for (unsigned int j = 0; j < NDIGITS; ++j) {
      sum += digits[j];
      //printf("%u", digits[j]);
    }
    printf("\tsum of digits %u\n", sum);
  }
  return 0;
}