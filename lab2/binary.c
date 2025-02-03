#include<stdio.h>

int binary_search(const int array[], const int left, const int right, const int to_find){
    if ( left > right ){
        return -1;
    }

    const int mid = left + ( right - left ) / 2;

    if (array[mid] == to_find){
        return mid;
    }

    if (to_find < array[mid]) {
        return binary_search(array, left, mid - 1, to_find);
    } else {
        return binary_search(array, mid + 1, right, to_find );
    }

    return -1;
}
int main(void){
    const int array[] = {1,2,3,4,5,6,7,8,9,10};
    const int array_length = sizeof(array)/sizeof(array[0]);

    const int index = binary_search(array, 0, array_length - 1 , 7);

    if (index == -1){
        printf("failed to find! \n");
        return 0;
    }

    printf("found: %d\n",index);
    return 0;
}

