#include <stdio.h>
#include "../utils.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int left, int right) {
    int pivot = array[right]; 
    int i = left - 1;         

    for (int j = left; j < right; j++) {
        if (array[j] <= pivot) {
            i++; 
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[right]);
    return i + 1;
}

void quick_sort(int array[], int left, int right) {
    if (left < right) {
        int pivot_index = partition(array, left, right);

        quick_sort(array, left, pivot_index - 1);
        quick_sort(array, pivot_index + 1, right);
    }
}


int main(void) {
    int array[] = {4, 5, 6, 3, 312, 0, 33}; 
    const int array_size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    print_array(array, array_size);

    int left = 0;
    int right = array_size - 1;

    quick_sort(array, left, right);

    printf("Sorted array: ");
    print_array(array, array_size);

    print_credit();

    return 0;
}