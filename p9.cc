int main(int argc, char const *argv[]) {
  unsigned int a, b, c;
  for (a = 1; a < 1000; ++a) {
    for (b = a; b < 1000; ++b) {
      for (c = b; c < 1000; ++c) {
        if(a+b+c != 1000) continue;
        if(a*a + b*b == c*c)
          printf("a:%u b:%u c:%u, product:%u\n", a, b, c, a*b*c);
      }
    }
  }
  return 0;
}