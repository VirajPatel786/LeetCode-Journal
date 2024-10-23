# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def sumup(self, root, sums, lvl):
        """
        Recursively sums up node values at each level.

        Parameters:
        root (TreeNode): The current node.
        sums (list): List to store the sum of node values at each level.
        lvl (int): The current level in the tree.
        """
        if not root:
            return

        # Ensure sums list is long enough to accommodate the current level
        if lvl >= len(sums):
            sums.append(0)

        sums[lvl] += root.val
        self.sumup(root.left, sums, lvl + 1)
        self.sumup(root.right, sums, lvl + 1)

    def replace(self, root, sums, lvl):
        """
        Recursively replaces node values with their cousin sums.

        Parameters:
        root (TreeNode): The current node.
        sums (list): List storing the sum of node values at each level.
        lvl (int): The current level in the tree.
        """
        if not root:
            return

        # Recursively process left and right children
        self.replace(root.left, sums, lvl + 1)
        self.replace(root.right, sums, lvl + 1)

        # Calculate sibling sum (sum of the current node's children if they exist)
        left_val = root.left.val if root.left else 0
        right_val = root.right.val if root.right else 0

        # Replace the left child's value if it exists
        if root.left:
            root.left.val = sums[lvl + 1] - left_val - right_val

        # Replace the right child's value if it exists
        if root.right:
            root.right.val = sums[lvl + 1] - right_val - left_val

    def replaceValueInTree(self, root):
        """
        Main function to replace node values in the tree with the sum of cousin node values.

        Parameters:
        root (TreeNode): The root of the binary tree.

        Returns:
        TreeNode: The modified tree with updated node values.
        """
        sums = []  # List to store sums of each level

        # First pass: Calculate the sum of values at each level
        self.sumup(root, sums, 0)

        # Second pass: Replace node values with the cousin sums
        self.replace(root, sums, 0)

        # The root node has no cousins, so set its value to 0
        root.val = 0

        return root