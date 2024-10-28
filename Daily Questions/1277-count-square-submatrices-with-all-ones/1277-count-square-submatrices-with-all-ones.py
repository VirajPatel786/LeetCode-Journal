from typing import List

class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        """
        Counts the number of square submatrices with all ones in the given matrix.

        Parameters:
        matrix (List[List[int]]): Binary matrix of 1s and 0s.

        Returns:
        int: Total number of square submatrices with all ones.
        """
        m, n = len(matrix), len(matrix[0])  # Dimensions of the matrix
        dp = [[0] * n for _ in range(m)]  # DP array to store the size of the largest square ending at each cell
        total_squares = 0  # Variable to accumulate the total number of squares
        
        for i in range(m):
            for j in range(n):
                # Only proceed if the cell has a 1, as only 1 can form squares
                if matrix[i][j] == 1:
                    if i == 0 or j == 0:
                        dp[i][j] = 1  # Edge cells can only form 1x1 squares
                    else:
                        # Take minimum of three adjacent squares and add 1
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                    total_squares += dp[i][j]  # Add the number of squares ending at dp[i][j]
        
        return total_squares
