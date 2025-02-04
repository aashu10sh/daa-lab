#include "../utils.h"
#include<stdio.h>



void swap(int * a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;    

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}



void merge_sort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; 

        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}



int main(void){
    int array[] = {4,5,6,3,312,0,33};
    const int array_size = sizeof(array)/sizeof(array[0]);

    puts("original array: ");
    print_array(array, array_size);


    int left = 0;
    int right = array_size - 1;

    merge_sort(array, left, right);

    puts("sorted array: ");
    print_array(array, array_size);
    print_credit();
    return 0;
}