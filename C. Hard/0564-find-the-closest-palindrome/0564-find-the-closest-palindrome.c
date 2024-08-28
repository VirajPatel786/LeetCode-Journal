#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

// Helper function to reverse a string
void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Helper function to find the closest palindrome candidate
long long createPalindrome(char* left_half, int odd_length) {
    int len = strlen(left_half);
    char* palindrome = (char*)malloc((2 * len + 1) * sizeof(char));
    strcpy(palindrome, left_half);

    if (odd_length) {
        for (int i = len - 2; i >= 0; i--) {
            palindrome[len++] = left_half[i];
        }
    } else {
        for (int i = len - 1; i >= 0; i--) {
            palindrome[len++] = left_half[i];
        }
    }
    palindrome[len] = '\0';
    long long result = atoll(palindrome);
    free(palindrome);
    return result;
}

char* nearestPalindromic(char* n) {
    int len = strlen(n);
    if (len == 1) {
        char* result = (char*)malloc(2 * sizeof(char));
        result[0] = n[0] - 1;
        result[1] = '\0';
        return result;
    }

    long long original = atoll(n);
    char prefix_str[20];
    snprintf(prefix_str, sizeof(prefix_str), "%.*s", (len + 1) / 2, n);
    long long prefix = atoll(prefix_str);
    int odd_length = len % 2;

    long long candidates[5];
    int count = 0;

    // Candidates based on prefix modifications
    snprintf(prefix_str, sizeof(prefix_str), "%lld", prefix);
    candidates[count++] = createPalindrome(prefix_str, odd_length);
    snprintf(prefix_str, sizeof(prefix_str), "%lld", prefix - 1);
    candidates[count++] = createPalindrome(prefix_str, odd_length);
    snprintf(prefix_str, sizeof(prefix_str), "%lld", prefix + 1);
    candidates[count++] = createPalindrome(prefix_str, odd_length);

    // Edge cases
    candidates[count++] = pow(10, len - 1) - 1; // 999...999
    candidates[count++] = pow(10, len) + 1;     // 100...001

    long long nearest_palindrome = LLONG_MAX;
    long long min_diff = LLONG_MAX;

    // Find the closest palindrome
    for (int i = 0; i < count; i++) {
        if (candidates[i] == original) continue;
        long long diff = llabs(candidates[i] - original);
        if (diff < min_diff || (diff == min_diff && candidates[i] < nearest_palindrome)) {
            min_diff = diff;
            nearest_palindrome = candidates[i];
        }
    }

    // Convert the nearest palindrome to string
    char* result = (char*)malloc(21 * sizeof(char)); // enough to store a 64-bit int
    snprintf(result, 21, "%lld", nearest_palindrome);
    return result;
}