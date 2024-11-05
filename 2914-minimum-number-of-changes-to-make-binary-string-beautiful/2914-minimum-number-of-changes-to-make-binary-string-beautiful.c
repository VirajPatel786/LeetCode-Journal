#include <string.h>

/**
 * @brief Calculates the minimum number of changes required for adjacent characters
 * in the input string to be identical in pairs, using pointer arithmetic within a for loop.
 *
 * This function checks each pair of adjacent characters in the input string and counts
 * the number of mismatches, which represents the minimum number of changes needed.
 *
 * @param s (char*): Pointer to the input string to evaluate.
 * @return int: The minimum number of changes required to make each pair of adjacent characters identical.
 */
int minChanges(char* s) {
    int count = 0; // Initialize a counter for required changes

    // Use a for loop with a pointer that advances by 2 each iteration to check pairs
    for (char *ptr = s; *ptr != '\0'; ptr += 2) {
        // If current character and the next one differ, increment the count
        if (*ptr != *(ptr + 1)) {
            count++;
        }
    }

    return count; // Return the total count of changes required
}
