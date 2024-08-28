from typing import List

class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        self.grid1 = grid1
        self.grid2 = grid2
        self.num_rows = len(grid2)
        self.num_cols = len(grid2[0])
        return self.count_sub_islands()
    
    def count_sub_islands(self) -> int:
        sub_island_count = 0
        
        # Traverse through each cell in grid2
        for row in range(self.num_rows):
            for col in range(self.num_cols):
                # If a land cell is found in grid2, initiate DFS to check if it's a sub-island
                if self.grid2[row][col] == 1:
                    self.is_sub_island = True
                    self.dfs(row, col)
                    # If the entire island is confirmed as a sub-island, increment the count
                    if self.is_sub_island:
                        sub_island_count += 1
        return sub_island_count
    
    def dfs(self, row: int, col: int) -> None:
        # Mark the current cell in grid2 as visited by setting it to 0
        self.grid2[row][col] = 0
        
        # If the corresponding cell in grid1 is water, mark this island as invalid
        if self.grid1[row][col] == 0:
            self.is_sub_island = False

        # Explore the 4 neighboring directions (up, down, left, right)
        if row > 0 and self.grid2[row - 1][col] == 1:  # Up
            self.dfs(row - 1, col)
        if row < self.num_rows - 1 and self.grid2[row + 1][col] == 1:  # Down
            self.dfs(row + 1, col)
        if col > 0 and self.grid2[row][col - 1] == 1:  # Left
            self.dfs(row, col - 1)
        if col < self.num_cols - 1 and self.grid2[row][col + 1] == 1:  # Right
            self.dfs(row, col + 1)
