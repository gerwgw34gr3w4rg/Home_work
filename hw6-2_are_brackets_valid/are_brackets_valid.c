/*
The function checks for correct placement of: ( ), { }, < >, [ ].
Other characters are ignored.
*/


#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <stdlib.h>


bool are_brackets_valid(const char *str){
    if(NULL == str){
        fprintf(stderr, "str == NULL");
        abort();
    }
    unsigned int size_str = 0;
    for(; str[size_str] != '\0'; size_str++){

    }
    char *str1 = (char *)malloc(sizeof(char) * (size_str + 1));
    if(NULL == str1){
        fprintf(stderr, "str1 == NULL");
        abort();
    }

    for(unsigned int i = 0; str[i] != '\0'; i++){
        str1[i] = str[i];
    }
    str1[size_str] = '\0';


    unsigned int j;
    int counter = 0;
    for(unsigned i = 0; str1[i] != '\0'; i++){
        // ( ), { }, < >, [ ]
        if(str1[i] == '('){
            counter++;
        }
        else if(str[i] == '{'){
            counter++;
        }
        else if(str[i] == '<'){
            counter++;
        }
        else if(str[i] == '['){
            counter++;
        }
        else if(str1[i] == ')'){
            counter--;
            j = i;
            do{
                j--;
                if(j > i or str1[j] == '{' or str1[j] == '<' or str1[j] == '['){
                    return false;
                }
            } while(str1[j] != '(');
            str1[i] = '0';
            str1[j] = '0';
        }
        else if(str1[i] == '}'){
            counter--;
            j = i;
            do{
                j--;
                if(j > i or str1[j] == '(' or str1[j] == '<' or str1[j] == '['){
                    return false;
                }
            } while(str1[j] != '{');
            str1[i] = '0';
            str1[j] = '0';
        }
        else if(str1[i] == '>'){
            counter--;
            j = i;
            do{
                j--;
                if(j > i or str1[j] == '(' or str1[j] == '{' or str1[j] == '['){
                    return false;
                }
            } while(str1[j] != '<');
            str1[i] = '0';
            str1[j] = '0';
        }
        else if(str1[i] == ']'){
            counter--;
            j = i;
            do{
                j--;
                if(j > i or str1[j] == '(' or str1[j] == '{' or str1[j] == '<'){
                    return false;
                }
            } while(str1[j] != '[');
            str1[i] = '0';
            str1[j] = '0';
        }
    }
    if(counter != 0){
    return false;
    }
    free(str1);
    return true;
}