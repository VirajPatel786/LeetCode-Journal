from math import gcd  # Import Python's built-in gcd function from the math module

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val  # Node value
#         self.next = next  # Pointer to the next node in the linked list

class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        This function inserts a new node containing the Greatest Common Divisor (GCD) 
        between every pair of consecutive nodes in a linked list.
        
        Args:
        head (Optional[ListNode]): The head of the singly linked list.
        
        Returns:
        Optional[ListNode]: The modified linked list with GCD nodes inserted.
        """
        
        currentNode = head  # Start traversal from the head of the linked list
        
        # Traverse through the list until we reach the end or the second last node
        while currentNode is not None and currentNode.next is not None:
            # Calculate GCD between the current node's value and the next node's value
            gcd_value = gcd(currentNode.val, currentNode.next.val)
            
            # Create a new node containing the GCD value
            gcdNode = ListNode(gcd_value, currentNode.next)
            
            # Insert the new GCD node between the current node and the next node
            currentNode.next = gcdNode
            
            # Move the current pointer two steps forward (skip over the newly inserted GCD node)
            currentNode = currentNode.next.next
        
        # Return the modified list with GCD nodes inserted
        return head
