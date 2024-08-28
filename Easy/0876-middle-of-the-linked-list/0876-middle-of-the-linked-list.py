# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if (head.next == None):
            return head
        
        count = 1
        node_list = list()
        node_list.append(head)

        temp = head
        while (temp.next != None):
            count += 1
            node_list.append(temp.next)
            temp = temp.next
        
        node_num = (count // 2)
        return node_list[node_num]