#include <stdio.h>
#include "../utils.h"

int fib(int n) {
  if (n <= 0)
    return 0;
  if (n == 1)
    return 1;

  int a = 0, b = 1, c;
  for (int i = 2; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}
int main(void) {
  const int answer = fib(21);
  printf("The Solution is %d \n", answer);
  print_credit();
  return 0;
}
