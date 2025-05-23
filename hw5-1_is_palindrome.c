#include <stdbool.h>
#include <iso646.h>


char to_lower(char ch){
    /*
    * @brief Converts an uppercase ASCII letter to its to_lowercase equivalent.
    *
    * This function takes a single character as input and returns its to_lowercase form
    * if the character is an uppercase English letter (i.e., 'A' to 'Z').
    * If the character is not an uppercase letter, it is returned unchanged.
    *
    * The conversion follows the ASCII standard, where uppercase letters 'A'-'Z'
    * correspond to values 65–90 and to_lowercase letters 'a'-'z' correspond to 97–122.
    * The function converts by adding 32 ('a' - 'A') to the ASCII value of the uppercase letter.
    *
    * @param ch A character to convert.
    *
    * @return The to_lowercase equivalent of the character if it is uppercase;
    *         otherwise, the original character.
    *
    * @examples
    * to_lower('A') -> 'a'
    * to_lower('Z') -> 'z'
    * to_lower('C') -> 'c'
    * to_lower('m') -> 'm'   // Already to_lowercase, returned unchanged
    * to_lower('9') -> '9'   // Not a letter, returned unchanged
    * to_lower('!') -> '!'   // Punctuation, returned unchanged
    */
    if(ch >= 'A' and ch <= 'Z'){
        return ch + 'a' - 'A';
    }
    return ch;
}

bool is_alpha(char ch){
    /*
    * @brief Determines whether a character is an ASCII alphabetic letter.
    *
    * This function checks whether the given character is an English letter,
    * either uppercase ('A'–'Z') or lowercase ('a'–'z'), based on its ASCII value.
    *
    * The ASCII values checked are:
    *   - Uppercase letters: 65 ('A') to 90 ('Z')
    *   - Lowercase letters: 97 ('a') to 122 ('z')
    *
    * Any other character, including digits, punctuation, or special symbols, 
    * is considered non-alphabetic and will return false.
    *
    * @param ch The character to evaluate.
    *
    * @return true if the character is an ASCII alphabetic letter; false otherwise.
    *
    * @examples
    * is_alpha('A') -> true
    * is_alpha('z') -> true
    * is_alpha('M') -> true
    * is_alpha('5') -> false   // Digit
    * is_alpha('#') -> false   // Symbol
    * is_alpha(' ') -> false   // Whitespace
    */
    if(ch >= 'A' and ch <= 'Z' or ch >= 'a' and ch <= 'z'){
        return true;
    }
    return false;
}

bool is_palindrome(const char *str){
    /*
    * @brief Determines whether a given input string is a palindrome.
    *
    * A palindrome is a sequence that reads the same forward and backward.
    * This function checks if the input string meets that criterion with the following considerations:
    *
    * - The comparison is case-insensitive; uppercase and to_lowercase letters are treated the same.
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