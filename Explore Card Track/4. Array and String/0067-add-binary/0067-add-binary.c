#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Adds two binary strings and returns the result as a binary string.
 *
 * @param a (char*): First binary string.
 * @param b (char*): Second binary string.
 *
 * @return (char*): The binary sum of the two input strings.
 */
char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = len_a > len_b ? len_a : len_b;
    
    // Result buffer with extra space for carry
    char* result = (char*)malloc(max_len + 2);
    result[max_len + 1] = '\0';
    
    int carry = 0, i = len_a - 1, j = len_b - 1, k = max_len;

    while (i >= 0 || j >= 0 || carry) {
        int bit_a = (i >= 0) ? a[i--] - '0' : 0;
        int bit_b = (j >= 0) ? b[j--] - '0' : 0;
        int sum = bit_a + bit_b + carry;
        
        result[k--] = (sum % 2) + '0';
        carry = sum / 2;
    }
    
    // Adjust the result pointer if there's no leftover carry
    return (k == 0) ? result + 1 : result;
}
