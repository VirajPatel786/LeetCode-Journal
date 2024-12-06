from typing import List

class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        """
        Finds the maximum number of integers that can be chosen
        from the range [1, n] under the given constraints.

        Parameters:
        banned (List[int]): List of integers that cannot be chosen.
        n (int): Maximum integer in the range [1, n].
        maxSum (int): Maximum allowed sum of chosen integers.

        Returns:
        int: Maximum number of integers that can be chosen.
        """
        banned_set = set(banned)  # Convert banned list to a set for fast lookups
        current_sum = 0
        count = 0
        
        for num in range(1, n + 1):
            if num in banned_set:
                continue  # Skip numbers in the banned list
            if current_sum + num > maxSum:
                break  # Stop if adding the number exceeds maxSum
            current_sum += num
            count += 1
        
        return count
