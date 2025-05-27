//tests


#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <stdlib.h>


#include "are_brackets_placed_correctly.c"


int main(){
    unsigned int size_str = 10;
    char *str = "1qgrt3()"; //true
    are_brackets_placed_correctly(str);
    str = ""; //true
    are_brackets_placed_correctly(str);
    str = "1qgrt3(()()()())"; //true
    are_brackets_placed_correctly(str);
    str = "(1)qgrt3()"; //true
    are_brackets_placed_correctly(str);
    str = "()"; //true
    are_brackets_placed_correctly(str);
    printf("\n");
    str = ")1qgrt3()"; //false
    are_brackets_placed_correctly(str);
    str = ")("; //false
    are_brackets_placed_correctly(str);
    str = "())"; //false
    are_brackets_placed_correctly(str);
    str = ")"; //false
    are_brackets_placed_correctly(str);
    str = "("; //false
    are_brackets_placed_correctly(str);

    return 0;
}