#include <stdio.h>
#include <assert.h>


#include "hw5-1_is_palindrome.c"


typedef struct{
    char *input;
    size_t expected_output;
} TestCase;

int main(void){
    TestCase test_cases[] = {
        {.input = "Hello", .expected_output = 5},
        {.input = "", .expected_output = 0},
        {.input = "OpenAI GPT-4", .expected_output = 12},
    };

    size_t test_cases_size = sizeof(test_cases) / sizeof(test_cases[0]);

    for(size_t i = 0; i < test_cases_size; i++){
        printf("input: %s\n", test_cases[i].input);
        printf("output: %u\n", (unsigned)str_size(test_cases[i].input));
        printf("expected output: %u\n", (unsigned)test_cases[i].expected_output);
        assert(str_size(test_cases[i].input) == test_cases[i].expected_output);
        printf("\n");
    }

    printf("\n%s done!\n", __FILE__);
}