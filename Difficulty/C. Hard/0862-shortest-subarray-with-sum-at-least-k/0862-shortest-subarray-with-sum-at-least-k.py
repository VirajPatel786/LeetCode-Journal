from typing import List
from collections import deque

class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        """
        Finds the length of the shortest subarray with a sum >= k.

        Parameters:
        nums (List[int]): List of integers.
        k (int): Target sum.

        Returns:
        int: Length of the shortest subarray with a sum >= k, or -1 if no such subarray exists.
        """
        # Initialize variables
        n = len(nums)
        prefix_sum = [0] * (n + 1)  # Prefix sum array
        for i in range(n):
            prefix_sum[i + 1] = prefix_sum[i] + nums[i]

        result = float("inf")  # Initialize result with infinity (indicating no valid subarray found)
        deque_indices = deque()  # Monotonic queue to store indices

        # Iterate over prefix sums
        for i in range(n + 1):
            # Remove elements from the front of the deque if a valid subarray is found
            while deque_indices and prefix_sum[i] - prefix_sum[deque_indices[0]] >= k:
                result = min(result, i - deque_indices.popleft())

            # Maintain the monotonicity of the deque
            while deque_indices and prefix_sum[i] <= prefix_sum[deque_indices[-1]]:
                deque_indices.pop()

            # Add the current index to the deque
            deque_indices.append(i)

        # Return the result if a valid subarray is found, otherwise -1
        return result if result != float("inf") else -1
