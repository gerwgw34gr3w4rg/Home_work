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
    char *arr = (char *)malloc(sizeof(char) * 128); // 128 == Size table ASCII
    if(NULL == arr){
        fprintf(stderr, "Error pointer arr == NULL. Error line = %d\nPress Enter to terminate the program\n", __LINE__);
        getchar();
        abort();
    }
    
    size_t time_box;
    for(size_t i = 0; ; i++){
        if(pattern[i] == '\0'){
            if(pattern[i - 1] == '\n'){
                time_box = i - 1;
                break;
            }
            printf("Input limit exceeded\nPress Enter to terminate the program\n");
            getchar();
            free(arr);
            abort();
        }
    }

    for(size_t i = 0; i < 128; i++){ // filling an array ASCII = time_box
        arr[i] = time_box;
    }

    for(size_t i = 0; i < time_box - 1; i++){
        arr[pattern[i]] = time_box - 1 - i;

    }
    size_t size_text = 0;
    for(size_t i = 0; text[i] != '\0'; i++){
        size_text = i;
    }
    for(size_t i = 0, j = 0; i < size_text; i++, j++){ // scaning
        if(pattern[j] == '\n' and pattern[j + 1] == '\0'){
            break;
        }
        else if(text[i] == '\n' and text[i + 1] == '\0' and pattern[j] != '\n'){
            number_start = -1;
            break;
        }
        if(text[i] == pattern[j]){
            if(number_start == -1){
                number_start = i;
            }
        }
        else{
            if(number_start == -1){
                number_start = i;
            }
            i = number_start + arr[text[number_start + time_box - 1]] - 1;
            number_start = -1;
            j = -1;
        }
    }
    
    free(arr);
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