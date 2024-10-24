from typing import List

class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        """
        Returns the index of the dominant element in the list if it exists,
        otherwise returns -1.

        Parameters:
        nums (List[int]): List of integers to evaluate.

        Returns:
        int: The index of the dominant element, or -1 if no such element exists.
        """
        
        # Edge case: If the list has only 2 elements, return index of the larger element directly
        if len(nums) == 2:
            return 0 if nums[0] >= 2 * nums[1] else (1 if nums[1] >= 2 * nums[0] else -1)
        
        # Step 1: Initialize variables for the largest and second largest numbers
        largest_num = second_largest_num = -1
        largest_num_index = -1
        
        # Step 2: Traverse the list once to find the largest and second largest numbers
        for i, num in enumerate(nums):
            if num > largest_num:
                second_largest_num = largest_num
                largest_num = num
                largest_num_index = i
            elif num > second_largest_num:
                second_largest_num = num
        
        # Step 3: Check if the largest number is at least twice the second largest number
        if largest_num >= 2 * second_largest_num:
            return largest_num_index
        
        # If the largest number is not at least twice the second largest number, return -1
        return -1

