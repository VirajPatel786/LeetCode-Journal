/**
 * @brief Returns the minimum number of swaps to make the string balanced.
 *
 * @param s (char*): The input string consisting of '[' and ']'.
 * @return (int): The minimum number of swaps required to balance the string.
 */
int minSwaps(char* s) {
    int unmatched_open_brackets = 0;  // To track unmatched opening brackets

    // Traverse the string until the null terminator is reached
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '[') {
            // Increment for each unmatched opening bracket '['
            unmatched_open_brackets++;
        } else if (unmatched_open_brackets > 0) {
            // If we encounter a closing bracket ']' and there are unmatched '[',
            // decrement the unmatched count since we found a valid pair.
            unmatched_open_brackets--;
        }
    }

    // Each swap can fix two unmatched brackets.
    // Increment unmatched_open_brackets by 1 before division to handle odd cases.
    return ++unmatched_open_brackets / 2;
}
