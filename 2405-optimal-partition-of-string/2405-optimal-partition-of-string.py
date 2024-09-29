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
        count = 0  # Counter for the number of substrings created
        seen_chars = set()  # Set to store characters in the current substring
        
        # Iterate over each character in the string
        for ch in s:
            if ch in seen_chars:
                # If the character is already in the current substring, 
                # increment the substring count and start a new substring
                count += 1
                seen_chars.clear()  # Clear the set for the new substring
            
            # Add the current character to the set for the current substring
            seen_chars.add(ch)
        
        # Return the total count of substrings (including the last one)
        return count + 1  # +1 to account for the last substring
