class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class MyLinkedList:
    def __init__(self):
        self.head = None
        self.length = 0

    def get(self, index: int) -> int:
        if ((index >= self.length) or (index < 0)):
            return -1
        else:
            currentNode = self.head
            while (index):
                currentNode = currentNode.next
                index -= 1
            return currentNode.val

    def addAtHead(self, val: int) -> None:
        newNode = Node(val)
        newNode.next = self.head
        self.head = newNode
        self.length += 1

    def addAtTail(self, val: int) -> None:
        newNode = Node(val)
        if (self.head is None):
            self.head = newNode
        else:
            currentNode = self.head
            while (currentNode.next is not None):
                currentNode = currentNode.next
            currentNode.next = newNode
        self.length += 1

    def addAtIndex(self, index: int, val: int) -> None:
        if ((index < 0) or (index > self.length)):
            return 
        elif (index == 0):
            self.addAtHead(val)
        elif (index == self.length):
            self.addAtTail(val)
        else:
            newNode = Node(val)
            currentNode = self.head
            for _ in range(index - 1):
                currentNode = currentNode.next
            newNode.next = currentNode.next
            currentNode.next = newNode
            self.length += 1

    def deleteAtIndex(self, index: int) -> None:
        if ((index < 0) or (index >= self.length)):
            return 
        elif (index == 0):
            self.head = self.head.next
        else:
            currentNode = self.head
            for _ in range(index - 1):
                currentNode = currentNode.next
            currentNode.next = currentNode.next.next
        self.length -= 1

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)