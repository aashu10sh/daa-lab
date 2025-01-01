#include <stdio.h>

int gcd(int a, int b) {

  if (a == 0 || b == 0) {
    return 0;
  }

  while (b != 0) {
    const int r = a % b;
    a = b;
    b = r;
  }

  return a;
}

int main(void) {
  const int answer = gcd(21, 7);
  printf("The Solution is %d \n", answer);
  return 0;
}
