from math import gcd
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        currentNode = head
        while ((currentNode != None) and (currentNode.next != None)):
            gcdNode = ListNode(gcd(currentNode.val, currentNode.next.val), currentNode.next)
            currentNode.next = gcdNode
            currentNode = currentNode.next.next
        return head