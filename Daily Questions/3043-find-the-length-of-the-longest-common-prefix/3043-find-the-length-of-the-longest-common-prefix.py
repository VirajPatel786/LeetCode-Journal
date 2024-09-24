from typing import List

class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        """
        Finds the length of the longest common prefix between pairs of numbers
        in two arrays using a HashSet for quick look-up of integer prefixes.
        
        Parameters:
        arr1 (List[int]): A list of integers.
        arr2 (List[int]): Another list of integers.
        
        Returns:
        int: The length of the longest common prefix.
        """
        # Create a set to store all prefixes of numbers in arr1
        prefix_set = set()

        # Add all possible prefixes of each number in arr1 to the set
        for number in arr1:
            current_prefix = number
            while current_prefix > 0:
                prefix_set.add(current_prefix)
                current_prefix //= 10  # Remove the last digit

        max_common_prefix_length = 0

        # Check all numbers in arr2 to find the longest matching prefix
        for number in arr2:
            current_prefix = number
            while current_prefix > 0:
                if current_prefix in prefix_set:
                    # Once a match is found, update the answer with the length of the number
                    max_common_prefix_length = max(max_common_prefix_length, len(str(current_prefix)))
                    break
                current_prefix //= 10  # Remove the last digit
        
        return max_common_prefix_length
