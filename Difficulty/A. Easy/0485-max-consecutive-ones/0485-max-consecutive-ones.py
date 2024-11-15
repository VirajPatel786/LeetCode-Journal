from typing import List

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        """
        Finds the maximum number of consecutive 1s in a binary array.

        Parameters:
        nums (List[int]): A list of integers containing 0s and 1s.

        Returns:
        int: The maximum length of consecutive 1s in the array.
        """
        max_count = 0       # Stores the maximum number of consecutive 1s found so far
        current_count = 0   # Tracks the current streak of consecutive 1s

        # Iterate through each number in the array
        for num in nums:
            if num == 1:
                # Increment the current streak if the number is 1
                current_count += 1
            else:
                # Update the maximum count and reset the current streak
                max_count = max(max_count, current_count)
                current_count = 0

        # Final comparison to ensure the last streak is considered
        return max(max_count, current_count)
