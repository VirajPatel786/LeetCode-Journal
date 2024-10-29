from typing import List

class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        """
        Calculates the maximum number of moves starting from any cell in the first column.

        Parameters:
        grid (List[List[int]]): 2D list representing the grid of integers.

        Returns:
        int: Maximum number of moves possible.
        """
        m, n = len(grid), len(grid[0])  # Dimensions of the grid
        memo = {}  # Dictionary to store memoized results

        def dfs(row: int, col: int) -> int:
            """
            Performs a DFS to calculate the maximum moves from the current cell.

            Parameters:
            row (int): Current row index.
            col (int): Current column index.

            Returns:
            int: Maximum moves possible from the given cell.
            """
            if (row, col) in memo:  # Check memoization
                return memo[(row, col)]
            
            max_moves = 0  # Initialize max moves for current cell

            # Define the possible moves (up-right, right, down-right)
            for d_row, d_col in [(-1, 1), (0, 1), (1, 1)]:
                n_row, n_col = row + d_row, col + d_col
                # Check if the new cell is within bounds and strictly larger
                if 0 <= n_row < m and 0 <= n_col < n and grid[n_row][n_col] > grid[row][col]:
                    max_moves = max(max_moves, 1 + dfs(n_row, n_col))

            memo[(row, col)] = max_moves  # Store the result in memo
            return max_moves

        # Start DFS from each cell in the first column and get the maximum result
        result = max(dfs(r, 0) for r in range(m))
        return result
