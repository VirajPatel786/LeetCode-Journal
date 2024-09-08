# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        # This function checks if the linked list starting from `head`
        # matches any downward path starting from `node` in the tree.
        def isSubPathFromNode(head: ListNode, node: TreeNode) -> bool:
            if head is None:  # If we've reached the end of the list, it's a match
                return True
            if node is None:  # If we've reached the end of the tree path, it's not a match
                return False
            # Check if current node matches current list node, and recursively check its children
            if head.val == node.val:
                return isSubPathFromNode(head.next, node.left) or isSubPathFromNode(head.next, node.right)
            return False
        
        # Traverse the binary tree to find any node that could be the start of a matching path
        if root is None:
            return False
        # Check if the path starts at current node, or in left/right subtree
        return isSubPathFromNode(head, root) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right)