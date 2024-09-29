class Solution:
    def partitionString(self, s: str) -> int:
        """
        Partition the input string into the smallest number of substrings 
        such that no substring contains repeated characters.

        Parameters:
        s (str): The input string to partition.

        Returns:
        int: The number of substrings created.
        """
        seen = 0  # Bitmask to track characters in the current substring
        count = 0  # Counter for the number of substrings created

        for ch in s:
            bit_position = ord(ch) - ord('a')  # Calculate bit position for the character
            if seen & (1 << bit_position):
                # If character already seen, increment the partition count and reset the bitmask
                count += 1
                seen = 0
            
            # Mark the character as seen by setting the corresponding bit
            seen |= (1 << bit_position)

        # Return the total count of substrings, including the last one
        return count + 1
