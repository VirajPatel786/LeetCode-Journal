from typing import List

class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        """
        Count unguarded cells in the grid.

        Parameters:
        m (int): Number of rows.
        n (int): Number of columns.
        guards (List[List[int]]): Positions of guards.
        walls (List[List[int]]): Positions of walls.

        Returns:
        int: Number of unguarded cells.
        """
        # Create the grid with 0 for empty cells
        grid = [[0] * n for _ in range(m)]
        
        # Mark guards as 1 and walls as 2
        for r, c in guards:
            grid[r][c] = 1
        for r, c in walls:
            grid[r][c] = 2
        
        # Directions: up, right, down, left
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        
        # Mark guarded cells
        for r, c in guards:
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                while 0 <= nr < m and 0 <= nc < n and grid[nr][nc] != 2 and grid[nr][nc] != 1:
                    grid[nr][nc] = -1  # Mark as guarded
                    nr += dr
                    nc += dc
        
        # Count unguarded and unoccupied cells
        unguarded_count = sum(grid[i][j] == 0 for i in range(m) for j in range(n))
        return unguarded_count
