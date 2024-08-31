# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        # Initialize a dummy node to handle edge cases easily
        dummy = ListNode(0)
        dummy.next = head
        
        current = dummy
        
        # Traverse the list
        while current.next:
            if current.next.val == val:
                # Skip the node with the target value
                current.next = current.next.next
            else:
                # Move current forward only if no node is removed
                current = current.next
        
        # Return the new head of the list
        return dummy.next