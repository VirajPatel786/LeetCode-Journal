# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # Create a dummy node and point it to head to handle edge cases easily
        dummy = ListNode(0, head)
        first = dummy
        second = dummy
        
        # Move first pointer n+1 steps ahead
        for _ in range(n + 1):
            first = first.next
        
        # Move both first and second pointers until first reaches the end
        while first:
            first = first.next
            second = second.next
        
        # Now, second is at the node before the one we want to remove
        second.next = second.next.next
        
        # Return the modified list, dummy.next is the new head
        return dummy.next

        