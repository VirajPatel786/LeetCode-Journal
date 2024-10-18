from collections import Counter
from typing import List

class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        """
        Count the number of subsets whose bitwise OR equals the maximum possible bitwise OR.
        
        Parameters:
        nums (List[int]): List of integers to form subsets from.
        
        Returns:
        int: The count of subsets with the maximum bitwise OR value.
        """
        # Step 1: Calculate the maximum OR for the entire array
        max_or = 0
        for num in nums:
            max_or |= num
        
        # Step 2: Initialize a Counter to track the number of subsets that produce each OR value
        prev = Counter()
        prev[0] = 1  # The OR of an empty subset is 0, so start with that
        
        # Step 3: Iterate over each number in the array
        for elem in nums:
            current = Counter()  # Temporary counter to track updates for the current element
            
            # For each OR value seen so far, calculate new ORs by including the current element
            for prev_or, count in prev.items():
                current[prev_or | elem] += count  # Update current with new OR
                
            # Merge the current counts into the main 'prev' counter
            prev.update(current)
        
        # Step 4: Return the count of subsets whose OR equals the maximum OR
        return prev[max_or]
