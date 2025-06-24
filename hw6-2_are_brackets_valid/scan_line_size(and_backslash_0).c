#include <stdio.h>


/*
    The function takes a pointer to a string and searches for the size of this string by \0,
    if there is no \0 in the string, the function's behavior is unpredictable!
    Do not pass a string to the function where there is no \0 !!!
*/
size_t scan_line_size(char *line){
    size_t size_line = 0;
    while(line[size_line] != '\0'){
        size_line++;
    }
    return size_line;
}
