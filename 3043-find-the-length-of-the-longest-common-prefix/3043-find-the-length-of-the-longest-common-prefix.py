from typing import List

class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        """
        Finds the length of the longest common prefix between pairs of numbers
        in two arrays by using a HashSet for quick look-up of prefixes.
        
        Parameters:
        arr1 (List[int]): A list of integers.
        arr2 (List[int]): Another list of integers.
        
        Returns:
        int: The length of the longest common prefix.
        """
        # Create a HashSet to store all prefixes of elements in arr1
        prefix_set = set()
        
        # Add all possible prefixes of each number in arr1 to the HashSet
        for num1 in arr1:
            str_num = str(num1)
            for i in range(1, len(str_num) + 1):
                prefix_set.add(str_num[:i])
        
        max_length = 0
        
        # Check all prefixes of numbers in arr2 and find the longest common prefix
        for num2 in arr2:
            str_num = str(num2)
            for i in range(len(str_num), 0, -1):  # Start from the longest prefix
                if str_num[:i] in prefix_set:
                    max_length = max(max_length, i)
                    break  # Stop early once we find the longest matching prefix
        
        return max_length