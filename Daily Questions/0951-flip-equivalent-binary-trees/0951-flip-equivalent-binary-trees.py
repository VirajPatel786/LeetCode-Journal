# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def flipEquiv(self, root1: TreeNode, root2: TreeNode) -> bool:
        """
        Determine if two binary trees are flip equivalent.
        
        Parameters:
        root1 (TreeNode): The root of the first binary tree.
        root2 (TreeNode): The root of the second binary tree.

        Returns:
        bool: True if the trees are flip equivalent, otherwise False.
        """
        # Base cases
        if not root1 and not root2:
            return True
        if not root1 or not root2 or root1.val != root2.val:
            return False
        
        # Check if trees are flip equivalent without flip and with flip
        return (self.flipEquiv(root1.left, root2.left) and self.flipEquiv(root1.right, root2.right)) or \
               (self.flipEquiv(root1.left, root2.right) and self.flipEquiv(root1.right, root2.left))

        