#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "hw5-1_is_palindrome.c"

typedef struct {
    char input;
    bool expected_output;
} TestCase;

int main(void){
    TestCase test_cases[] = {
        {.input = 'A', .expected_output = true},
        {.input = 'z', .expected_output = true},
        {.input = 'M', .expected_output = true},
        {.input = '5', .expected_output = false},
        {.input = '#', .expected_output = false},
        {.input = ' ', .expected_output = false},
    };

    size_t test_cases_size = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for(size_t i = 0; i < test_cases_size; i++){
        printf("in: %c out: %d expected: %d\n", test_cases[i].input, is_alpha(test_cases[i].input), test_cases[i].expected_output);
        assert (is_alpha(test_cases[i].input) == test_cases[i].expected_output);
        printf("\n");
    }
    printf("\n%s done!\n", __FILE__);
}

