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
        
        # Negate all elements in nums to simulate a max-heap, because heapq in Python implements a min-heap.
        nums = [-num for num in nums]
        
        # Convert the negated list into a heap (which will behave as a max-heap for the original values).
        heapq.heapify(nums)
        
        score = 0  # Initialize the score to 0.
        
        # Perform exactly k operations
        for _ in range(k):
            # Push the element back after shrinking and pop the largest (negated smallest)
            # heapq.heappushpop: Pushes the value (-floor(nums[0] / 3)) and pops the smallest value in one step.
            # Since the heap contains negated values, we subtract the result of heappushpop to maintain the score.
            score -= heapq.heappushpop(nums, floor(nums[0] / 3))
        
        # Return the total score after performing k operations.
        return score
