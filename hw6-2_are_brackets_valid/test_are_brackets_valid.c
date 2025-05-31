//tests

#include <stdio.h>
#include <stdbool.h>


#include "are_brackets_valid.c"


int main(){
    const char *str[] = {
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
        "{w343w4}", // true
        "[0]", // true
        "1", // true
        "                          ", // true
        "\t\n", // true
        "=-=-=_++", // true
        "#$%%^&*()", // true
        "nm,cccsd", // true

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
    };

    for(unsigned int i = 0; i < sizeof(str) / sizeof(str[0]); i++){
        are_brackets_valid(str[i]);
    }
    printf("All tests passed successfully\n");
    return 0;
}