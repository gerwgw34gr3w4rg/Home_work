#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "hw5-1_is_palindrome.c"


typedef struct {
    char *input;
    bool expected_output;
} TestCase;


int main(void){
    TestCase test_cases[] = {
        {.input = "         \t  A\tSanta            at NASA\t\t", .expected_output = true},
        {.input = "         \?t  A!!!\tSanta   \n -++=123        at NASA\t\t", .expected_output = true},
        {.input = "Madam, I'm Adam!", .expected_output = true},
        {.input = "q", .expected_output = true},
        {.input = "Q", .expected_output = true},
        {.input = "Qq", .expected_output = true},
        {.input = "897579A", .expected_output = false},
        {.input = "897A798", .expected_output = false},
        {.input = "8A75798", .expected_output = false},
        
        {.input = "8975798", .expected_output = false},
        {.input = "Madam Palindrome", .expected_output = false},
        {.input = "", .expected_output = false},
        {.input = "         ", .expected_output = false},
    };

    size_t test_cases_size = sizeof(test_cases) / sizeof(test_cases[0]);

    for(size_t i = 0; i < test_cases_size; i++){
        printf("input: %s\n", test_cases[i].input);
        printf("output: %d\n", (int)is_palindrome((const char *)test_cases[i].input));
        printf("expected_output: %d\n", test_cases[i].expected_output);

        assert(is_palindrome((const char *)test_cases[i].input) == test_cases[i].expected_output);
        printf("\n");
    }
    
}