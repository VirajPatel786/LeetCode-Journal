from typing import List

class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        # Calculate the remaining sum needed for the missing rolls
        remaining_sum = (mean * (len(rolls) + n)) - sum(rolls)
        
        # If the remaining sum is invalid, return an empty list
        if remaining_sum < n or remaining_sum > 6 * n:
            return []
        
        # Initialize the result with all 1's
        result = [1] * n
        # We pre-filled n ones, so subtract that from the remaining sum
        remaining_sum -= n
        
        # Distribute the remaining sum across the rolls
        i = 0
        while remaining_sum > 0:
            # Increment the current roll, but don't exceed 6
            increment = min(remaining_sum, 6 - result[i])
            result[i] += increment
            remaining_sum -= increment
            i += 1
        
        return result
