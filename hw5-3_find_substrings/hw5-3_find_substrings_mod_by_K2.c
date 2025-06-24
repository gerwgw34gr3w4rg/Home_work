#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/types.h>


ssize_t find_substring(const char *text, const char *pattern);
void close_program(void *ptr_to_free_1, void *ptr_to_free_2, const char *format_message, int line_number_g);
bool check_line_limit(const char *line);
char to_lower(char ch);
const char *get_str(const size_t MAX_STR_SIZE);
char to_lower(char ch);
size_t str_size(const char *str);


#define EVERYTHING_IS_OK 0
#define NULL_POINTER 1
#define LINE_LIMIT_REACHED 2
#define NOT_ENOUGH_MEMORY 3

const char *error_message[] = {
    "",
    "Null pointer at %d line\nTo close program, press enter\n",
    "You enter more that %u characters\nTo close program, press enter\n",
    "Not enough of memory! line: %d\n",
};

int error_number_g = 0;
int line_number_g = 0;

int main(){
    const unsigned int LIMIT_LINE = 100;
    fprintf(stderr, "The program checks two lines with a range of no more than %u characters"
            " (the height of the letters is not taken into account),"
            " if the second line is completely contained in the first,"
            " then the index of the place where the second line begins in"
            " the first line is displayed, otherwise -1 is displayed\n\n", LIMIT_LINE);

    const char *text = get_str(LIMIT_LINE + (size_t)2);
    const char *pattern = get_str(LIMIT_LINE + (size_t)2);
    ssize_t pattern_index_in_text = find_substring(text, pattern);
    if(EVERYTHING_IS_OK != error_number_g){
        close_program((void *)text, (void *)pattern,
                        error_message[error_number_g], line_number_g);

    }
    printf("%zd\n", pattern_index_in_text);
    free((void *)text);
    free((void *)pattern);
    getchar();
}


ssize_t find_substring(const char *text, const char *pattern){
    /*
    * @brief Searches for the first occurrence of a substring within a string,
    *        using a case-insensitive Boyer-Moore-Horspool algorithm.
    *
    * This function scans the given ASCII text for the first appearance of the
    * ASCII pattern, ignoring case differences between letters. It returns the
    * zero-based index of the start of the match if found; otherwise, it returns -1.
    * If either text or pattern is NULL, the function prints an error message
    * to stderr and aborts the program.
    *
    * @param text    A pointer to the null-terminated string in which to search.
    * @param pattern A pointer to the null-terminated substring to find.
    *
    * @return The index of the first match within text, or -1 if no match is found
    *         or either input is the empty string.
    *
    * @note    The search is case-insensitive: 'A' and 'a' are considered equal.
    * @note    Empty text or pattern (i.e., first character '\0') yields -1.
    *
    * @examples
    * find_substring("Hello World", "world") -> 6
    * find_substring("OpenAI GPT-4", "GPT")  -> 7
    * find_substring("abcdef", "gh")         -> -1
    * find_substring("", "a")                -> -1
    * find_substring("a", "")                -> -1
    */
    if(NULL == text){
        line_number_g = __LINE__ - 1;
        error_number_g = NULL_POINTER;
        return (size_t)-1;
    }
    if(NULL == pattern){
        line_number_g = __LINE__ - 1;
        error_number_g = NULL_POINTER;
        return (size_t)-1;
    }
    if('\0' == *text or '\0' == *pattern){
        return (ssize_t)-1;
    }
    size_t text_size = str_size(text);
    size_t pattern_size = str_size(pattern);
    if(pattern_size > text_size){
        return -1;
    }
    const size_t ASCII_TABLE_SIZE = (size_t)128;
    size_t *shift_arr = (size_t *)malloc(sizeof(size_t) * ASCII_TABLE_SIZE);
    if(NULL == shift_arr){
        line_number_g = __LINE__ - 2;
        error_number_g = NOT_ENOUGH_MEMORY;
        return (size_t)-1;
    }
    for(size_t i = 0; i < ASCII_TABLE_SIZE; i++){
        shift_arr[i] = pattern_size;
    }
    for(size_t i = 0; i < pattern_size - 1; i++){
        size_t lowercase_letter_index = (size_t)to_lower(pattern[i]);
        shift_arr[lowercase_letter_index] = pattern_size - i - 1;
    }
    size_t i = 0;
    while(i <= text_size - pattern_size){
        size_t j = 0;
        while(to_lower(text[i + j]) == to_lower(pattern[j])){
            j++;
            if(j == pattern_size){
                return (ssize_t)i;
            }
        }
        size_t lowercase_letter_index = (size_t)to_lower(text[i + pattern_size - 1]);
        i = i + shift_arr[lowercase_letter_index];
    }

    free(shift_arr);
    return (ssize_t)-1;
}

void close_program(void *ptr_to_free_1, void *ptr_to_free_2, const char *format_message, int line_number_g){
    free(ptr_to_free_1);
    free(ptr_to_free_2);
    assert(NULL != format_message);
    fprintf(stderr, format_message, line_number_g);
    getchar();
    abort();
}

bool check_line_limit(const char *line){
    if(NULL == line){
        line_number_g = __LINE__ - 1;
        error_number_g = NULL_POINTER;
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


const char *get_str(const size_t MAX_STR_SIZE){
    char *str = (char *)malloc(sizeof(char) * (MAX_STR_SIZE));
    if(NULL == str){
        close_program(NULL, NULL, error_message[NULL_POINTER], __LINE__ - 1);
    }
    fprintf(stderr, "Enter different characters (up to %u)\n", MAX_STR_SIZE - 2);
    if(NULL == fgets(str, MAX_STR_SIZE, stdin)){
        close_program((void *)str, NULL, error_message[NULL_POINTER], __LINE__ - 1);
    }

    if(EVERYTHING_IS_OK != error_number_g){
        close_program((void *)str, NULL, error_message[NULL_POINTER], line_number_g);
    }
    if(not check_line_limit(str)){
        close_program((void *)str, NULL, error_message[LINE_LIMIT_REACHED], MAX_STR_SIZE);
    }
    size_t str_size_ = str_size(str);
    if('\n' == str[str_size_ - 1]){
        str[str_size_ - 1]= '\0';
    }
    return (const char *)str;
}

char to_lower(char ch){
    /**
    * @brief Converts an uppercase ASCII letter to its lowercase equivalent.
    *
    * This function takes a single character as input and returns its lowercase form
    * if the character is an uppercase English letter (i.e., 'A' to 'Z').
    * If the character is not an uppercase letter, it is returned unchanged.
    *
    * The conversion follows the ASCII standard, where uppercase letters 'A'-'Z'
    * correspond to values 65–90 and lowercase letters 'a'-'z' correspond to 97–122.
    * The function converts by adding 32 ('a' - 'A') to the ASCII value of the uppercase letter.
    *
    * @param ch A character to convert.
    *
    * @return The lowercase equivalent of the character if it is uppercase;
    *         otherwise, the original character.
    *
    * @examples
    * lower('A') -> 'a'
    * lower('Z') -> 'z'
    * lower('C') -> 'c'
    * lower('m') -> 'm'   // Already lowercase, returned unchanged
    * lower('9') -> '9'   // Not a letter, returned unchanged
    * lower('!') -> '!'   // Punctuation, returned unchanged
    */
    if (ch >= 'A' and ch <= 'Z'){
        return ch + 'a' - 'A';
    }
    return ch;
}

size_t str_size(const char *str){
    /**
    * @brief Calculates the length of a null-terminated C string.
    *
    * This function returns the number of characters in the input string,
    * excluding the null terminator ('\0').
    *
    * If the input pointer is NULL, the function prints an error message
    * to stderr indicating the file and line where the null pointer was detected,
    * and then terminates the program using abort().
    *
    * @param str A pointer to a null-terminated C string.
    *
    * @return The number of characters in the string (not including the null terminator).
    *
    * @note This function is designed for ASCII or UTF-8 strings where characters are
    *       represented by single bytes. It does not support wide or multibyte characters.
    *
    * @warning Passing a NULL pointer will cause the program to terminate.
    *
    * @examples
    * str_size("Hello")         -> 5
    * str_size("")              -> 0
    * str_size("OpenAI GPT-4")  -> 12
    * str_size(NULL)            -> Program aborts with an error message
    */
    if (NULL == str){
        fprintf(stderr, "Null pointer at %s: %d\n", __FILE__, __LINE__ - 1);
        abort();
    }
    size_t size = 0;
    for (size_t i = 0; str[i] != '\0'; i++){
        size++;
    }
    return size;
}