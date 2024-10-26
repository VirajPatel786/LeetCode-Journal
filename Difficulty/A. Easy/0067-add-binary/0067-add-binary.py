class Solution:
    def addBinary(self, a: str, b: str) -> str:
        """
        Adds two binary strings and returns the result as a binary string.

        Parameters:
        a (str): First binary string.
        b (str): Second binary string.

        Returns:
        str: The binary sum of the two input strings.
        """
        result = []
        carry = 0
        i, j = len(a) - 1, len(b) - 1
        
        # Loop through both strings from right to left
        while i >= 0 or j >= 0 or carry:
            # Get current bits and convert them to integers
            bit_a = int(a[i]) if i >= 0 else 0
            bit_b = int(b[j]) if j >= 0 else 0
            
            # Calculate the sum of bits and carry
            total = bit_a + bit_b + carry
            result.append(str(total % 2))  # Current bit result
            carry = total // 2  # Update carry
            
            # Move to the next bit
            i -= 1
            j -= 1
        
        # Since the result is in reverse order, reverse it back
        return ''.join(reversed(result))
