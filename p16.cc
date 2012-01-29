#define NDIGITS 320
int main(int argc, char const *argv[]) {
  unsigned int digits[NDIGITS];
  for (unsigned int j = 1; j < NDIGITS; ++j) {
    digits[j] = 0;
  }
  digits[NDIGITS-1] = 1;
  for (unsigned int i = 1; i <= 1000; ++i) {
    for (int j = 0; j < NDIGITS; ++j) {
      if(digits[j] == 0) continue;
      unsigned int temp = digits[j] * 2;
      int offset = 0;
      while (temp) {
        if (offset == 0)
          digits[j] = temp%10;
        else
          digits[j - offset] += temp%10;
        temp /= 10;
        offset++;
      }
    }
    unsigned int sum = 0;
    for (unsigned int j = 0; j < NDIGITS; ++j) {
      sum += digits[j];
      //printf("%u ", digits[j]);
    }
    printf("2^%d\t%d\n", i, sum);
  }
  return 0;
}