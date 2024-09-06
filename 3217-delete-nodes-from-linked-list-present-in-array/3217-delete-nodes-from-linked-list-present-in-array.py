# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        # Convert the nums array into a set for O(1) lookups
        numsSet = set(nums)
        
        # Dummy node to simplify handling edge cases, like when the head needs to be removed
        dummyNode = ListNode(0, head)
        
        # Initialize pointers for the previous node and the current node
        prevNode = dummyNode
        currNode = head
        
        # Iterate through the linked list
        while currNode:
            if currNode.val in numsSet:
                # If current node's value is in the numsSet, skip it by adjusting prevNode's next pointer
                prevNode.next = currNode.next
            else:
                # Otherwise, move prevNode forward
                prevNode = currNode
            # Move the current node to the next one
            currNode = currNode.next
        
        # Return the head of the modified linked list (starting after the dummy node)
        return dummyNode.next
