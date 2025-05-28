//tests


#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <stdlib.h>


#include "are_brackets_placed_correctly.c"


int main(){
    char *str = "1qgrt3()"; //true
    if(are_brackets_placed_correctly(str) == false){
        abort();
    }
    str = ""; //true
    if(are_brackets_placed_correctly(str) == false){
        abort();
    }
    str = "1qgrt3(()()()())"; //true
    if(are_brackets_placed_correctly(str) == false){
        abort();
    }
    str = "(1)qgrt3()"; //true
    if(are_brackets_placed_correctly(str) == false){
        abort();
    }
    str = "()"; //true
    if(are_brackets_placed_correctly(str) == false){
        abort();
    }

    str = ")1qgrt3()"; //false
    if(are_brackets_placed_correctly(str) == true){
        abort();
    }
    str = ")("; //false
    if(are_brackets_placed_correctly(str) == true){
        abort();
    }
    str = "())"; //false
    if(are_brackets_placed_correctly(str) == true){
        abort();
    }
    str = ")"; //false
    if(are_brackets_placed_correctly(str) == true){
        abort();
    }
    str = "("; //false
    if(are_brackets_placed_correctly(str) == true){
        abort();
    }
    
    printf("All tests passed successfully");

    return 0;
}