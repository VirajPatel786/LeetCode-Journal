from typing import List

class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        """
        Determines if subarrays defined by queries are special.

        Parameters:
        nums (List[int]): The input array of integers.
        queries (List[List[int]]): The list of queries where each query is [from, to].

        Returns:
        List[bool]: A list of booleans indicating if each subarray is special.
        """
        n = len(nums)
        
        # Step 1: Precompute special_prefix array
        special_prefix = [True] * (n - 1)
        for i in range(n - 1):
            special_prefix[i] = (nums[i] % 2) != (nums[i + 1] % 2)

        # Step 2: Compute prefix sum of the special_prefix array
        prefix_sum = [0] * (n - 1)
        for i in range(n - 1):
            prefix_sum[i] = prefix_sum[i - 1] + special_prefix[i] if i > 0 else special_prefix[i]

        # Step 3: Answer each query
        result = []
        for start, end in queries:
            if start == end:
                result.append(True)  # A single element is always special
            else:
                # Check if the entire range [start, end-1] in special_prefix is special
                special_count = prefix_sum[end - 1] - (prefix_sum[start - 1] if start > 0 else 0)
                if special_count == (end - start):
                    result.append(True)
                else:
                    result.append(False)

        return result
