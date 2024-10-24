#include <stdio.h>
#include <string.h>

/**
 * @brief Returns the maximum number by swapping at most two digits of the given integer.
 *
 * @param num (int): The input integer.
 *
 * @return (int): The maximum number after at most one swap.
 */ 
int maximumSwap(int num) {
    char digits[10];
    sprintf(digits, "%d", num);  // Convert the number to a string for easy manipulation
    int n = strlen(digits);
    
    int last[10] = {0};
    
    // Record the last occurrence of each digit
    for (int i = 0; i < n; i++) {
        last[digits[i] - '0'] = i;
    }

    // Traverse the digits and try to find the best swap
    for (int i = 0; i < n; i++) {
        for (int d = 9; d > digits[i] - '0'; d--) {
            if (last[d] > i) {
                // Swap the digits
                char temp = digits[i];
                digits[i] = digits[last[d]];
                digits[last[d]] = temp;
                
                // Convert back to integer and return
                int swappedNum;
                sscanf(digits, "%d", &swappedNum);
                return swappedNum;
            }
        }
    }
    
    // Return the original number if no swap happened
    return num;
}
