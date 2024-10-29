from typing import List

class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        """
        Calculates the maximum number of moves starting from any cell in the first column.
        A move is valid only if the target cell has a strictly greater value than the current cell.

        Parameters:
        grid (List[List[int]]): 2D list representing the grid of positive integers.

        Returns:
        int: Maximum number of moves possible starting from any cell in the first column.
        Returns 0 if no valid moves are possible.
        """
        m, n = len(grid), len(grid[0])  # Get dimensions of the grid
        dp = [[-1] * n for _ in range(m)]  # Initialize DP table with -1 (indicating no moves made)

        # Initialize the first column of DP table with 0 moves as starting points
        for row in range(m):
            dp[row][0] = 0  # Starting at each cell in the first column is allowed

        # Fill DP table column by column, starting from the second column
        for col in range(1, n):
            for row in range(m):
                # Check possible moves from neighboring cells in the previous column
                for d_row in [-1, 0, 1]:  # Row offsets: -1 (up), 0 (straight), 1 (down)
                    prev_row = row + d_row  # Calculate row index of the previous cell
                    # Check if previous cell is within bounds and has a lower value
                    if 0 <= prev_row < m and grid[prev_row][col - 1] < grid[row][col]:
                        # Update dp[row][col] to reflect max moves from a valid previous cell
                        dp[row][col] = max(dp[row][col], dp[prev_row][col - 1] + 1)

        # Extract the maximum number of moves possible from the last column in DP table
        max_moves = max((dp[row][n - 1] for row in range(m)), default=0)

        # Return max moves, or 0 if no valid moves exist (if all are still -1)
        return max_moves if max_moves != -1 else 0
