#include <stdio.h>
#include <stdlib.h>

int main(){
    const int STOP = 99; // table of squares of numbers up to 99
    int *arr = (int *)malloc(sizeof(int) * STOP + 1);
    if(NULL == arr){
        printf("Error malloc");
        abort();
    }
    int i = 0;
    while(i <= STOP){
        arr[i] = i * i;
        i++;
    }
    i = 0;
    while(i <= STOP){
        printf("%d\t", arr[i]);
        i++;
        if(i % 10 == 0){
            printf("\n");
        }
    }
    free(arr);
    printf("\n");
    return 0;
}