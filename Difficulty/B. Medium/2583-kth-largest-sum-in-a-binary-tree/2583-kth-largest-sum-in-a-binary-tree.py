# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        if not root:
            return -1
        
        # List to store the level sums
        level_sums = []
        
        # BFS setup
        queue = deque([root])
        
        # Perform level-order traversal
        while queue:
            level_sum = 0
            level_size = len(queue)
            
            # Process all nodes at the current level
            for _ in range(level_size):
                node = queue.popleft()
                level_sum += node.val
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            # Store the sum of the current level
            level_sums.append(level_sum)
        
        # Sort the level sums in descending order
        level_sums.sort(reverse=True)
        
        # Return the k-th largest level sum if there are at least k levels
        if len(level_sums) >= k:
            return level_sums[k - 1]
        else:
            return -1
