#include <stdio.h>
#include <stdlib.h>


void table_init(int *table, size_t width, size_t height);
void table_print(const int *table, size_t width, size_t height);


int main(){
    
    const size_t TABLE_SIZE = (size_t)100;
    int *multiplication_table = (int *)malloc(sizeof(int) * TABLE_SIZE);
    if(NULL == multiplication_table){
        perror("malloc");
        abort();
    }
    
    table_init(multiplication_table, TABLE_SIZE / 10, TABLE_SIZE / 10);
    table_print((const int *)multiplication_table, TABLE_SIZE / 10, TABLE_SIZE / 10);
    
    free(multiplication_table);
    multiplication_table = NULL;
    return 0;
}


void table_init(int *table, size_t width, size_t height){
    if (NULL == table){
        fprintf(stderr, "Null pointer int %s: %d\n", __FILE__, __LINE__ -1);
        abort();
    }
    for(size_t i = 0; i < height; i++){
        for(size_t j = 0; j < width; j++){
            table[i * width + j] = (i + 1) * (j + 1);
        }
    }
}
void table_print(const int *table, size_t width, size_t height){
    if (NULL == table){
        fprintf(stderr, "Null pointer int %s: %d\n", __FILE__, __LINE__ -1);
        abort();
    }
    for(size_t i = 0; i < height; i++){
        for(size_t j = 0; j < width; j++){
            printf ("%d\t", table[i * width + j]);
        }
        printf("\n");
    }    
}






