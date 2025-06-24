#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <stdlib.h>

#include "scan_line_size(and_backslash_0).c"
const char *filename = "are_brackets_valid.c";


bool true_(char *open_brackets);
bool false_(char *open_brackets);


//int are_brackets_valid(const char *str, bool *are_valid){
char are_brackets_valid(const char *str){
    /*
    The function checks the correctness of the placement: ( ), { }, < >, [ ].
    Other symbols are ignored.
    */
    if(NULL == str){
        fprintf(stderr, "\nError - pointer = NULL\nName file - %s\nLine = %d\n\n"
                        "Press enter to continue executing the program\n", filename, __LINE__ - 2);
        getchar();
        return false;
    }
    size_t size_str = scan_line_size(str);
    size_t open_brackets_size = size_str / 2;
    char *open_brackets = (char *)malloc(sizeof(char) * (open_brackets_size));
    if(NULL == open_brackets){
        fprintf(stderr, "\nError - pointer = NULL\nName file - %s\nLine = %d\n\n"
                        "Press enter to continue executing the program\n", filename, __LINE__ - 2);
        getchar();
        return false;
    }

    for(size_t i = 0, j = 0; ; i++){  // scan ( ), { }, < >, [ ]
        if('\0' == str[i]){
            if(0 != j){
                false_(open_brackets);
                break;
            }
            true_(open_brackets);
            break;
        }
        else if(str[i] == '(' or str[i] == '{' or str[i] == '<' or str[i] == '['){
            if(j == open_brackets_size){
                false_(open_brackets);
                break;
            }
            if(str[i] == '('){
                open_brackets[j] = str[i] + 1;
                j++;
            }
            else{
                open_brackets[j] = str[i] + 2;
                j++;
            }
        }
        else if(str[i] == ')' or str[i] == '}' or str[i] == '>' or str[i] == ']'){
            j--;
            if(i < j){
                false_(open_brackets);
                break;
            }
            if(str[i] != open_brackets[j]){
                false_(open_brackets);
                break;
            }
            open_brackets[j] = '0';
        }
    }
}


bool true_(char *open_brackets){
    free(open_brackets);
    return true;
}

bool false_(char *open_brackets){
    free(open_brackets);
    return false;
}

