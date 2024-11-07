#include <stdint.h>

/**
 * @brief Finds the size of the largest combination with bitwise AND greater than zero.
 *
 * @param candidates (int*): Array of positive integers.
 * @param candidatesSize (int): Size of the candidates array.
 *
 * @return int: Size of the largest combination with bitwise AND greater than zero.
 */
int largestCombination(int* candidates, int candidatesSize) {
    int max_count = 0; // Variable to store the maximum count of numbers sharing a common bit set
    
    // Loop through each bit position up to 24 (sufficient for numbers up to 10^7)
    for (int bit = 0; bit < 24; ++bit) {
        int count = 0; // Count of numbers that have the current bit set
        
        // Iterate over each number in the candidates array
        for (int i = 0; i < candidatesSize; ++i) {
            // Check if the current bit position is set in the number
            if (candidates[i] & (1 << bit)) {
                count++; // Increment count if the bit is set
            }
        }
        
        // Update max_count if the current bit position has more numbers with this bit set
        if (count > max_count) {
            max_count = count;
        }
    }
    
    // Return the maximum count found across all bit positions
    return max_count;
}
