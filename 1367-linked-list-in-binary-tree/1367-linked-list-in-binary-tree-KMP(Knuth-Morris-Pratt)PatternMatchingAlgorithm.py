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
        # Step 1: Build the pattern (list of values from the linked list)
        # and the prefix table (KMP failure function) for the linked list.
        pattern = [head.val]  # Initialize the pattern with the head node's value
        prefix_table = [0]  # KMP prefix table, starts with 0 for the first element
        pattern_index = 0  # Current index in the pattern

        # Move to the next node in the linked list
        head = head.next

        # Build the pattern array and the KMP prefix table
        while head:
            # If there's a mismatch, move back to the last matching prefix
            while pattern_index > 0 and head.val != pattern[pattern_index]:
                pattern_index = prefix_table[pattern_index - 1]

            # If the current node value matches the pattern, move forward
            pattern_index += 1 if head.val == pattern[pattern_index] else 0

            # Append current value to the pattern and update the prefix table
            pattern.append(head.val)
            prefix_table.append(pattern_index)

            # Move to the next node in the linked list
            head = head.next

        # Step 2: Use DFS to search for the pattern in the binary tree
        return self._search_in_tree(root, 0, pattern, prefix_table)

    def _search_in_tree(self, node: Optional[TreeNode], pattern_index: int, 
                        pattern: List[int], prefix_table: List[int]) -> bool:
        """
        A helper function that performs a DFS to search for the pattern
        in the tree, starting at the current node. Uses the KMP algorithm
        for efficient matching.
        """
        if not node:
            # If we've reached a null node, the pattern cannot be found here
            return False

        # Step 3: Match the current tree node value with the current pattern value
        while pattern_index > 0 and node.val != pattern[pattern_index]:
            # If the current values don't match, move to the previous best match in the pattern
            pattern_index = prefix_table[pattern_index - 1]

        # If the values match, move forward in the pattern
        if node.val == pattern[pattern_index]:
            pattern_index += 1

        # Step 4: Check if we've matched the entire pattern
        if pattern_index == len(pattern):
            return True  # Full pattern match found

        # Step 5: Recursively search both left and right subtrees
        return (
            self._search_in_tree(node.left, pattern_index, pattern, prefix_table) or
            self._search_in_tree(node.right, pattern_index, pattern, prefix_table)
        )