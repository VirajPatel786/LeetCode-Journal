from typing import List
from math import inf, isinf

class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        """
        Finds the length of the shortest subarray with bitwise OR at least k.

        Parameters:
        nums (List[int]): Array of non-negative integers.
        k (int): Target OR value.

        Returns:
        int: Length of the shortest subarray with OR at least k, or -1 if none exists.
        """
        n = len(nums)
        left = 0  # Start index of the sliding window
        current_or = 0  # Current bitwise OR of the sliding window
        bit_count = [0] * 31  # Tracks how many numbers contribute to each bit position
        min_length = inf  # Stores the minimum length of a valid subarray

        # Expand the sliding window by increasing the right boundary
        for right in range(n):
            # Update the OR for the window by including nums[right]
            current_or |= nums[right]

            # Add contributions of nums[right] to each bit in bit_count
            num = nums[right]
            bit_position = 0
            while num > 0:
                if num & 1:
                    bit_count[bit_position] += 1
                num >>= 1
                bit_position += 1

            # Try to shrink the window from the left while OR condition is met
            while left <= right and current_or >= k:
                # Update minimum length if current window is smaller
                min_length = min(min_length, right - left + 1)

                # Remove contributions of nums[left] from each bit in bit_count
                num = nums[left]
                bit_position = 0
                while num > 0:
                    if num & 1:
                        bit_count[bit_position] -= 1
                        # If nums[left] was the only contributor to this bit, update current OR
                        if bit_count[bit_position] == 0:
                            current_or &= ~(1 << bit_position)
                    num >>= 1
                    bit_position += 1
                
                # Move the left boundary of the window
                left += 1

        # Return -1 if no valid subarray was found, otherwise the minimum length
        return -1 if isinf(min_length) else min_length
