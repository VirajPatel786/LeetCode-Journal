#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * @brief Finds the length of the longest substring where all vowels ('a', 'e', 'i', 'o', 'u') appear an even number of times.
 *
 * @param s: char* - Input string.
 * 
 * @return int - Length of the longest valid substring with even vowel counts.
 */
int findTheLongestSubstring(char *s) {
    // Mapping vowels to their respective bit positions in the bitmask
    // 'a' -> 0, 'e' -> 1, 'i' -> 2, 'o' -> 3, 'u' -> 4
    int vowel_to_bit[128];
    memset(vowel_to_bit, -1, sizeof(vowel_to_bit));  // Initialize the map to -1 (non-vowels)
    vowel_to_bit['a'] = 0;
    vowel_to_bit['e'] = 1;
    vowel_to_bit['i'] = 2;
    vowel_to_bit['o'] = 3;
    vowel_to_bit['u'] = 4;

    int seen[32];  // Array to store the first occurrence of each bitmask (5 bits = 32 possible values)
    for (int i = 0; i < 32; ++i) {
        seen[i] = -1;  // Initialize seen to -1 (indicating the bitmask hasn't been seen yet)
    }
    seen[0] = 0;  // Bitmask 00000 (all vowels even) starts at index -1

    int bitmask = 0;  // Start with an all-even bitmask (00000)
    int max_len = 0;  // Variable to store the maximum length of valid substring

    // Traverse the string
    for (int i = 0; s[i] != '\0'; i++) {
        // If the character is a vowel, toggle its corresponding bit in the bitmask
        if (vowel_to_bit[s[i]] != -1) {
            bitmask ^= (1 << vowel_to_bit[s[i]]);
        }

        // Check if this bitmask has been seen before
        if (seen[bitmask] != -1) {
            // If seen before, calculate the length of the valid substring
            max_len = MAX(max_len, i + 1 - seen[bitmask]);
        } else {
            // If not seen, store the first occurrence of this bitmask
            seen[bitmask] = i + 1;  // Store index + 1 to handle 0-indexing properly
        }
    }

    return max_len;
}