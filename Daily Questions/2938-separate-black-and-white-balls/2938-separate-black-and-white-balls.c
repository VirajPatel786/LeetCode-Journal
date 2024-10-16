#include <string.h>

/**
 * @brief Calculate the minimum number of steps to group all black balls to the right
 *        and all white balls to the left.
 *
 * @param s (char*): A binary string representing the sequence of black (1) and white (0) balls.
 *
 * @return (long long): The minimum number of swaps required.
 */
long long minimumSteps(char* s) {
    long long white_count = 0;  // Tracks the total number of swaps required
    long long min_steps = 0;    // Tracks the number of black balls encountered
    int n = strlen(s);          // Get the length of the string
    
    // Traverse the string character by character
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            // For each white ball, add the number of black balls encountered so far
            white_count += min_steps;
        } else {
            // For each black ball, increment the number of black balls encountered
            min_steps++;
        }
    }
    
    return white_count;  // Return the total number of swaps required
}
