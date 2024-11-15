from typing import List

class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        """
        Finds the length of the shortest subarray to remove to make the array non-decreasing.

        Parameters:
        arr (List[int]): The input array.

        Returns:
        int: The length of the shortest subarray to remove.
        """
        n = len(arr)
        
        # Find the longest non-decreasing prefix
        left = 0
        while left < n - 1 and arr[left] <= arr[left + 1]:
            left += 1

        # If the whole array is non-decreasing, no need to remove anything
        if left == n - 1:
            return 0
        
        # Find the longest non-decreasing suffix
        right = n - 1
        while right > 0 and arr[right - 1] <= arr[right]:
            right -= 1
        
        # Calculate minimum removal length
        # Case 1: Remove all elements between left and right
        min_length = min(n - left - 1, right)

        # Case 2: Merge prefix and suffix with a two-pointer approach
        i, j = 0, right
        while i <= left and j < n:
            if arr[i] <= arr[j]:
                # Valid merge point, update minimum length
                min_length = min(min_length, j - i - 1)
                i += 1
            else:
                # Move the suffix pointer
                j += 1
        
        return min_length
