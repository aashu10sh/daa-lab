#include<stdio.h>
#include "../utils.h"

void min_max(const int array[], int left, int right, int *min, int *max){
    
    if (left == right){
        *min = left;
        *max = right;
        return;
    }

    if (right == left + 1){
        if (array[left] < array[right]){
            *min = array[left];
            *max = array[right];
        } else {
            *min = array[right];
            *max = array[left];
        }
        return;
    }

    int mid = (left + right)/2;

    int min1, min2, max1, max2;
    
    min_max(array, left, mid, &min1, &max1);
    min_max(array, mid + 1, right, &min2, &max2 );

    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
}


int main(void){
    const int array[] = {4,5,6,3,312,0,33};

    const int array_size = sizeof(array)/sizeof(array[0]);

    int min = 0;
    int max = 0;

    int left = 0;
    int right = array_size - 1;

    min_max(array, left, right, &min, &max);

    printf("Min: %d\n",min);
    printf("Max: %d\n",max);

    print_credit();


    return 0;
}