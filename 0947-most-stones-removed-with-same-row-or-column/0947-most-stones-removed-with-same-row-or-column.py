class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        # Union-Find (Disjoint Set Union) with path compression and union by rank
        parent = {}
        rank = {}

        # Find function with path compression
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        # Union function with union by rank
        def union(x, y):
            rootX = find(x)
            rootY = find(y)
            if rootX != rootY:
                if rank[rootX] > rank[rootY]:
                    parent[rootY] = rootX
                elif rank[rootX] < rank[rootY]:
                    parent[rootX] = rootY
                else:
                    parent[rootY] = rootX
                    rank[rootX] += 1

        # Add each stone to the union-find structure
        for x, y in stones:
            if x not in parent:
                parent[x] = x
                rank[x] = 0
            if y + 100000 not in parent:  # Offset y to distinguish rows and columns
                parent[y + 100000] = y + 100000
                rank[y + 100000] = 0
            union(x, y + 100000)

        # Count the number of unique components
        root_set = {find(x) for x, y in stones}
        # The maximum number of stones that can be removed is the total number of stones
        # minus the number of unique components
        return len(stones) - len(root_set)