# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        # Step 1: Find the length of the linked list
        length = 0
        current = head
        while current:
            length += 1
            current = current.next
        
        # Step 2: Determine the base size of each part and the number of extra nodes
        part_size = length // k
        extra_nodes = length % k
        
        result = []
        current = head
        
        # Step 3: Split the list into parts
        for i in range(k):
            part_head = current
            # Determine the size of the current part
            current_part_size = part_size + (1 if i < extra_nodes else 0)
            
            # Advance the current pointer to the end of the current part
            for j in range(current_part_size - 1):
                if current:
                    current = current.next
            
            # If there is a node, we need to break the connection to the rest of the list
            if current:
                next_part = current.next
                current.next = None
                current = next_part
            
            # Append the current part's head to the result
            result.append(part_head)
        
        # Step 4: If k > length of the list, append None for remaining parts
        while len(result) < k:
            result.append(None)
        
        return result