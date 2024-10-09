/**
 * @brief Reverses the input string in-place using recursion.
 *
 * @param s (char*): Pointer to the string (character array).
 * @param sSize (int): The size of the string.
 */
void reverseString(char* s, int sSize) {

    /**
     * @brief Helper function to recursively reverse the string.
     *
     * @param left (int): The current index from the left side of the string.
     * @param right (int): The current index from the right side of the string.
     */
    void helper(int left, int right) {
        // Base case: Stop recursion when left index is greater than or equal to right index
        if (left >= right) {
            return;
        }

        // Swap the characters at the left and right indices
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        // Recursively call the helper function with updated pointers
        helper(left + 1, right - 1);
    }

    // Initial call to the helper function with the full range of the string
    helper(0, sSize - 1);
}
