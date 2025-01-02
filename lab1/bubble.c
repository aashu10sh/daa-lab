#include <stdio.h>

void bubble_sort(int data[], const int size) {
  int changed = 0;
  for (int i = 0; i < size - 1; i++) {
    for (int j = i; j < size; j++) {
      if (data[i] > data[j]) {
        const int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
        changed = 1;
      }
    }
    if (!changed) {
      break;
    }
  }
}

int main(void) {
  puts("hello world!\n");
  const int data[] = {21,3,4,6,12,5,33,1};
  const int data_length = sizeof(data) / sizeof(data[0]);

  printf("unsorted ");
  for (int i = 0; i < data_length; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");

  bubble_sort(&data, data_length);

  printf("sorted ");
  for (int i = 0; i < data_length; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");
}
