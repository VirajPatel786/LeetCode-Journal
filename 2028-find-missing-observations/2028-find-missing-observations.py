from typing import List

class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        # Calculate the sum of the missing rolls
        missing_sum = (mean * (len(rolls) + n)) - sum(rolls)
        
        # Check if it's possible to distribute the missing_sum among n rolls
        if ((missing_sum < n) or (missing_sum > (6 * n))):
            return list()
        
        # Calculate the base value and extra rolls
        base_value, extra_rolls = divmod(missing_sum, n)
        
        # Construct the result list
        result = []
        for i in range(n):
            if i < extra_rolls:
                result.append(base_value + 1)  # Add 1 to handle the remainder
            else:
                result.append(base_value)      # Assign the base value
        
        return result
