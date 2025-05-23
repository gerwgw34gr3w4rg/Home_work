#include <stdio.h>
#include <assert.h>

#include "hw5-1_is_palindrome.c"


typedef struct {
    char input;
    char expected_output;
} TestCase;


int main(void){
    TestCase test_cases[] = {
        {.input = 'A', .expected_output = 'a'},
        {.input = 'Z', .expected_output = 'z'},
        {.input = 'C', .expected_output = 'c'},
        {.input = 'm', .expected_output = 'm'},  // Already lowercase, returned unchanged
        {.input = '9', .expected_output = '9'},  // Not a letter, returned unchanged
        {.input = '!', .expected_output = '!'},  // Punctuation, returned unchanged
    };

    size_t test_cases_size = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = (size_t)0; i < test_cases_size; i++){
        printf("in: %c out: %c expected_out: %c\n", test_cases[i].input,
                                                    to_lower(test_cases[i].input),
                                                    test_cases[i].expected_output);
        assert(to_lower(test_cases[i].input) == test_cases[i].expected_output);
        printf("\n");
    }

    printf("\n%s done!\n", __FILE__);
}
