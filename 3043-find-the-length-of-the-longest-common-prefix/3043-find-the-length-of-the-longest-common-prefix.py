from typing import List

class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        """
        Finds the length of the longest common prefix between pairs of numbers
        in two arrays.
        
        Parameters:
        arr1 (List[int]): A list of integers.
        arr2 (List[int]): Another list of integers.
        
        Returns:
        int: The length of the longest common prefix.
        """
        # Convert both arrays of integers to strings once
        arr1_str = list(map(str, arr1))
        arr2_str = list(map(str, arr2))
        
        max_length = 0
        
        # Compare each number in arr1_str with each number in arr2_str
        for str1 in arr1_str:
            for str2 in arr2_str:
                # Find the common prefix length
                common_length = self.commonPrefixLength(str1, str2)
                # Update max_length with the maximum prefix length found
                max_length = max(max_length, common_length)
        
        return max_length
    
    def commonPrefixLength(self, s1: str, s2: str) -> int:
        """
        Finds the common prefix length between two strings.
        
        Parameters:
        s1 (str): First string.
        s2 (str): Second string.
        
        Returns:
        int: Length of the common prefix.
        """
        min_len = min(len(s1), len(s2))
        i = 0
        while i < min_len and s1[i] == s2[i]:
            i += 1
        return i