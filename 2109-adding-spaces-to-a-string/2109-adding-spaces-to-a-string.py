from typing import List

class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        """
        Adds spaces to the string `s` at the specified indices in `spaces`.

        Parameters:
        s (str): The original string.
        spaces (List[int]): The list of indices where spaces should be added.

        Returns:
        str: The modified string with spaces added.
        """
        result = []  # List to build the result efficiently
        space_idx = 0  # Pointer for the spaces array
        n = len(spaces)
        
        # Traverse the string `s`
        for i, char in enumerate(s):
            # If the current index matches the space position
            if space_idx < n and i == spaces[space_idx]:
                result.append(' ')  # Add a space
                space_idx += 1  # Move to the next space position
            
            result.append(char)  # Add the current character
        
        return ''.join(result)  # Convert list to string
