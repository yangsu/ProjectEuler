#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
  vector<unsigned int> primes;
  unsigned int num = 2, n = 0;
  bool prime;
  while (n < 10001) {
    prime  = true;
    for (unsigned int i = 0; i < primes.size(); ++i) {
      if (num%primes[i] == 0) prime = false;
    }
    if (prime) {
      primes.push_back(num);
      n++;
    }
    num++;
  }
  printf("%u\n", primes.back());
  return 0;
}