#include<stdio.h>
#include "../utils.h"


int main(void){

  const int data[] = {41, 2, 1, 34, 5, 3, 45, 2, 3, 422, 9};
  
  const int data_length = sizeof(data) / sizeof(data[0]);

  printf("unsorted: ");
  print_array(data, data_length);
  
  printf("Insertion Sort!\n");


    print_credit();
    return 0;
}