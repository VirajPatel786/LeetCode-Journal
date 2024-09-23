# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        """
        Add two numbers represented as linked lists.

        Parameters:
        l1 (ListNode): The head of the first linked list.
        l2 (ListNode): The head of the second linked list.

        Returns:
        ListNode: The head of the new linked list representing the sum.
        """
        # Initialize a dummy node to simplify result list construction
        dummy = ListNode()
        current = dummy
        carry = 0

        # Traverse both lists
        while l1 or l2 or carry:
            # Get the current values; if the list is exhausted, use 0
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            
            # Calculate the sum and update carry
            total = val1 + val2 + carry
            carry = total // 10
            total = total % 10
            
            # Add the current sum to the new list
            current.next = ListNode(total)
            current = current.next
            
            # Move to the next nodes
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        
        return dummy.next