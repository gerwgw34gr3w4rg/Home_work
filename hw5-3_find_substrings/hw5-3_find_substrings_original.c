#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/types.h>

ssize_t find_substring(const char *text, const char *pattern);
void close_program(void *ptr_to_free_1, void *ptr_to_free_2, const char *format_message, int line_number);
bool check_limit_line(char *line);
char to_lower(char ch);
const char *get_str(const size_t MAX_STR_SIZE);

#define EVERYTHING_IS_OK 0
#define NULL_POINTER 1
#define LINE_LIMIT_REACHED 2


const char *error_message[] = {
    "",
    "Null pointer at %d line\nTo close program, press enter\n",
    "You enter more that %u characters\nTo close program, press enter\n",
};

int error_number = 0;
int line_number = 0;

int main(){
    const unsigned int LIMIT_LINE = 100;
    ssize_t number_start = (ssize_t)-1;
    fprintf(stderr, "The program checks two lines with a range of no more than %u characters"
            " (the height of the letters is not taken into account),"
            " if the second line is completely contained in the first,"
            " then the index of the place where the second line begins in"
            " the first line is displayed, otherwise -1 is displayed\n\n", LIMIT_LINE);

    const char *text = get_str(LIMIT_LINE + (size_t)2);
    const char *pattern = get_str(LIMIT_LINE + (size_t)2);
    printf("%d\n", (int)find_substring(text, pattern));
    free(text);
    free(pattern);
    getchar();
}


ssize_t find_substring(const char *text, const char *pattern){
    if(NULL == text){
        line_number = __LINE__ - 1;
        error_number = NULL_POINTER;
        return (int)-1;
    }
    if(NULL == pattern){
        line_number = __LINE__ - 1;
        error_number = NULL_POINTER;
        return (int)-1;
    }
    ssize_t number_start = -1;
    for(ssize_t i = 0, j = 0; text[i] != '\0'; i++){
        
        if(to_lower(text[i]) == to_lower(pattern[j])){
            j++;
            if((ssize_t)-1 == number_start){
                number_start = i;
            }
            if('\n' == pattern[j]){
                if('\0' == pattern[j + 1]){
                    break;
                }
            }
        }
        else{
            if((ssize_t)-1 != number_start){
                i = number_start;
                number_start = (ssize_t)-1;
                j = (ssize_t)0;
            }
        }
    }
    return (int)number_start;
}

void close_program(void *ptr_to_free_1, void *ptr_to_free_2, const char *format_message, int line_number){
    free(ptr_to_free_1);
    free(ptr_to_free_2);
    assert(NULL != format_message);
    fprintf(stderr, format_message, line_number);
    getchar();
    abort();
}

bool check_limit_line(char *line){
    if(NULL == line){
        line_number = __LINE__ -1;
        error_number = NULL_POINTER;
        return false;
    }
    assert(NULL != line);
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

char to_lower(char ch){
    if(ch >= 'A' and ch <= 'Z'){
        return ch + 'a' - 'A';
    }
    return ch;
}

const char *get_str(const size_t MAX_STR_SIZE){
    char *str = (char *)malloc(sizeof(char) * (MAX_STR_SIZE));
    if(NULL == str){
        close_program(NULL, NULL, error_message[NULL_POINTER], __LINE__ -1);
    }
    fprintf(stderr, "Enter different characters (up to %u)\n", MAX_STR_SIZE - 2);
    if(NULL == fgets(str, MAX_STR_SIZE, stdin)){
        close_program((void *)str, NULL, error_message[NULL_POINTER], __LINE__ -1);
    }

    if(EVERYTHING_IS_OK != error_number){
        close_program((void *)str, NULL, error_message[NULL_POINTER], line_number);
    }
    if(not check_limit_line(str)){
        close_program((void *)str, NULL, error_message[LINE_LIMIT_REACHED], MAX_STR_SIZE);
    }
    return (const char *)str;
    
}