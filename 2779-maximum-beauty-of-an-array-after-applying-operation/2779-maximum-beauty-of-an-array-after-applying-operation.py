from typing import List

class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        """
        Find the maximum beauty of the array after applying the operation.

        Parameters:
        nums (List[int]): The input array.
        k (int): The maximum allowable change for each element.

        Returns:
        int: The maximum possible beauty of the array.
        """
        # Sort the array to efficiently check for overlapping ranges
        nums.sort()
        left = 0
        max_beauty = 0

        for right in range(len(nums)):
            # Keep the window within the allowable range
            while nums[right] - nums[left] > 2 * k:
                left += 1
            max_beauty = max(max_beauty, right - left + 1)

        return max_beauty
