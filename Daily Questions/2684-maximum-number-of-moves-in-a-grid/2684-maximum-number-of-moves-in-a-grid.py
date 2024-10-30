from typing import List

class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        """
        Calculates the maximum number of moves starting from any cell in the first column.
        A move is valid only if the target cell has a strictly greater value than the current cell.

        Parameters:
        grid (List[List[int]]): 2D list representing the grid of positive integers.

        Returns:
        int: The maximum number of moves possible from any cell in the first column,
             or 0 if no valid moves are possible.
        """
        num_rows = len(grid)
        num_cols = len(grid[0])

        # Track rows in the current column that can initiate moves
        can_move_from_current_col = [True] * num_rows
        # Track rows in the next column that are reachable from the current column
        can_move_to_next_col = [False] * num_rows

        # Iterate through each column up to the second last (we are moving rightward)
        for col_idx in range(num_cols - 1):
            # Check each row in the current column for possible moves
            for row_idx in range(num_rows):

                # Skip this row if no moves can be made from it in the current column
                if not can_move_from_current_col[row_idx]:
                    continue

                # Check and mark moves from the current cell to the next column
                # Up-right move (only if there is a row above)
                if row_idx > 0:
                    can_move_to_next_col[row_idx - 1] |= grid[row_idx - 1][col_idx + 1] > grid[row_idx][col_idx]
                
                # Rightward move to the same row
                can_move_to_next_col[row_idx] |= grid[row_idx][col_idx + 1] > grid[row_idx][col_idx]
                
                # Down-right move (only if there is a row below)
                if row_idx + 1 < num_rows:
                    can_move_to_next_col[row_idx + 1] |= grid[row_idx + 1][col_idx + 1] > grid[row_idx][col_idx]

            # If no moves are possible to any row in the next column, return the current column index
            if not any(can_move_to_next_col):
                return col_idx

            # Update current column tracking with next column's move possibilities
            can_move_from_current_col = can_move_to_next_col
            # Reset next column tracking for the next iteration
            can_move_to_next_col = [False] * num_rows

        # If we've iterated through all columns, check if any moves were possible in the last column
        return col_idx + 1 if any(can_move_from_current_col) else col_idx
