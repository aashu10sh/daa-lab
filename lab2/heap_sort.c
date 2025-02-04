#include <stdio.h>
#include "../utils.h"


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], int size, int i) {
    int largest = i;      
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        swap(&array[i], &array[largest]); 
        heapify(array, size, largest);    
    }
}

void heap_sort(int array[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    for (int i = size - 1; i > 0; i--) {
        swap(&array[0], &array[i]);

        heapify(array, i, 0);
    }
}


int main(void) {
    int array[] = {4, 5, 6, 3, 312, 0, 33}; 
    const int array_size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    print_array(array, array_size);

    heap_sort(array, array_size);

    printf("Sorted array: ");
    print_array(array, array_size);

    print_credit();

    return 0;
}