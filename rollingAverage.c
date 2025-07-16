#include <stdio.h>
#include <stdlib.h>
double movingAvg(double *ptrArrNumbers, double *ptrSum, int pos, double len, double nextNum)
{
  *ptrSum = *ptrSum - ptrArrNumbers[pos] + nextNum;
  //make nextNum the next position in the input array
  ptrArrNumbers[pos] = nextNum;
  //return the average
  return *ptrSum / len;
}

int main() 
{
  //A sample of doubles to model sensor input data.
  double sample[7] = {66.7, 33.2, 3434.43, 126.77, 532.63, 75.34, 564.23};
  double filterData[3] = {0};

  int pos = 0;
  int newAvg = 0;
  double sum = 0;
  int len = sizeof(filterData) / sizeof(double);
  int count = sizeof(sample) / sizeof(double);

  for (int i = 0; i < count; i++) {
    newAvg = movingAvg(filterData, &sum, pos, len, sample[i]);
    printf("New average is %d\n", newAvg);
    pos++;
    if (pos >= len) {
      pos = 0;
    }
  }

  return 0;
}
