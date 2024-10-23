# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class Solution:
    def replaceValueInTree(self, root: TreeNode) -> TreeNode:
        """
        Replaces the value of each node in the binary tree with the sum of its cousins' values.

        Parameters:
        root (TreeNode): The root of the binary tree.

        Returns:
        TreeNode: The modified binary tree with updated node values.
        """
        if not root:
            return None

        # Initialize a queue for breadth-first traversal (node, parent)
        queue = deque([root])
        root.val = 0  # Root has no cousins, so its value should be 0
        
        while queue:
            level_size = len(queue)
            level_sum = 0  # Sum of all node values at the current level
            node_info = []  # List to store node information for this level
            
            # First pass: compute the level sum and gather nodes
            for _ in range(level_size):
                node = queue.popleft()
                node_info.append(node)
                
                if node.left:
                    queue.append(node.left)
                    level_sum += node.left.val
                if node.right:
                    queue.append(node.right)
                    level_sum += node.right.val
            
            # Second pass: update each node's value to the sum of its cousins' values
            for node in node_info:
                # Calculate the sibling sum
                sibling_sum = 0
                if node.left:
                    sibling_sum += node.left.val
                if node.right:
                    sibling_sum += node.right.val
                
                # Update child nodes' values to the cousin sum
                if node.left:
                    node.left.val = level_sum - sibling_sum
                if node.right:
                    node.right.val = level_sum - sibling_sum
        
        return root