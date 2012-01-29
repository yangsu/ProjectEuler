#include <vector>
using namespace std;
bool isPalindrome(unsigned int number) {
  vector<unsigned int> digits;
  while (number) {
    digits.push_back(number % 10);
    number /= 10;
  }
  
  for (unsigned int i = 0; i < digits.size()/2; ++i) {
    if (digits[i] != digits[digits.size()-1-i]) return false;
  }
  return true;
}
int main(int argc, char const *argv[]) {
  unsigned int largestp;
  for (unsigned int i = 900; i < 1000; ++i) {
    for (unsigned int j = 900; j < 1000; ++j) {
      unsigned int product = i*j;
      if (isPalindrome(product)) largestp = product;
    }
  }
  printf("%d\n", largestp);
  return 0;
}