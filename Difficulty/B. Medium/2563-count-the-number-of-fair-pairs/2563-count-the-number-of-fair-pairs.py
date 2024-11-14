from typing import List
from bisect import bisect_left, bisect_right

class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        """
        Counts the number of fair pairs (i, j) where:
        - i < j
        - lower <= nums[i] + nums[j] <= upper

        Parameters:
        nums (List[int]): List of integers.
        lower (int): Lower bound for the sum of pairs.
        upper (int): Upper bound for the sum of pairs.

        Returns:
        int: The count of fair pairs.
        """
        # Sort the array to use binary search for ranges
        nums.sort()
        count = 0  # Initialize the count of fair pairs
        
        for i in range(len(nums) - 1):
            # Target range for nums[j] so that lower <= nums[i] + nums[j] <= upper
            min_val = lower - nums[i]
            max_val = upper - nums[i]
            
            # Binary search for the left boundary (first index where nums[j] >= min_val)
            j_start = bisect_left(nums, min_val, i + 1)
            # Binary search for the right boundary (first index where nums[j] > max_val)
            j_end = bisect_right(nums, max_val, i + 1) - 1
            
            # Add the count of valid pairs between j_start and j_end
            count += max(0, j_end - j_start + 1)
        
        return count
