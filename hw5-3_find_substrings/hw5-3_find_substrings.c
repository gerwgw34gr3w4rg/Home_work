#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <stdbool.h>


bool check_limit_line(char *line);
void down_registers(char *line);


int main(){
    const unsigned int LIMIT_LINE = 100;
    int number_start = -1;
    fprintf(stderr, "The program checks two lines with a range of no more than %u characters"
            " (the height of the letters is not taken into account),"
            " if the second line is completely contained in the first,"
            " then the index of the place where the second line begins in"
            " the first line is displayed, otherwise %d is displayed\n\n", LIMIT_LINE, number_start);
    
    char *line_1 = (char *)malloc(sizeof(char) * (LIMIT_LINE + 2));
    if(NULL == line_1){
        fprintf(stderr, "Error, Line %d, pointer is NULL\n", __LINE__ - 1);
        fprintf(stderr, "To close the program, press enter\n");
        getchar();
        abort();
    }
    fprintf(stderr, "Enter different characters (up to %u)\n", LIMIT_LINE);
    if(NULL == fgets(line_1, LIMIT_LINE + 2, stdin)){
        free(line_1);
        fprintf(stderr, "Error, Line %d, pointer is NULL\n", __LINE__ - 1);
        fprintf(stderr, "To close the program, press enter\n");
        getchar();
        abort();
    }
    down_registers(line_1);
    if(false == check_limit_line(line_1)){
        free(line_1);
        fprintf(stderr, "Error - you enter more than %u characters\n", LIMIT_LINE);
        fprintf(stderr, "To close the program, press enter\n");
        getchar();
        abort();
    }


    char *line_2 = (char *)malloc(sizeof(char) * (LIMIT_LINE + 2));
    if(NULL == line_2){
        free(line_1);
        fprintf(stderr, "Error, Line %d, pointer is NULL\n", __LINE__ - 1);
        fprintf(stderr, "To close the program, press enter\n");
        getchar();
        abort();
    }
    fprintf(stderr, "Enter different characters (up to %u) this will be the next line\n", LIMIT_LINE);
    if(NULL == fgets(line_2, LIMIT_LINE + 2, stdin)){
        free(line_1);
        free(line_2);
        fprintf(stderr, "Error, Line %d, pointer is NULL\n", __LINE__ - 1);
        fprintf(stderr, "To close the program, press enter\n");
        getchar();
        abort();
    }
    down_registers(line_2);
    if(false == check_limit_line(line_2)){
        free(line_1);
        free(line_2);
        fprintf(stderr, "Error - you enter more than %u characters\n", LIMIT_LINE);
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
    free(line_1);
    free(line_2);
    getchar();
    return 0;
}


bool check_limit_line(char *line){
    for(unsigned int i = 0;; i++){
        if(line[i] == '\0'){
            if(line[i - 1] == '\n'){
                return true;
            }
            break;
        }
    }
    return false;
}

void down_registers(char *line){
    for(unsigned int i = 0; line[i] != '\0'; i++){
        if(line[i] >= 'A' and line[i] <= 'Z' or line[i] >= 'А' and line[i] <= 'Я'){
            line[i] = line[i] + 32;
        }
    }
}