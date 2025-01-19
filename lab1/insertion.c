#include <stdio.h>
#include "../utils.h"

void insertion_sort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int key = array[i];  
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main(void) {
    int array[] = {12, 11, 13, 5, 6};
    int n = sizeof(array) / sizeof(array[0]);
    printf("unsorted: ");
    print_array(array, n);

    insertion_sort(array, n);

    printf("Sorted array: ");
    print_array(array, n);
    print_credit();
    return 0;
}