class Solution:
    def minLength(self, s: str) -> int:
        """
        Continuously removes the first occurrence of the substrings 'AB' and 'CD' 
        from the input string until no such substrings are present.

        Parameters:
        s (str): The input string.

        Returns:
        int: The length of the string after removing all occurrences of 'AB' and 'CD'.
        """
        # Continuously remove both 'AB' and 'CD' until neither is present
        while True:
            new_s = s.replace("AB", "").replace("CD", "")  # Replace both in one pass
            if new_s == s:  # If no changes, break out of the loop
                break
            s = new_s  # Update the string for the next iteration
        
        # Return the length of the final string
        return len(s)
