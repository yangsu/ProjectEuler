int main(int argc, char const *argv[]) {
  unsigned int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  unsigned int day = 1; //M=1 S=0 Sat=6
  unsigned int endyear = 2000;
  unsigned int count = 0;
  for (unsigned int year = 1900; year <= endyear; ++year) {
    if (year%400==0 || (year%100!=0 && year%4==0))
      month[1] = 29;
    else
      month[1] = 28;
      
    for (unsigned int j = 0; j < 12; ++j) {
      if (day == 0 && year > 1900) {
        count++;
        printf("Sunday, %02u-%02u-%4u\n", j+1, 1, year);
      }
      day = (day + month[j]%7)%7;
    }
  }
  if (day == 0) {
    count++;
    printf("Sunday, %02u-%02u-%4u\n", 12, 1, endyear);
  }
  printf("%u Sundays fell on the first of the month during the twentieth century \
  (1 Jan 1901 to 31 Dec 2000)\n", count);
  return 0;
}