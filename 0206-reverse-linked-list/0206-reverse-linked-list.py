# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize previous pointer to None
        prev = None
        current = head
        
        while current:
            # Save the next node
            next_node = current.next
            # Reverse the current node's pointer
            current.next = prev
            # Move the previous and current pointers one step forward
            prev = current
            current = next_node
        
        # At the end, prev will be the new head of the reversed list
        return prev