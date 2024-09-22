#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Reverses a string in place.
 *
 * This function reverses the input string in place by swapping characters
 * from the beginning and the end towards the center of the string.
 *
 * @param str (char*) The string to be reversed. It must be null-terminated.
 */
void reverse(char *str) {
    int n = strlen(str);  // length of the string
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];  // temporary variable to hold char during swap
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

/**
 * @brief Finds the shortest palindrome by adding the minimum characters in front of the given string.
 *
 * This function finds the shortest palindrome by adding the minimum number of characters
 * in front of the given string. It reverses the string and finds the largest palindromic
 * prefix. Then, it adds the reversed non-palindromic suffix to the front of the string.
 *
 * @param s (char*) The input string. It must be null-terminated.
 * @return (char*) A newly allocated string representing the shortest palindrome.
 * The caller is responsible for freeing the memory of the returned string.
 */
char* shortestPalindrome(char* s) {
    int len = strlen(s);  // length of the input string
    if (len == 0) 
       return strdup(s);  // Return a copy of the empty string if the input is empty

    // Reverse the string
    char rev[len + 1];  // buffer to store the reversed string
    strcpy(rev, s);
    reverse(rev);  // Reverse the string in place

    // Find the longest prefix of s that is a palindrome
    for (int i = 0; i < len; i++) {
        // Compare s with rev + i to find the largest palindromic prefix
        if (strncmp(s, rev + i, len - i) == 0) {
            // Create the shortest palindrome by appending the reverse of the suffix to the front
            int new_len = len + i;  // length of the resulting palindrome
            char *result = (char *)malloc(new_len + 1);  // Allocate memory for the result
            if (!result) return NULL;  // Handle memory allocation failure

            // Copy the part of rev that needs to be added in front
            strncpy(result, rev, i);  // Copy rev[0..i-1] to result
            // Append the original string s after the prefix
            strcpy(result + i, s);  // Copy s to result[i..new_len-1]
            result[new_len] = '\0';  // Null-terminate the result string

            return result;
        }
    }

    return strdup(s);  // If no palindrome is found, return a copy of the string itself
}