#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
  vector<unsigned int> primes;
  unsigned int num = 2;
  long starting = 600851475143;
  bool prime;
  while (starting > 1 && num <= starting) {
    prime  = true;
    for (unsigned int i = 0; i < primes.size(); ++i) {
      if (num%primes[i] == 0) {
        prime = false;
        break;
      }
    }
    if (prime) {
      primes.push_back(num);
      while (starting%num == 0)
        starting /= num;
    }
    num++;
  }
  printf("%u\n", primes.back());
  return 0;
}