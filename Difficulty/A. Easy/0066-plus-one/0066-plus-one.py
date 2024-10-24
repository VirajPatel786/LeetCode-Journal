from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        """
        Increments the integer represented by the list of digits by one.

        Parameters:
        digits (List[int]): List of digits representing a non-negative integer.

        Returns:
        List[int]: A new list of digits representing the integer incremented by one.
        """
        
        # Traverse the list from the last digit (rightmost side)
        for i in range(len(digits) - 1, -1, -1):
            if digits[i] < 9:
                # If the current digit is less than 9, just increment and return the result
                digits[i] += 1
                return digits
            # If the current digit is 9, it becomes 0 (carry over to the next significant digit)
            digits[i] = 0
        
        # If the loop finishes and we still have a carry, we add 1 at the beginning (e.g., [9, 9, 9] becomes [1, 0, 0, 0])
        return [1] + digits