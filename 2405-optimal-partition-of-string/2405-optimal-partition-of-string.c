#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Finds the minimum number of substrings with no repeating characters.
 *
 * This function partitions the input string into the smallest number of substrings
 * such that no substring contains repeated characters.
 *
 * @param s (const char*): The input string to partition.
 *
 * @return (int): The number of substrings created.
 */
int partitionString(char* s) {
    bool seen_chars[26] = {false};  /* Boolean array to track characters in the current substring */
    int count = 0;                  /* Counter for the number of substrings created */
    int i = 0;                      /* Index for iterating over the string */

    while (s[i] != '\0') {
        int idx = s[i] - 'a';  /* Calculate the index for the current character (assuming only lowercase letters) */
        
        if (seen_chars[idx]) {
            /* If the character is already in the current substring,
               start a new substring and increment the count */
            count++;
            for (int j = 0; j < 26; j++) {
                seen_chars[j] = false;  /* Clear the boolean array for the new substring */
            }
        }
        
        /* Mark the current character as seen */
        seen_chars[idx] = true;
        
        /* Move to the next character */
        i++;
    }
    
    /* Return the number of substrings (including the last one) */
    return count + 1;  /* +1 to account for the last substring */
}
