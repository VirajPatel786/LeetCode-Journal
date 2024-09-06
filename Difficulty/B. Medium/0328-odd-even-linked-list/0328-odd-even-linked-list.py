# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head  # If the list is empty or has only one node, return it as is.

        # Initialize odd and even pointers
        odd = head
        even = head.next
        even_head = even  # Keep the head of the even nodes to attach later

        # Traverse the list, connecting odd nodes to odd and even nodes to even
        while even and even.next:
            odd.next = even.next  # Link current odd to the next odd
            odd = odd.next        # Move odd pointer forward
            even.next = odd.next  # Link current even to the next even
            even = even.next      # Move even pointer forward

        # Connect the end of the odd list to the head of the even list
        odd.next = even_head

        return head  # The head of the modified list is still the original head
        