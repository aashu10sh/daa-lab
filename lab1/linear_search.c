#include <stdio.h>


int linear_search(const int numbers[], const int numbers_length, const int element);

int main(void) {
  const int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};

  const int numbers_length = sizeof(numbers) / sizeof(numbers[0]);

  const int to_find = 3;

  const int index = linear_search(numbers, numbers_length, to_find);

  if (index != -1) {
    printf("Found Element %d at index %d \n", to_find, index);
  } else {
    printf("Not Found Element %d \n", to_find);
  }
}

int linear_search(const int numbers[], const int numbers_length, const int element) {
  int found_index = -1;

  for (int i = 0; i < numbers_length; i++) {
    if (numbers[i] == element) {
      found_index = i;
      break;
    }
  }

  return found_index;
}