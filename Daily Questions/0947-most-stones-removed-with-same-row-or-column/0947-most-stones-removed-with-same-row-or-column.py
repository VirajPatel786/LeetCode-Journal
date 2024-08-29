from typing import List

class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        num_stones = len(stones)
        # rank[i] will hold the rank (size) of the set containing stone i
        rank = [1] * num_stones
        # parent[i] will hold the parent of stone i in the union-find structure
        parent = [i for i in range(num_stones)]
        
        # Find the root parent of the stone with path compression
        def find(stone_index):
            while stone_index != parent[stone_index]:
                # Path compression: point the stone directly to its grandparent
                parent[stone_index] = parent[parent[stone_index]]
                stone_index = parent[stone_index]
            return stone_index
        
        # Union two stones' sets if they are not already connected
        def union(stone1_index, stone2_index):
            root1 = find(stone1_index)
            root2 = find(stone2_index)
            
            # If both stones are already in the same set, no need to union
            if root1 == root2:
                return 0
            
            # Union by rank: attach the smaller tree under the larger tree
            if rank[root1] < rank[root2]:
                root1, root2 = root2, root1  # Swap to ensure root1 is always larger
            parent[root2] = root1
            rank[root1] += rank[root2]
            return 1
        
        # Maps to track the latest stone seen in each row and column
        row_to_stone = {}
        col_to_stone = {}
        stones_removed = 0
        
        # Process each stone
        for i, (row, col) in enumerate(stones):
            # If there is already a stone in the same row, union the current stone with it
            if row in row_to_stone:
                stones_removed += union(i, row_to_stone[row])
            else:
                row_to_stone[row] = i
            
            # If there is already a stone in the same column, union the current stone with it
            if col in col_to_stone:
                stones_removed += union(i, col_to_stone[col])
            else:
                col_to_stone[col] = i
        
        # The number of stones that can be removed is equal to the number of unions performed
        return stones_removed
