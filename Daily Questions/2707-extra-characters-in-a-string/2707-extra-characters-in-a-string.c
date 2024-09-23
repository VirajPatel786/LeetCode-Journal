#include <stdio.h>
#include <string.h>
#include <limits.h>

/**
 * @brief Calculates the minimum number of extra characters needed to represent
 *        the string `s` using words from the `dictionary`.
 *
 * @param s (char*): The input string to process.
 * @param dictionary (char**): The dictionary containing words that can be used to represent the string.
 * @param dictionarySize (int): The size of the dictionary (number of words).
 * @return (int): The minimum number of extra characters left after forming the string using the words from the dictionary.
 */
int minExtraChar(char * s, char ** dictionary, int dictionarySize) {
    int sLength = strlen(s);
    int dp[sLength + 1]; // dp[i] stores the minimum extra chars for s[:i]
    
    // Initialize dp array
    dp[0] = 0;
    for (int i = 1; i <= sLength; i++) {
        dp[i] = dp[i - 1] + 1; // Default: no match means 1 extra character
        
        // Check all words in the dictionary for matching substring ending at i
        for (int j = 0; j < dictionarySize; j++) {
            int wordLength = strlen(dictionary[j]);
            if (i >= wordLength && strncmp(s + i - wordLength, dictionary[j], wordLength) == 0) {
                dp[i] = dp[i] < dp[i - wordLength] ? dp[i] : dp[i - wordLength];
            }
        }
    }
    
    return dp[sLength];
}