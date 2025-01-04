#include<stdio.h>

void print_array(const int array[], const int array_size){
    for(int i=0;i<array_size;i++){
        printf("%d ", array[i]);
    }
    puts("\n");
}

void print_credit(){
    printf("Program ran by Aashutosh Pudasaini - 1202\n");
}