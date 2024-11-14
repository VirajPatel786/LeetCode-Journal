from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        """
        Finds two indices such that the values at these indices add up to the target.
        Assumes the input list 'numbers' is sorted in ascending order.

        Parameters:
        numbers (List[int]): List of integers sorted in ascending order.
        target (int): Target sum for two elements in 'numbers'.

        Returns:
        List[int]: 1-based indices of the two numbers that add up to the target.
        """
        # Initialize two pointers, one at the start and one at the end of the array
        left, right = 0, len(numbers) - 1

        # Continue searching while the pointers do not overlap
        while left < right:
            # Calculate the sum of elements at the two pointers
            current_sum = numbers[left] + numbers[right]
            
            # If the sum matches the target, return 1-based indices of the two pointers
            if current_sum == target:
                return [left + 1, right + 1]
            # If the sum is less than the target, move the left pointer to the right
            elif current_sum < target:
                left += 1
            # If the sum is greater than the target, move the right pointer to the left
            else:
                right -= 1

        # If no solution is found (though the problem guarantees one solution), return an empty list
        return []
