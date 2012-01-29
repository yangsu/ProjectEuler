  unsigned int nums[] = {
    3,//one
    3,//two
    5,//three
    4,//four
    4,//five
    3,//six
    5,//seven
    5,//eight
    4//nine
  };
  unsigned int teens[] = {
    6,//eleven
    6,//twelve
    8,//thirteen
    8,//fourteen
    7,//fifteen
    7,//sixteen
    9,//seventeen
    8,//eighteen
    8,//nineteen
  };  
  unsigned int tens[] = {
    3,//ten
    6,//twenty
    6,//thirty
    5,//forty
    5,//fifty
    5,//sixty
    7,//seventy
    6,//eighty
    6,//ninety
  };  
  unsigned int hundred = 7;
  unsigned int thousand = 8;
  unsigned int _and = 3;

unsigned int numLetters(unsigned int n) {
  unsigned int letters = 0;
  
  unsigned int h = n/100;
  if (n%100 == 0) {
    letters += nums[h-1] + hundred;
  }
  else {
    if (h > 0) 
      letters += nums[h-1] + hundred + _and;
    
    unsigned int t = n%100;
    if (t < 10)
      letters += nums[t-1];
    else if (t > 10 && t < 20)
      letters += teens[t-11];
    else {
      letters += tens[t/10-1];
      if (t%10 > 0)
        letters += nums[t%10-1];
    }    
  }
  printf("%u: %u letters\n", n, letters);
  return letters;
}
int main(int argc, char const *argv[]) {

  unsigned int totalletters = 0;
  unsigned int last = 999;
  for (unsigned int i = 1; i <= last; ++i) {
    totalletters += numLetters(i);
  }
  totalletters += 3 + thousand;
  
  printf("%u letters used in writing numbers from 1 to 1000 in words\n", 
          totalletters);
  return 0;
}