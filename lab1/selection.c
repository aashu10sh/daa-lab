#include "../utils.h"
#include <stdio.h>

int main(void) {

  int data[] = {41, 2, 1, 34, 5, 3, 45, 2, 3, 422, 9};
  const int data_length = sizeof(data) / sizeof(data[0]);

  printf("selection Sort!\n");

  printf("unsorted: ");
  print_array(data, data_length);

  for (int i = 0; i < data_length - 1; i++) {
    int minimum = i;
    for (int j = i; j < data_length; j++) {
      if (data[j] < data[minimum]) {
        minimum = j;
      }
    }
    if (minimum != i) {
      int temp = data[i];
      data[i] = data[minimum];
      data[minimum] = temp;
    }
  }

  printf("sorted: ");
  print_array(data, data_length);

  print_credit();
  return 0;
}