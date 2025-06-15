//tests

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#include "are_brackets_valid.c"


int main(){
    // test true
    const char *str_true[] = {
        "wks98iughj(){}<>wqe3", // true
        "iuedy87iu()(ywjhn<222{[eeee]}>)", // true
        "09({[<..>]})", // true
        "", // true
        "{}", // true
        "()", // true
        "<>", // true
        "12445", // true
        " ", // true
        "rth54", // true
        "( we4387)", // true
        "<w34rgw3>", // true
        "{w343\nw4}", // true
        "[0]", // true
        "1", // true
        "                          ", // true
        "\t\n", // true
        "=-=-=_++", // true
        "#$%%^&*()", // true
        "nm,cccsd", // true
    };

    // test false
    const char *str_false[] = {
        ")", // false
        "}", // false
        "]", // false
        ">", // false
        "w24243322q)", // false
        "ghrth)(", // false
        "3w42<)", // false
        "wesiu909878)))))", // false
        "ewrgw234<>{[]})", // false
        "uhw398oyuyg}", // false
        "w34gw23q23>", // false
        "mn,,,,,,       \t } 78uhw2i9-00i", // false
        "[[[[]]]]]", // false
        "[[[[]]]])", // false
        ")[[[[[]]]]]", // false
        ">]})", // false
        "<", // false
        "(", // false
        "[", // false
        "{", // false
        "546789-0,<", // false
        "({)}", // false
        "<(>)", // false
    };

    // check test true
    for(unsigned int i = 0; i < sizeof(str_true) / sizeof(str_true[0]); i++){
        if(are_brackets_valid(str_true[i]) != true){
            fprintf(stderr, "Error %s = false, line = %d", str_true[i], __LINE__ - 1); 
            abort();
        }
    }
    // check test false
    for(unsigned int i = 0; i < sizeof(str_false) / sizeof(str_false[0]); i++){
        if(are_brackets_valid(str_false[i]) != false){
            fprintf(stderr, "Error %s = true, line = %d", str_false[i], __LINE__ - 1); 
            abort();
        }
    }

    printf("All tests passed successfully\n");
    getchar();
    return 0;
}