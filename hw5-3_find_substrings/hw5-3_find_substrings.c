#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <stdbool.h>


bool check_NULL(bool check);
void clear_malloc(char *pointer);
bool check_limit_line(char *line, unsigned int max_size);

int main(){
    const unsigned int MAX = 100;
    int number_start = -1;
    fprintf(stderr, "The program checks two lines with a range of no more than %u characters"
            " (the height of the letters is not taken into account),"
            " if the second line is completely contained in the first,"
            " then the index of the place where the second line begins in"
            " the first line is displayed, otherwise %d is displayed\n\n", MAX, number_start);
    
    char *line_1 = (char *)malloc(sizeof(char) * (MAX + 2));
    if(check_NULL(line_1) == line_1){
        fprintf(stderr, "Error, Line %d, pointer is NULL\n", __LINE__ - 1);
        fprintf(stderr, "To close the program, press enter\n");
        getchar();
        abort();
    }
    fprintf(stderr, "Enter different characters (up to %u)\n", MAX);
    if(NULL == check_NULL(fgets(line_1, MAX + 2, stdin))){
        clear_malloc(line_1);
        fprintf(stderr, "Error, Line %d, pointer is NULL\n", __LINE__ - 1);
        fprintf(stderr, "To close the program, press enter\n");
        getchar();
        abort();
    }
    if(false == check_limit_line(line_1, MAX + 2)){
        clear_malloc(line_1);
        fprintf(stderr, "Error - you enter more than %u characters\n", MAX);
        fprintf(stderr, "To close the program, press enter\n");
        getchar();
        abort();
    }


    char *line_2 = (char *)malloc(sizeof(char) * (MAX + 2));
    if(check_NULL(line_2) == line_2){
        clear_malloc(line_1);
        fprintf(stderr, "Error, Line %d, pointer is NULL\n", __LINE__ - 1);
        fprintf(stderr, "To close the program, press enter\n");
        getchar();
        abort();
    }
    fprintf(stderr, "Enter different characters (up to %u) this will be the next line\n", MAX);
    if(NULL == check_NULL(fgets(line_2, MAX + 2, stdin))){
        clear_malloc(line_1);
        clear_malloc(line_2);
        fprintf(stderr, "Error, Line %d, pointer is NULL\n", __LINE__ - 1);
        fprintf(stderr, "To close the program, press enter\n");
        getchar();
        abort();
    }
    if(false == check_limit_line(line_2, MAX + 2)){
        clear_malloc(line_1);
        clear_malloc(line_2);
        fprintf(stderr, "Error - you enter more than %u characters\n", MAX);
        fprintf(stderr, "To close the program, press enter\n");
        getchar();
        abort();
    }

    number_start = -1;
    for(unsigned int i = 0, j = 0; line_1[i] != '\0' or line_2[j] == '\0'; i++){
        if(line_1[i] == line_2[j]){
            j++;
            if(-1 == number_start){
                number_start = i;
            }
            if('\n' == line_2[j]){
                if('\0' == line_2[j + 1]){
                    break;
                }
            }
        }
        else{
            if(-1 != number_start){
                i = number_start;
                number_start = -1;
                j = 0;
            }
        }
    }


    printf("%d\n", number_start);
    clear_malloc(line_1);
    clear_malloc(line_2);
    getchar();
    return 0;
}


bool check_NULL(bool check){
    if(0 == check){
        return 0;
    }
    return 1;
}

void clear_malloc(char *pointer){
    free(pointer);
}

bool check_limit_line(char *line, unsigned int max_size){
    max_size = max_size - 1;
    if(line[0] == '\0'){
        return true;
    }
    else if(line[max_size] == '\0' and line[max_size - 1] != '\n'){
        return false;
    }
    return true;
}