#include <stdbool.h>
#include <string.h>

/**
 * @brief Check if a permutation of s1 exists as a substring of s2.
 *
 * @param s1 (char*): The pattern string whose permutation we are checking.
 * @param s2 (char*): The text string where we are searching for the permutation of s1.
 *
 * @return bool: Returns true if a permutation of s1 exists in s2, otherwise false.
 */
bool checkInclusion(char *s1, char *s2) {
    int s1_length = strlen(s1);
    int s2_length = strlen(s2);

    // If s1 is longer than s2, no permutation can be a substring
    if (s1_length > s2_length) {
        return false;
    }

    // Arrays to store frequency counts of characters in s1 and current window in s2
    int s1_count[26] = {0};
    int s2_count[26] = {0};

    // Initialize frequency count arrays for s1 and the first window in s2
    for (int i = 0; i < s1_length; i++) {
        s1_count[s1[i] - 'a']++;
        s2_count[s2[i] - 'a']++;
    }

    // Compare s1's character frequency with the first window in s2
    if (memcmp(s1_count, s2_count, sizeof(s1_count)) == 0) {
        return true;
    }

    // Slide the window over s2, one character at a time
    for (int i = s1_length; i < s2_length; i++) {
        // Add the new character (right side of the window) to s2_count
        s2_count[s2[i] - 'a']++;

        // Remove the character that's no longer in the window (left side)
        s2_count[s2[i - s1_length] - 'a']--;

        // Compare the frequency arrays of s1 and current window of s2
        if (memcmp(s1_count, s2_count, sizeof(s1_count)) == 0) {
            return true;
        }
    }

    return false;
}
