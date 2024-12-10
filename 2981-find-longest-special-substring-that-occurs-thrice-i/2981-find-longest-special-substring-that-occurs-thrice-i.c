#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_SUBSTRINGS 5000

/**
 * @brief Structure to store a substring and its frequency.
 */
typedef struct {
    char substring[MAX_LENGTH + 1];
    int count;
} SubstringCounter;

/**
 * @brief Finds the length of the longest special substring that occurs at least thrice.
 *
 * A special substring is defined as a substring consisting of only one repeated character.
 *
 * @param s (char*): The input string consisting of lowercase English letters.
 *
 * @return (int): The length of the longest special substring that occurs at least thrice, or -1 if none exist.
 */
int maximumLength(char *s) {
    int n = strlen(s);
    SubstringCounter counters[MAX_SUBSTRINGS];
    int counter_index = 0;

    // Step 1: Generate all special substrings and count their frequencies
    for (int i = 0; i < n;) {
        int j = i;
        
        // Find the end of the contiguous segment of the same character
        while (j < n && s[j] == s[i]) {
            j++;
        }
        
        int length = j - i;  // Length of the contiguous segment

        // Add all possible substrings from this segment to the counters
        for (int k = 1; k <= length; k++) {
            for (int start = i; start <= j - k; start++) {
                char temp[MAX_LENGTH + 1];
                strncpy(temp, s + start, k);
                temp[k] = '\0';  // Null-terminate the substring

                // Check if the substring already exists in the counters
                int found = 0;
                for (int m = 0; m < counter_index; m++) {
                    if (strcmp(counters[m].substring, temp) == 0) {
                        counters[m].count++;
                        found = 1;
                        break;
                    }
                }

                // If the substring is not found, add a new entry
                if (!found && counter_index < MAX_SUBSTRINGS) {
                    strcpy(counters[counter_index].substring, temp);
                    counters[counter_index].count = 1;
                    counter_index++;
                }
            }
        }

        i = j;  // Move to the next segment
    }

    // Step 2: Find the maximum length of substrings that appear at least three times
    int max_length = -1;
    for (int i = 0; i < counter_index; i++) {
        if (counters[i].count >= 3) {
            int substr_length = strlen(counters[i].substring);
            if (substr_length > max_length) {
                max_length = substr_length;
            }
        }
    }

    return max_length;
}
