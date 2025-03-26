#include <stdio.h>

// Function to check if there exists a subset with the given sum and print the subsets
void findSubsets(int array[], int n, int sum, int subset[], int subsetSize) {
    // If the sum is 0, print the current subset
    if (sum == 0) {
        printf("Subset with the target sum: ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    // If there are no more elements to consider or sum becomes negative, return
    if (n == 0 || sum < 0) {
        return;
    }

    // Exclude the last element and recur
    findSubsets(array, n - 1, sum, subset, subsetSize);

    // Include the last element in the current subset and recur
    subset[subsetSize] = array[n - 1];
    findSubsets(array, n - 1, sum - array[n - 1], subset, subsetSize + 1);
}

int main() {
    int array[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(array) / sizeof(array[0]);
    int target_sum = 9;
    int subset[n]; // Array to store the current subset
    int subsetSize = 0; // Initialize subset size to 0

    findSubsets(array, n, target_sum, subset, subsetSize);

    return 0;
}
