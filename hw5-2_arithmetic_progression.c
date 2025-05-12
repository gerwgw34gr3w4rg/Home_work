#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>


void error_press_key(int limit_min, int limit_max);


int main(){
    int limit_min = -1000;
    int limit_max = 1000;
    int start;
    int stop;
    int step;
    
    printf("Enter 3 numbers separated by a space with a range from %d to %d\n", limit_min, limit_max);
    if(scanf("%d", &start) != 1 or start < limit_min or start > limit_max){
        error_press_key(limit_min, limit_max);
    }
    if(scanf("%d", &stop) != 1 or stop < limit_min or stop > limit_max){
        error_press_key(limit_min, limit_max);
    }
    if(scanf("%d", &step) != 1 or step < limit_min or step > limit_max){
        error_press_key(limit_min, limit_max);
    }
    if (step < 0){
        step = step * -1;
    }
    if (0 == step){
        
    }
    else if (start < stop){
        for(; start < stop; start = start + step){
            printf("%d ", start);
        }
    }
    else if (start > stop){
        for(; start > stop; start = start - step){
            printf("%d ", start);
        }
    }
    printf("\n");
    return 0;
}


void error_press_key(int limit_min, int limit_max){
    printf("You had to enter a number in the range %d to %d\n", limit_min, limit_max);
    abort();
}