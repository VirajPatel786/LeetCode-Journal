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
        head (Optional[Node]): The head of the multilevel doubly linked list.

        Returns:
        Optional[Node]: The head of the flattened doubly linked list.
        """
        current_node = head  # Pointer to the current node we are traversing
        
        while current_node is not None:
            # If the current node has a child, we need to flatten the child list into the main list
            if current_node.child is not None:
                # Merge the child list starting from the current node
                self._merge_child_list(current_node)
            
            # Move to the next node in the parent list
            current_node = current_node.next
        
        return head

    def _merge_child_list(self, current_node: 'Node') -> None:
        """
        Merges the child list into the main doubly linked list at the current node.

        Parameters:
        current_node (Node): The node in the parent list that has a child list to be merged.
        """
        child_list_head = current_node.child  # The start of the child list
        
        # Traverse to the end of the child list to get the last node
        child_list_tail = child_list_head
        while child_list_tail.next is not None:
            child_list_tail = child_list_tail.next
        
        # If the current node has a next node, connect the tail of the child list to it
        if current_node.next is not None:
            child_list_tail.next = current_node.next  # Connect the child list tail to the current next node
            current_node.next.prev = child_list_tail  # Update the prev pointer of the next node
        
        # Now connect the current node to the child list's head
        current_node.next = current_node.child  # Link current node to the start of the child list
        current_node.child.prev = current_node  # Update the prev pointer of the child list head

        # Remove the child pointer as the child list has been flattened
        current_node.child = None
        