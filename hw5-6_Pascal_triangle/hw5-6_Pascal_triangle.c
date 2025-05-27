#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>


//void input_and_check((int *)num, const int NUM_MIN, const int NUM_MAX); почему не работает???
void input_and_check(int *num, const int NUM_MIN, const int NUM_MAX);
void filling_and_printing(unsigned long long *arr, int height, int width);


int main(){
    const int NUM_MIN = 1;
    const int NUM_MAX = 100;
    int height;
    int width;
    
    input_and_check(&height, NUM_MIN, NUM_MAX);
    input_and_check(&width, NUM_MIN, NUM_MAX);
    
    unsigned long long *arr = (unsigned long long *)malloc((unsigned long long)height * (unsigned long long)width);

    filling_and_printing(arr, height, width);
    return 0;
}


void filling_and_printing(unsigned long long *arr, int height, int width){
    size_t index = 0;
    for(;index < width; index++){
        arr[index] = 1;
    }
    for(; index < height * width; index++){
        if(index % width == 0){
            arr[index] = 1;
        }
        else {
            arr[index] = arr[index - 1] + arr[index - width];
        }
    }
    index = 0;
    for(; index < height * width; index++){
        if(index % width == 0){
            printf("\n");
        }
        printf("%llu\t", arr[index]);
    }
}

void input_and_check(int *num, const int NUM_MIN, const int NUM_MAX){
    printf("enter from %d to %d\n", NUM_MIN, NUM_MAX);
    if(scanf("%d", num) != 1){
        fprintf(stderr, "input is invalid\n");
        abort();
    }
    if(*num < NUM_MIN or *num > NUM_MAX){
        printf("input is invalid\n");
        abort();
    }
}