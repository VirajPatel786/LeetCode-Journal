# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from typing import List, Optional

class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        """
        Calculates the height of the binary tree after removing the subtree rooted at each queried node.

        Parameters:
        root (TreeNode): The root of the binary tree.
        queries (List[int]): List of nodes for which the subtree rooted at each node is removed.

        Returns:
        List[int]: List of heights of the tree after each subtree removal query.
        """
        
        depth = {}  # Stores depth of each node
        height = {}  # Stores height of the subtree rooted at each node
        
        def dfs(node, d):
            """
            Computes the depth and height of each node in the binary tree.

            Parameters:
            node (TreeNode): The current node in the tree.
            d (int): The depth of the current node.

            Returns:
            int: The height of the subtree rooted at the current node.
            """
            if not node:
                return -1  # Base case: empty node has height -1
            depth[node.val] = d  # Set depth of the current node
            # Recursively calculate height of left and right subtrees
            left_height = dfs(node.left, d + 1)
            right_height = dfs(node.right, d + 1)
            # Height of the current node is 1 + max height of its children
            height[node.val] = 1 + max(left_height, right_height)
            return height[node.val]
        
        # Initial DFS call to compute depth and height for each node
        dfs(root, 0)
        
        from collections import defaultdict
        max_depth_with_removal = defaultdict(lambda: [-1, -1])  # Stores top two heights at each depth level
        
        def dfs_depth_levels(node):
            """
            Records the maximum heights at each depth level, ignoring a specific node.

            Parameters:
            node (TreeNode): The current node in the tree.
            """
            if not node:
                return
            h = height[node.val]  # Height of the current subtree rooted at `node`
            d = depth[node.val]  # Depth level of the current node
            # Update the two largest heights at this depth
            if h > max_depth_with_removal[d][0]:  # Current height is the largest at this depth
                max_depth_with_removal[d][1] = max_depth_with_removal[d][0]  # Move current max to second max
                max_depth_with_removal[d][0] = h  # Update max height
            elif h > max_depth_with_removal[d][1]:  # Current height is the second largest
                max_depth_with_removal[d][1] = h  # Update second max height
            # Recursive calls for left and right subtrees
            dfs_depth_levels(node.left)
            dfs_depth_levels(node.right)
        
        # DFS to calculate max heights per depth level, ignoring each node
        dfs_depth_levels(root)
        
        max_tree_height = height[root.val]  # Overall height of the tree
        
        result = []
        for q in queries:
            q_depth = depth[q]  # Depth of the queried node
            q_height = height[q]  # Height of the subtree rooted at the queried node
            # If the queried height is the maximum at this depth, use the second maximum
            if max_depth_with_removal[q_depth][0] == q_height:
                answer_height = max_tree_height - q_height + max_depth_with_removal[q_depth][1]
            else:
                answer_height = max_tree_height  # No need to adjust if not the max at its level
            result.append(answer_height)
        
        return result
