#include <stdio.h>
#include <stdlib.h>


int main(){
    const size_t LIMIT = 99;
    const size_t TABLE_SIZE = 81; // table of squares of numbers from 11 to 99
    int *squares_table = (int *)malloc(sizeof(int) * TABLE_SIZE);
    if(NULL == squares_table){
        perror("Error malloc");
        abort();
    }
    size_t i = 11;
    size_t j = 0;
    while(i <= LIMIT){
        if(i % 10 == 0){
            i++;
            continue;
        }
        squares_table[j] = i * i;
        j++;
        i++;
    }
    j = 0;
    while(j < TABLE_SIZE){
        printf("%d\t", squares_table[j]);
        j++;
        if(j % 9 == 0){
            printf("\n");
        }
    }
    printf("\n");
    free(squares_table);
    squares_table = NULL;
    return 0;
}