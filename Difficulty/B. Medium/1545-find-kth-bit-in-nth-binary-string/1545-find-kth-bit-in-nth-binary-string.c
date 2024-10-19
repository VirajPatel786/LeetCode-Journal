/**
 * @brief Finds the k-th bit in the n-th binary string S_n.
 *
 * @param n (int): The sequence number.
 * @param k (int): The 1-based index of the bit to find.
 *
 * @return (char): The k-th bit as a character ('0' or '1').
 */ 
char findKthBit(int n, int k) {
    // Base case: S1 = "0"
    if (n == 1) {
        return '0';
    }

    // The length of S_n is 2^n - 1
    int length = (1 << n) - 1;  // Equivalent to 2^n - 1
    int mid = (length / 2) + 1; // Middle index (1-based)

    if (k == mid) {
        // Middle element is always '1'
        return '1';
    } else if (k < mid) {
        // k is in the first half, corresponds to S_{n-1}
        return findKthBit(n - 1, k);
    } else {
        // k is in the second half, corresponds to reverse of invert(S_{n-1})
        // Map k to the corresponding position in S_{n-1} and invert the result
        return findKthBit(n - 1, length - k + 1) == '1' ? '0' : '1';
    }
}
