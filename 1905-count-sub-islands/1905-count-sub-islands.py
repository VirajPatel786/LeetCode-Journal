class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        def dfs(x, y):
            if x < 0 or x >= len(grid2) or y < 0 or y >= len(grid2[0]) or grid2[x][y] == 0:
                return True
            # Mark the cell as visited
            grid2[x][y] = 0
            is_sub_island = True
            # Check the current cell in grid1
            if grid1[x][y] == 0:
                is_sub_island = False
            # Explore all 4 directions
            is_sub_island &= dfs(x+1, y)
            is_sub_island &= dfs(x-1, y)
            is_sub_island &= dfs(x, y+1)
            is_sub_island &= dfs(x, y-1)
            return is_sub_island
        
        sub_islands_count = 0
        for i in range(len(grid2)):
            for j in range(len(grid2[0])):
                if grid2[i][j] == 1:  # Start DFS from every unvisited land cell in grid2
                    if dfs(i, j):
                        sub_islands_count += 1
        return sub_islands_count