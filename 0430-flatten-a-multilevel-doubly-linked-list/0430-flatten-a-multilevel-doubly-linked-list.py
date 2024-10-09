"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        """
        Flattens a multilevel doubly linked list into a single-level doubly linked list.

        Parameters:
        head (Node): The head of the multilevel doubly linked list.

        Returns:
        Node: The head of the flattened doubly linked list.
        """
        
        if not head:
            return None  # If the list is empty, return None
        
        current = head  # Start at the head of the list
        
        while current:
            if current.child:
                # Flatten the child list recursively
                child = current.child
                next_node = current.next  # Save the next node
                
                # Flatten the child list and attach it to the current node
                flattened_child = self.flatten(child)
                
                # Connect current node to the child list
                current.next = flattened_child
                flattened_child.prev = current
                
                # Find the tail of the flattened child list to reconnect the rest
                tail = flattened_child
                while tail.next:
                    tail = tail.next  # Move to the end of the flattened child list
                
                # Connect the tail of the flattened child list to the next node
                tail.next = next_node
                if next_node:
                    next_node.prev = tail  # If next_node exists, connect its prev to the tail
                
                # Clear the child pointer as we've flattened it
                current.child = None
            
            # Move to the next node in the list
            current = current.next
        
        return head  # Return the head of the flattened list