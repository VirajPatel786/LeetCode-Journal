#include <stdio.h>

/**
 * @brief Finds the minimum number of substrings with no repeating characters.
 *
 * This function partitions the input string into the smallest number of substrings
 * such that no substring contains repeated characters. It uses bit manipulation
 * to efficiently track the seen characters.
 *
 * @param s (const char*): The input string to partition.
 *
 * @return (int): The number of substrings created.
 */
int partitionString(const char *s) {
    int seen = 0;  /* Bitmask to track characters in the current substring (0 indicates unseen) */
    int count = 0; /* Counter for the number of substrings created */
    int i = 0;     /* Index for iterating over the string */
    
    while (s[i] != '\0') {
        int bit_position = s[i] - 'a';  /* Calculate the bit position for the current character */
        
        /* If the bit for the current character is already set, start a new substring */
        if (seen & (1 << bit_position)) {
            count++;    /* Increment the substring count */
            seen = 0;   /* Reset the bitmask for the new substring */
        }
        
        /* Set the bit for the current character */
        seen |= (1 << bit_position);
        
        /* Move to the next character */
        i++;
    }
    
    /* Return the number of substrings (including the last one) */
    return count + 1;  /* +1 to account for the last substring */
}