from bisect import bisect_left

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
        
        # Step 1: Compute longest increasing subsequence (LIS) ending at each index
        lis_length = [0] * n  # lis_length[i] will store the LIS ending at index i
        lis_seq = []          # Auxiliary list for binary search based LIS
        
        for i in range(n):
            pos = bisect_left(lis_seq, nums[i])
            if pos == len(lis_seq):
                lis_seq.append(nums[i])  # Extend the sequence
            else:
                lis_seq[pos] = nums[i]   # Replace the element at pos
            lis_length[i] = pos + 1      # Length of LIS ending at index i

        # Step 2: Compute longest decreasing subsequence (LDS) starting at each index
        lds_length = [0] * n  # lds_length[i] will store the LDS starting at index i
        lds_seq = []          # Auxiliary list for binary search based LDS
        
        for i in range(n - 1, -1, -1):
            pos = bisect_left(lds_seq, nums[i])
            if pos == len(lds_seq):
                lds_seq.append(nums[i])  # Extend the sequence
            else:
                lds_seq[pos] = nums[i]   # Replace the element at pos
            lds_length[i] = pos + 1      # Length of LDS starting at index i

        # Step 3: Find the maximum length of a mountain array
        max_mountain_length = 0
        for i in range(1, n - 1):
            # A valid peak must have both an increasing sequence on the left and a decreasing on the right
            if lis_length[i] > 1 and lds_length[i] > 1:
                # Calculate mountain length centered at i and update max length
                mountain_length = lis_length[i] + lds_length[i] - 1
                max_mountain_length = max(max_mountain_length, mountain_length)

        # Step 4: Calculate minimum removals
        return n - max_mountain_length
