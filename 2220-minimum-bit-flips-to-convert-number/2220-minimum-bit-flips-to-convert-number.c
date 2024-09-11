#include <stdio.h>

/**
 * Function to calculate the minimum number of bit flips required to
 * convert `start` to `goal`.
 *
 * @param start (int): The initial integer.
 * @param goal (int): The target integer.
 * @return int: The number of bit flips required.
 */
int minBitFlips(int start, int goal) {
    int c = 0;

    // Continue until both 'start' and 'goal' become 0
    while (start > 0 || goal > 0) {
        // Compare the least significant bits using bitwise AND operation
        if ((start & 1) != (goal & 1)) {
            c++;  // Increment the counter if the bits are different
        }
        
        // Right shift both 'start' and 'goal' by 1 bit
        start >>= 1;
        goal >>= 1;
    }
    
    return c;
}