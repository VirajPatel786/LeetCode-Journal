#include <stdio.h>
#include <ctype.h>  // For isalpha()
#include <string.h> // For strlen()

char* reverseOnlyLetters(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    // Two-pointer approach
    while (left < right) {
        // Move left pointer until it points to a letter
        if (!isalpha(s[left])) {
            left++;
        }
        // Move right pointer until it points to a letter
        else if (!isalpha(s[right])) {
            right--;
        }
        // If both left and right pointers are at letters, swap them
        else {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }

    return s; // Return the modified string
}