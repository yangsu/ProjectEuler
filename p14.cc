unsigned int chain(unsigned int n) {
  int chain = 1;
  while (n > 1) {
    if (n & 0x1) n = 3*n + 1;
    else  n /= 2;
    chain++;
  }
  return chain;
}

int main (int argc, char const *argv[]) {
  unsigned int longest = 0, n = 0;
  for (unsigned int i = 0; i < 1000000; ++i) {
    unsigned int c = chain(i);
    if (c > longest) {
      n = i;
      longest = c;
    }
  }
  printf("%d has the longest chain of %d terms\n", n, longest);
  return 0;
}