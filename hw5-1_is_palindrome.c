#include <stdbool.h>


char lower(char ch){
    /**
    * @brief Converts an uppercase ASCII letter to its lowercase equivalent.
    *
    * This function takes a single character as input and returns its lowercase form
    * if the character is an uppercase English letter (i.e., 'A' to 'Z').
    * If the character is not an uppercase letter, it is returned unchanged.
    *
    * The conversion follows the ASCII standard, where uppercase letters 'A'-'Z'
    * correspond to values 65–90 and lowercase letters 'a'-'z' correspond to 97–122.
    * The function converts by adding 32 ('a' - 'A') to the ASCII value of the uppercase letter.
    *
    * @param ch A character to convert.
    *
    * @return The lowercase equivalent of the character if it is uppercase;
    *         otherwise, the original character.
    *
    * @examples
    * lower('A') -> 'a'
    * lower('Z') -> 'z'
    * lower('C') -> 'c'
    * lower('m') -> 'm'   // Already lowercase, returned unchanged
    * lower('9') -> '9'   // Not a letter, returned unchanged
    * lower('!') -> '!'   // Punctuation, returned unchanged
    */
    return ch;
}


bool is_palindrome(const char *str){
    /*
    * @brief Determines whether a given input string is a palindrome.
    *
    * A palindrome is a sequence that reads the same forward and backward.
    * This function checks if the input string meets that criterion with the following considerations:
    *
    * - The comparison is case-insensitive; uppercase and lowercase letters are treated the same.
    * - Only alphabetic letters (A-Z, a-z) are considered in the comparison.
    * - Non-letter characters (e.g., digits, punctuation, whitespace) are ignored.
    * - An empty string is considered a not valid palindrome.
    *
    * Example cases:
    *   is_palindrome("A Santa at NASA")           -> true
    *   is_palindrome("Madam, I'm Adam!")          -> true
    *   is_palindrome("8975798")                   -> false
    *   is_palindrome("Madam Palindrome")          -> false
    *
    * @param str A null-terminated C string (const char *) to be evaluated.
    *            The input is assumed to be no longer than 100 characters.
    *
    * @return true if the input string is a palindrome under the rules above,
    *         false otherwise.
    */
    return true;
}