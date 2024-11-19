from typing import List

class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        """
        Finds the maximum sum of a subarray of size k with unique elements.

        Parameters:
        nums (List[int]): List of integers.
        k (int): Size of the subarray.

        Returns:
        int: Maximum sum of subarray of size k with all unique elements.
        """
        max_sum = 0  # Stores the maximum sum of subarrays
        current_sum = 0  # Current sum of the sliding window
        unique_elements = set()  # To track unique elements in the current window
        left = 0  # Left pointer of the sliding window

        for right in range(len(nums)):
            # Expand the window by adding the current element
            while nums[right] in unique_elements:
                # If the element is a duplicate, shrink the window from the left
                unique_elements.remove(nums[left])
                current_sum -= nums[left]
                left += 1

            # Add the current element to the window
            unique_elements.add(nums[right])
            current_sum += nums[right]

            # Check if the window size is exactly k
            if right - left + 1 == k:
                # Update the maximum sum if all elements are unique
                max_sum = max(max_sum, current_sum)

                # Shrink the window from the left to maintain the size k
                unique_elements.remove(nums[left])
                current_sum -= nums[left]
                left += 1

        return max_sum
