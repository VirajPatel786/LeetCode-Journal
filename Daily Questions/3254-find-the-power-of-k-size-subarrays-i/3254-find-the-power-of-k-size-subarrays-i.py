from typing import List

class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        """
        Computes the power of all k-size subarrays of nums efficiently.

        Parameters:
        nums (List[int]): Array of integers.
        k (int): Size of subarrays to process.

        Returns:
        List[int]: List of powers for each subarray of size k.
        """
        if k == 1: 
            return nums  # If k == 1, each element is its own subarray and the result is nums

        results = []  # List to store the results
        left, right = 0, 1  # Pointers for the sliding window
        n = len(nums)

        # Iterate through the array using the right pointer
        while right < n:
            # If the current pair is not consecutive
            if nums[right] - nums[right - 1] != 1:
                # Fill -1 for all invalid windows starting from left
                while left < right and left + k - 1 < n:
                    results.append(-1)
                    left += 1
                # Reset left pointer to the current right position
                left = right
            # If the window is valid and its size is exactly k
            elif right - left == k - 1:
                results.append(nums[right])  # Append the last element of the valid window
                left += 1  # Move the left pointer forward

            # Increment the right pointer
            right += 1

        return results
