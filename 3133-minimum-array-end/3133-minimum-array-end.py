class Solution:
    def minEnd(self, n: int, x: int) -> int:
        """
        Calculate the minimum possible last element of a strictly increasing array with a given bitwise AND.

        Parameters:
        n (int): The length of the array.
        x (int): The target bitwise AND value.

        Returns:
        int: The minimum possible value of the last element in the array.
        """
        
        # Start with the initial result as `x`, since we need the final AND to be `x`
        min_last_element = x
        
        # Number of remaining increments needed to make an increasing sequence of length `n`
        increments_needed = n - 1
        
        # Current bit position, starting from the least significant bit
        bit_position = 1

        # Iterate while we still have increments needed
        while increments_needed > 0:
            # Check if the current bit position in `x` is not set (0)
            if not (x & bit_position):
                # Set this bit in `min_last_element` only if the current increment is needed
                # `increments_needed & 1` checks if the current least significant bit of increments_needed is 1
                min_last_element |= (increments_needed & 1) * bit_position
                
                # Right-shift `increments_needed` by 1 to process the next bit
                increments_needed >>= 1
            
            # Move to the next bit position (shift left by 1)
            bit_position <<= 1

        return min_last_element
