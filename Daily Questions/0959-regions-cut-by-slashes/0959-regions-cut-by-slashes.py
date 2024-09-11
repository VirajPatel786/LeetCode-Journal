class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            rootX = find(x)
            rootY = find(y)
            if rootX != rootY:
                parent[rootY] = rootX

        n = len(grid)
        parent = list(range(4 * n * n))  # Each cell is split into 4 parts
        
        for r in range(n):
            for c in range(n):
                root = 4 * (r * n + c)
                if grid[r][c] == '/':
                    union(root + 0, root + 3)
                    union(root + 1, root + 2)
                elif grid[r][c] == '\\':
                    union(root + 0, root + 1)
                    union(root + 2, root + 3)
                else:  # space ' '
                    union(root + 0, root + 1)
                    union(root + 1, root + 2)
                    union(root + 2, root + 3)
                
                # Union with right cell
                if c + 1 < n:
                    union(root + 1, 4 * (r * n + c + 1) + 3)
                # Union with bottom cell
                if r + 1 < n:
                    union(root + 2, 4 * ((r + 1) * n + c) + 0)
        
        # Count distinct components
        return sum(find(x) == x for x in range(4 * n * n))