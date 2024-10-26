from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        """
        Finds the longest common prefix among an array of strings.

        Parameters:
        strs (List[str]): List of input strings.

        Returns:
        str: The longest common prefix, or an empty string if none exists.
        """
        
        # Edge case: If the input list is empty, return an empty string
        if not strs:
            return ""
        
        # Start with the first string as the initial prefix
        prefix = strs[0]
        
        # Compare prefix with each string in the list
        for string in strs[1:]:
            # Reduce the prefix size until it matches the start of `string`
            while string[:len(prefix)] != prefix:
                prefix = prefix[:-1]  # Shorten the prefix by removing the last character
                if not prefix:
                    return ""  # No common prefix exists
        
        return prefix
