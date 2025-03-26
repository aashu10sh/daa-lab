#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int weights[] = {2, 3, 4, 5};
int values[] = {3, 5, 6, 10};
int n = sizeof(weights) / sizeof(weights[0]);
int capacity = 8;
int selectedItems[sizeof(weights) / sizeof(weights[0])];  // Array to store selected items

int backtrackKnapsack(int i, int currentWeight, int currentValue, int items[]) {
    if (i < 0) {
        return currentValue;
    }

    // Copy current items state to new arrays for both include and exclude paths
    int itemsWithCurrent[n];
    int itemsWithoutCurrent[n];
    for (int j = 0; j < n; j++) {
        itemsWithCurrent[j] = items[j];
        itemsWithoutCurrent[j] = items[j];
    }

    // Try including the current item
    int includeItem = 0;
    if (weights[i] <= currentWeight) {
        itemsWithCurrent[i] = 1;  // Mark the item as included
        includeItem = backtrackKnapsack(i - 1, currentWeight - weights[i], currentValue + values[i], itemsWithCurrent);
    }

    // Try excluding the current item
    int excludeItem = backtrackKnapsack(i - 1, currentWeight, currentValue, itemsWithoutCurrent);

    // Choose the option with the higher value and update selectedItems array accordingly
    if (includeItem > excludeItem) {
        for (int j = 0; j < n; j++) {
            selectedItems[j] = itemsWithCurrent[j];
        }
        return includeItem;
    } else {
        for (int j = 0; j < n; j++) {
            selectedItems[j] = itemsWithoutCurrent[j];
        }
        return excludeItem;
    }
}

int main() {
    int items[n];
    for (int i = 0; i < n; i++) {
        items[i] = 0;
    }

    int result = backtrackKnapsack(n - 1, capacity, 0, items);
    printf("Maximum value in the knapsack: %d\n", result);
    printf("Items included in the knapsack:\n");
    for (int i = 0; i < n; i++) {
        if (selectedItems[i]) {
            printf("Item %d: weight = %d, value = %d\n", i + 1, weights[i], values[i]);
        }
    }

    return 0;
}
