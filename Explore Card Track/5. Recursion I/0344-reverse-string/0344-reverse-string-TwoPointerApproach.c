/**
 * @brief Reverses the input string in-place using the two-pointer technique.
 *
 * @param s (char*): Pointer to the string (character array).
 * @param sSize (int): The size of the string.
 */
void reverseString(char* s, int sSize) {
    // Initialize two pointers: one at the start and one at the end of the string
    int left = 0;
    int right = sSize - 1;

    // Loop until the left pointer is greater than or equal to the right pointer
    while (left < right) {
        // Swap the characters at the left and right indices
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        // Move the left pointer towards the center
        left++;
        // Move the right pointer towards the center
        right--;
    }
}
