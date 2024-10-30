class Solution:
    def minimumMountainRemovals(self, nums: list[int]) -> int:
        """
        Calculate the minimum number of elements to remove to make the array a mountain array.

        Parameters:
        nums (list[int]): List of integers representing the input array.

        Returns:
        int: Minimum number of elements to remove to form a mountain array.
        """
        
        n = len(nums)
        
        # Initialize left_inc array to store the length of the longest increasing subsequence
        # ending at each index
        left_inc = [1] * n
        for i in range(1, n):
            for j in range(i):
                # If nums[i] can extend the increasing subsequence ending at nums[j]
                if nums[i] > nums[j]:
                    left_inc[i] = max(left_inc[i], left_inc[j] + 1)
        
        # Initialize right_dec array to store the length of the longest decreasing subsequence
        # starting at each index
        right_dec = [1] * n
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                # If nums[i] can extend the decreasing subsequence starting at nums[j]
                if nums[i] > nums[j]:
                    right_dec[i] = max(right_dec[i], right_dec[j] + 1)
        
        # Initialize max_mountain to track the length of the longest valid mountain subarray
        max_mountain = 0
        for i in range(1, n - 1):
            # Only consider indexes that can be the peak of a mountain
            if left_inc[i] > 1 and right_dec[i] > 1:
                # Calculate the mountain length at index i and update max_mountain
                max_mountain = max(max_mountain, left_inc[i] + right_dec[i] - 1)
        
        # Minimum removals is total elements minus the length of the longest mountain
        return n - max_mountain
