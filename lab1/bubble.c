#include <stdio.h>
#include "../utils.h"


void bubble_sort(int data[], const int size) {
    int changed = 0;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (data[j] > data[j + 1]) {
        const int temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
        changed = 1;
      }
    }
    if (!changed) {
      printf("=> O(n) condition\n");
      break;
    }
  }
}

int main(void) {
  const int data[] = {41, 2, 1, 34, 5, 3, 45, 2, 3, 422, 9};
  const int data_length = sizeof(data) / sizeof(data[0]);

  printf("unsorted: ");
  print_array(data, data_length);
  
  bubble_sort((int * )data, data_length);

  printf("sorted: ");
  print_array(data, data_length);

  puts("Code ran by Aashutosh Pudasaini!");
}
