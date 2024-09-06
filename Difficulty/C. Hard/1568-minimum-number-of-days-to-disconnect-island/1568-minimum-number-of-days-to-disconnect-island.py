class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        def is_connected():
            # Helper function to check if the grid is connected
            visited = [[False] * len(grid[0]) for _ in range(len(grid))]
            
            def dfs(i, j):
                if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] == 0 or visited[i][j]:
                    return
                visited[i][j] = True
                dfs(i + 1, j)
                dfs(i - 1, j)
                dfs(i, j + 1)
                dfs(i, j - 1)
            
            found_island = False
            for i in range(len(grid)):
                for j in range(len(grid[0])):
                    if grid[i][j] == 1 and not visited[i][j]:
                        if found_island:
                            return False  # More than one island found
                        dfs(i, j)
                        found_island = True
            
            # If no island was found, it's disconnected
            return found_island

        def count_land_cells():
            return sum(grid[i][j] for i in range(len(grid)) for j in range(len(grid[0])))

        # If the grid is already disconnected
        if not is_connected():
            return 0
        
        # If the grid has only one land cell
        if count_land_cells() == 1:
            return 1
        
        # Try removing each land cell and check if it disconnects the grid
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    if not is_connected():
                        return 1
                    grid[i][j] = 1
        
        # If no single removal causes disconnection, return 2
        return 2