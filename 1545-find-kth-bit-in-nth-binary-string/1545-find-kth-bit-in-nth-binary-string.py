class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        """
        Finds the k-th bit in the n-th sequence S_n using recursion without constructing the full sequence.
        
        Parameters:
        n (int): The sequence number.
        k (int): The 1-based index of the bit to find.
        
        Returns:
        str: The k-th bit as a string ('0' or '1').
        """
        # Base case: S1 = "0"
        if n == 1:
            return '0'
        
        # The length of S_n is 2^n - 1
        length = (1 << n) - 1  # equivalent to 2^n - 1
        mid = length // 2 + 1  # middle element index (1-based)
        
        if k == mid:
            # The middle element is always '1'
            return '1'
        elif k < mid:
            # k is in the first half, corresponds to S_{n-1}
            return self.findKthBit(n - 1, k)
        else:
            # k is in the second half, corresponds to the reverse of invert(S_{n-1})
            # Map k to the corresponding position in S_{n-1}
            return '0' if self.findKthBit(n - 1, length - k + 1) == '1' else '1'
