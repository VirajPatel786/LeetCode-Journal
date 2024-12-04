#include <stdbool.h>
#include <string.h>

/**
 * @brief Determines if str2 can be a subsequence of str1 by performing at most one cyclic increment operation.
 *
 * @param str1 (char*): The original string.
 * @param str2 (char*): The target subsequence.
 * @return (bool): True if str2 can be a subsequence, False otherwise.
 */
bool canMakeSubsequence(char* str1, char* str2) {
    int n = strlen(str1);  // Length of str1
    int m = strlen(str2);  // Length of str2
    int i = 0, j = 0;      // Pointers for str1 and str2

    while (i < n && j < m) {
        // Check if str1[i] matches str2[j] either directly or with a cyclic increment
        if (str1[i] == str2[j] || ((str1[i] - 'a' + 1) % 26 + 'a') == str2[j]) {
            j++;  // Move to the next character in str2
        }
        i++;  // Always move to the next character in str1
    }

    // Return true if we've matched all characters of str2
    return j == m;
}
