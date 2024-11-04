#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Checks if one string is a rotation of another.
 *
 * This function checks if the string `goal` can be obtained by rotating
 * the string `s`.
 *
 * @param s (char*): The original string.
 * @param goal (char*): The target string to check for rotation.
 *
 * @return bool: true if `goal` is a rotation of `s`, false otherwise.
 */
bool rotateString(char* s, char* goal) {
    // Get the lengths of both strings
    int len_s = strlen(s);
    int len_goal = strlen(goal);

    // If lengths are different, rotation is not possible
    if (len_s != len_goal) {
        return false;
    }

    // Create a new string by concatenating `s` with itself
    char* doubled_s = (char*)malloc(2 * len_s + 1); // Allocate memory for doubled string
    if (doubled_s == NULL) {
        return false; // Memory allocation failed
    }
    strcpy(doubled_s, s);
    strcat(doubled_s, s); // doubled_s = s + s

    // Check if `goal` is a substring of `doubled_s`
    bool result = strstr(doubled_s, goal) != NULL;

    // Free allocated memory
    free(doubled_s);

    return result;
}
