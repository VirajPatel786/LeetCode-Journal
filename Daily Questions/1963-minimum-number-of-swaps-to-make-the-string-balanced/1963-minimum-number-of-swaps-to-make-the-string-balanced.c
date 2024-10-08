/**
 * @brief Returns the minimum number of swaps to make the string balanced.
 *
 * @param s (char*): The input string consisting of '[' and ']'.
 * @return (int): The minimum number of swaps required to balance the string.
 */
int minSwaps(char* s) {
    int balance = 0;  // Tracks the balance of unmatched opening brackets '['
    int unmatched_close_brackets = 0;  // Tracks unmatched closing brackets ']'

    // Traverse the string until the null terminator
    for (; *s; s++)
        if (balance == 0 && *s == ']')
            // Increment unmatched closing brackets count if we encounter ']' without matching '['
            unmatched_close_brackets++;
        else
            // Increment balance for '[' and decrement for ']'
            balance += 2 * (*s == '[') - 1;

    // Each swap fixes two unmatched brackets, so we need (unmatched_close_brackets + 1) / 2 swaps
    return ++unmatched_close_brackets / 2;
}
