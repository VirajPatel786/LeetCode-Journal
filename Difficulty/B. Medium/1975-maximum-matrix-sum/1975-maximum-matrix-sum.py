from typing import List

class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        """
        Maximizes the sum of matrix elements using the given operation.

        Parameters:
        matrix (List[List[int]]): The n x n integer matrix.

        Returns:
        int: Maximum sum of the matrix elements.
        """
        total_sum = 0  # Total sum of absolute values
        min_abs_val = float('inf')  # Smallest absolute value found
        negative_count = 0  # Count of negative numbers in the matrix
        
        # Traverse each element in the matrix
        for row in matrix:
            for value in row:
                abs_val = abs(value)  # Get absolute value of the element
                total_sum += abs_val  # Add absolute value to total sum
                min_abs_val = min(min_abs_val, abs_val)  # Track smallest absolute value
                if value < 0:
                    negative_count += 1  # Count negative numbers

        # If the count of negatives is odd, subtract twice the smallest absolute value
        if negative_count % 2 == 1:
            total_sum -= 2 * min_abs_val

        return total_sum  # Return the maximum sum
