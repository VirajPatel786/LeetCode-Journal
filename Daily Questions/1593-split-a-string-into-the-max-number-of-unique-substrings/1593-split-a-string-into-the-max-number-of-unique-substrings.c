#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to check if a substring exists in the set of unique substrings
bool is_unique(char* substrings[], char* substring, int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(substrings[i], substring) == 0) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Backtracking function to explore maximum unique splits.
 *
 * @param s (char*): The input string.
 * @param start (int): The starting index for the current split.
 * @param substrings (char*[]): The set of unique substrings to check.
 * @param count (int): The number of unique substrings.
 *
 * @return int: The maximum number of unique splits.
 */
int backtrack(char* s, int start, char* substrings[], int count, int max_len) {
    // If we've reached the end of the string, return 0 because no more splits are possible
    if (start == max_len) {
        return 0;
    }

    int max_splits = 0;
    char temp[17]; // Temporary buffer for substrings (max length is 16)
    
    // Try all possible substrings starting from index `start`
    for (int end = start + 1; end <= max_len; end++) {
        strncpy(temp, s + start, end - start);  // Copy the substring from start to end
        temp[end - start] = '\0';  // Null-terminate the string
        
        if (is_unique(substrings, temp, count)) {
            // Add substring to the set
            substrings[count] = strdup(temp);  
            
            // Recurse for the remaining part of the string and count this split
            int splits = 1 + backtrack(s, end, substrings, count + 1, max_len);
            if (splits > max_splits) {
                max_splits = splits;
            }
            
            // Backtrack: Remove the substring from the set
            free(substrings[count]);
        }
    }

    return max_splits;
}

/**
 * @brief Function to find the maximum number of unique substrings that the string can be split into.
 *
 * @param s (char*): The input string.
 *
 * @return int: The maximum number of unique substrings.
 */
int maxUniqueSplit(char* s) {
    int max_len = strlen(s);
    char* substrings[16];  // Array to store unique substrings (max 16 substrings since max length is 16)
    
    return backtrack(s, 0, substrings, 0, max_len);
}
