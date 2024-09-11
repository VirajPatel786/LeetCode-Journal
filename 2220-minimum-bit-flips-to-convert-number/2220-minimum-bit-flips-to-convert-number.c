#include <stdio.h>

/**
 * Function to calculate the minimum number of bit flips required to
 * convert `start` to `goal` using XOR and bitwise operations.
 *
 * @param start (int): The initial integer.
 * @param goal (int): The target integer.
 * @return int: The number of bit flips required.
 */
int minBitFlips(int start, int goal) {
    int xor_result = start ^ goal;  // XOR to get differing bits
    int count = 0;
    
    // Count the number of 1's in the XOR result
    while (xor_result > 0) {
        count += (xor_result & 1);  // Add 1 if the least significant bit is 1
        xor_result >>= 1;           // Right shift the bits by 1
    }
    
    return count;
}