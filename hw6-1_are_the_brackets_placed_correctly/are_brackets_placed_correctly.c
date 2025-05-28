#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>


bool are_brackets_placed_correctly(const char *str){
    /*This function takes a string and checks for correct placement ()
    other characters are ignored

    If an invalid sequence of parentheses is found in the string
    (for example, a closing parenthesis without a corresponding opening parenthesis),
    the function immediately returns False and terminates.

    If all parentheses are placed correctly and each
    opening parenthesis has a corresponding closing parenthesis,
    the function returns True

    "()wseriu87iubn(jwhsdu76y7u76u(wuyse76uy)) == true"
    "()wseriu87iubn(23452w312!Q@$#@!Qsdu76y7u76u(wuyse76uy)) == true"
    "()(()) == true"

    ")(()) == false"
    "()(() == false"
    */

    int n = 0;
    for(unsigned int i = 0; str[i] != '\n' and str[i] != '\0'; i++){
        if('(' == str[i]){
            n++;
        }
        else if(')' == str[i]){
            n--;
        }
        if(0 > n){
            break;
        }
    }
    if(0 != n){
        return false;
    }
    return true;
}