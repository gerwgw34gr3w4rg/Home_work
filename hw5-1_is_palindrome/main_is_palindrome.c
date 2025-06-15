#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#include "is_palindrome.c"


#define LIMIT_LINE 101 //max len is 100 + '\0' = 101


int main(){
    char *str = (char *)malloc(sizeof(char) * LIMIT_LINE);
    if(NULL == str){
        perror("malloc()");
        abort();
    }
    printf("Enter up to %d characters, then press Enter. \n", LIMIT_LINE - 1);
    assert(NULL != str);
    char* fgets_return = fgets(str, LIMIT_LINE, stdin);
    if(NULL == fgets_return){
        if(feof(stdin)){
            return 0;
        }
        perror("fgets()");
        free(str);
        abort();
    }
    if(is_palindrome((const char *)str)){
        printf("This is a palindrome\n");
    }
    else {
        printf("This is not a palindrome\n");
    }
    free(str);
    getchar();
    return 0;
}