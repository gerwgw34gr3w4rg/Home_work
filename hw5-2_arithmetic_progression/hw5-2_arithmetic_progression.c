#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>


void input_int(int *value, const int MIN, const int MAX);


int main(){
    const int MIN = -1000;
    const int MAX = 1000;
    int start;
    int stop;
    int step;
    
    printf("Enter 3 numbers separated by a space with a range from %d to %d\n", MIN, MAX);
    input_int(&start, MIN, MAX);
    input_int(&stop, MIN, MAX);
    input_int(&step, MIN, MAX);
    if (0 == step){
        return 0;
    }
    else if (start < stop){
        for(; start < stop; start = start + step){
            printf("%d ", start);
        }
    }
    else{
        for(; start > stop; start = start + step){
            printf("%d ", start);
        }
    }
    printf("\n");
    getchar();
    getchar();
    return 0;
}


void input_int(int *value, const int MIN, const int MAX){
    if(NULL == value){
        fprintf(stderr, "NULL pointer at %s: %d\n", __FILE__, __LINE__);
        abort();
    }
    if(scanf("%d", value) != 1 or *value < MIN or *value > MAX){
        fprintf(stderr, "You had to enter a number in the range %d to %d\n", MIN, MAX);
        abort();
    }
}