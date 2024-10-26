#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Finds the longest common prefix among an array of strings.
 *
 * @param strs (char**): Array of input strings.
 * @param strsSize (int): Number of strings in the array.
 *
 * @return (char*): The longest common prefix, or an empty string if none exists.
 */
char* longestCommonPrefix(char** strs, int strsSize) {
    // Edge case: if there are no strings, return an empty prefix
    if (strsSize == 0) {
        return "";
    }
    
    // Initialize the prefix with the first string
    char* prefix = strs[0];
    int prefix_len = strlen(prefix);
    
    // Loop through each string in the array, starting from the second string
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        
        // Compare characters until we find a mismatch or reach the end of one string
        while (j < prefix_len && strs[i][j] == prefix[j]) {
            j++;
        }
        
        // Update the prefix length based on the matched characters
        prefix_len = j;
        
        // If at any point the common prefix becomes empty, return immediately
        if (prefix_len == 0) {
            return "";
        }
    }
    
    // Allocate memory for the result and copy the prefix up to the matched length
    char* result = (char*)malloc((prefix_len + 1) * sizeof(char));
    strncpy(result, prefix, prefix_len);
    result[prefix_len] = '\0'; // Null-terminate the string
    
    return result;
}
