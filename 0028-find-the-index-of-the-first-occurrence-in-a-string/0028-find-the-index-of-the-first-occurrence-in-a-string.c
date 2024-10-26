#include <stdio.h>
#include <string.h>

/**
 * @brief Finds the index of the first occurrence of needle in haystack.
 *
 * @param haystack (char*): The main string in which to search.
 * @param needle (char*): The substring to find within haystack.
 *
 * @return (int): The index of the first occurrence of needle in haystack,
 *                or -1 if needle is not found.
 */
int strStr(char* haystack, char* needle) {
    // Get the lengths of haystack and needle
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);
    
    // If needle is empty, return 0 as per the problem's typical definition.
    if (needle_len == 0) {
        return 0;
    }
    
    // Loop through the haystack, stopping when there aren't enough characters
    // left to match the needle.
    for (int i = 0; i <= haystack_len - needle_len; i++) {
        // Check if the substring starting at position i matches needle.
        int j;
        for (j = 0; j < needle_len; j++) {
            if (haystack[i + j] != needle[j]) {
                break;  // Mismatch found, break out of the inner loop
            }
        }
        
        // If we've gone through the entire needle without a mismatch, return i.
        if (j == needle_len) {
            return i;
        }
    }
    
    // If needle was not found in haystack, return -1.
    return -1;
}
