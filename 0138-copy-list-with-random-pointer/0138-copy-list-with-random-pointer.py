"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        """
        Creates a deep copy of a linked list where each node contains an additional random pointer
        that can point to any node in the list or null.

        Parameters:
        head (Optional[Node]): The head of the original linked list.

        Returns:
        Optional[Node]: The head of the deep-copied linked list.
        """
        
        # Edge case: If the input list is empty, return None.
        if not head:
            return None

        # Dictionary to map each original node to its corresponding deep-copied node.
        node_map = dict()

        # First pass: Create all nodes (without setting the `next` or `random` pointers).
        current = head
        while current:
            # Create a deep copy of the current node and store it in the map.
            node_map[current] = Node(current.val)
            current = current.next

        # Second pass: Set the `next` and `random` pointers for the copied nodes.
        current = head
        while current:
            # Get the deep copy of the current node.
            copy_node = node_map[current]

            # Set the `next` pointer for the copied node.
            if current.next:
                copy_node.next = node_map[current.next]

            # Set the `random` pointer for the copied node.
            if current.random:
                copy_node.random = node_map[current.random]

            # Move to the next node in the original list.
            current = current.next

        # Return the deep-copied head node.
        return node_map[head]