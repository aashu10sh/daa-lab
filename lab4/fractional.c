#include <stdio.h>

#include <stdlib.h>

typedef struct {
  double weight;
  double value;
}
Item;

double fractional_knapsack(int n, Item items[], double capacity) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      double value_per_weight1 = items[j].value / items[j].weight;
      double value_per_weight2 = items[j + 1].value / items[j + 1].weight;

      if (value_per_weight1 < value_per_weight2) {
        Item temp = items[j];
        items[j] = items[j + 1];
        items[j + 1] = temp;
      }
    }
  }

  double total_value = 0.0;
  int current_index = 0;

  while (capacity > 0 && current_index < n) {
    if (items[current_index].weight <= capacity) {
      capacity -= items[current_index].weight;
      total_value += items[current_index].value;
    } else {
      double fraction = capacity / items[current_index].weight;
      total_value += fraction * items[current_index].value;
      capacity = 0;
    }
    current_index++;
  }

  return total_value;
}

int main() {
  int i, n;

  printf("Enter the number of items: ");
  scanf("%d", & n);

  Item * items = (Item * ) malloc(n * sizeof(Item));
  if (items == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }

  printf("Enter the weight and value of each item:\n");
  for (i = 0; i < n; i++) {
    scanf("%lf %lf", & items[i].weight, & items[i].value);
  }

  double capacity;
  printf("Enter the capacity of the knapsack: ");
  scanf("%lf", & capacity);

  double max_value = fractional_knapsack(n, items, capacity);
  printf("Maximum value in the knapsack: %.2lf\n", max_value);

  free(items);

  puts("Ran by Aashutosh Pudasaini\n");

  return 0;
}