# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        """
        Rotates the linked list to the right by k places.

        Parameters:
        head (ListNode): The head of the linked list.
        k (int): Number of places to rotate the list to the right.

        Returns:
        ListNode: The new head of the rotated linked list.
        """
        
        # Edge case: If the list is empty or no rotation is needed, return the original list.
        if not head or k == 0:
            return head
        
        # Step 1: Find the length of the list and locate the last node (tail).
        length = 1  # Start with 1 to account for the head node.
        current = head
        
        while current.next:  # Traverse the list to find the length and tail.
            current = current.next
            length += 1
        
        tail = current  # Tail now points to the last node in the list.

        # Step 2: Calculate the effective number of rotations needed (modulo operation).
        k = k % length  # If k is greater than length, reduce the number of rotations.
        if k == 0:
            return head  # No rotation needed if k is 0 (after modulo).

        # Step 3: Create a circular list by connecting the tail to the head.
        tail.next = head

        # Step 4: Find the new tail position, which is (length - k) nodes from the start.
        steps_to_new_tail = length - k
        new_tail = head
        
        for _ in range(steps_to_new_tail - 1):  # Stop one node before the new head.
            new_tail = new_tail.next

        # Step 5: The new head will be the node after the new tail.
        new_head = new_tail.next

        # Step 6: Break the circular link by setting the next pointer of the new tail to None.
        new_tail.next = None

        return new_head  # Return the new head of the rotated list.
