import heapq
from typing import List
from math import ceil

class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        """
        Calculate the maximum score by performing exactly k operations.
        In each operation:
        - Choose the largest element from the array.
        - Increase the score by that element.
        - Replace the chosen element with ceil(nums[i] / 3).
        
        Parameters:
        nums (List[int]): List of integers representing the elements.
        k (int): Number of operations to perform.
        
        Returns:
        int: The maximum possible score after k operations.
        """
        
        # Convert the list to a max-heap by negating all values (heapq is a min-heap by default)
        nums = [-num for num in nums]
        
        # Heapify the negated list (O(n) operation to convert it to a heap)
        heapq.heapify(nums)
        
        score = 0  # Initialize score to 0
        
        # Perform exactly k operations
        for _ in range(k):
            # Pop the largest element (which is the smallest in the negated heap)
            max_num = -heapq.heappop(nums)
            
            # Increase the score by the largest element
            score += max_num
            
            # Compute the new value as ceil(max_num / 3)
            new_value = ceil(max_num / 3)
            
            # Push the new value (negated) back into the heap to maintain the max-heap property
            heapq.heappush(nums, -new_value)
        
        # Return the total score after k operations
        return score

