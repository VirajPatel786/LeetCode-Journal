# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        seenNodes = set()
        currentNode = head
        while(currentNode):
            if currentNode in seenNodes:
                return True
            seenNodes.add(currentNode)
            currentNode = currentNode.next
        return False
        