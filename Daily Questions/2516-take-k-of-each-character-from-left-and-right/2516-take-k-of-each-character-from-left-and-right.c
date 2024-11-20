#include <string.h>
#include <stdbool.h>

/**
 * @brief Finds the minimum time needed to take at least k of each character ('a', 'b', 'c')
 *        from either the leftmost or rightmost sides of the string.
 *
 * @param s (char*): Input string consisting of 'a', 'b', and 'c'.
 * @param k (int): Minimum number of each character to take.
 *
 * @return (int): Minimum number of characters needed to satisfy the condition, or -1 if impossible.
 */
int takeCharacters(char* s, int k) {
    int n = strlen(s); // Length of the string
    int charCounts[3] = {0}; // Array to store the total frequency of 'a', 'b', 'c'

    // Calculate the total frequency of each character in the string
    for (int i = 0; i < n; i++) {
        charCounts[s[i] - 'a']++;
    }

    // If it's not possible to take k of any character, return -1
    if (charCounts[0] < k || charCounts[1] < k || charCounts[2] < k) {
        return -1;
    }

    // Required counts to leave behind
    int required[3] = {
        charCounts[0] - k,
        charCounts[1] - k,
        charCounts[2] - k
    };

    // Sliding window to find the largest valid substring
    int left = 0, maxValidWindow = 0;
    int currentCounts[3] = {0}; // Track counts of characters in the current window

    for (int right = 0; right < n; right++) {
        // Add the character at the right pointer to the window
        currentCounts[s[right] - 'a']++;

        // Shrink the window if the counts exceed the "required" counts
        while (currentCounts[0] > required[0] || currentCounts[1] > required[1] || currentCounts[2] > required[2]) {
            currentCounts[s[left] - 'a']--;
            left++;
        }

        // Update the size of the largest valid window
        if (right - left + 1 > maxValidWindow) {
            maxValidWindow = right - left + 1;
        }
    }

    // Minimum characters to take = Total length - Largest valid window
    return n - maxValidWindow;
}
