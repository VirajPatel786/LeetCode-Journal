# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        # If either head is None, there's no intersection
        if not headA or not headB:
            return None

        # Initialize two pointers for the two lists
        pointerA, pointerB = headA, headB

        # Traverse both lists
        while pointerA != pointerB:
            # Move to the next node in the list, or to the head of the other list if reaching the end
            pointerA = pointerA.next if pointerA else headB
            pointerB = pointerB.next if pointerB else headA

        # Either they met at the intersection node, or both are None (no intersection)
        return pointerA
