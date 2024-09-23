class Solution:
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
        """
        Merge two sorted linked lists into one sorted linked list.

        Parameters:
        list1 (ListNode): The head of the first sorted linked list.
        list2 (ListNode): The head of the second sorted linked list.

        Returns:
        ListNode: The head of the merged sorted linked list.
        """
        # Initialize a dummy node to simplify edge cases
        dummy = ListNode()
        tail = dummy
        
        # Iterate over both lists until one is empty
        while list1 and list2:
            if list1.val <= list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next
        
        # Append any remaining nodes from either list
        if list1:
            tail.next = list1
        else:
            tail.next = list2
        
        return dummy.next