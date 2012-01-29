#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
  vector<unsigned int> primes;
  unsigned int num = 2, n = 0, sum = 2;
  bool prime;
  while (num < 200000) {
    if(num & 0x1 == 0) {
      num++;
      continue;
    }
    prime  = true;
    for (unsigned int i = 0; i < primes.size(); ++i) {
      if (num%primes[i] == 0) {
        prime = false;
        break;
      }
    }
    if (prime) {
      primes.push_back(num);
      sum += num;
      n++;
    }
    num++;
  }
  printf("last of %d primes: %u sum %u\n", primes.size(), primes.back(), sum);
  return 0;
}