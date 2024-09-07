class Node:
    def __init__(self, val):
        self.prev = None  # Pointer to the previous node
        self.val = val    # Value stored in the node
        self.next = None  # Pointer to the next node

class MyLinkedList:
    def __init__(self):
        self.head = None  # Head pointer to the first node of the list
        self.length = 0   # Length of the linked list

    # Get the value of the node at the given index
    def get(self, index: int) -> int:
        if index >= self.length or index < 0:
            return -1  # Return -1 if the index is invalid
        currentNode = self.head
        while index:
            currentNode = currentNode.next
            index -= 1
        return currentNode.val

    # Add a new node with value `val` at the head of the list
    def addAtHead(self, val: int) -> None:
        newNode = Node(val)
        if self.head is None:  # If the list is empty, just set head to newNode
            self.head = newNode
        else:
            newNode.next = self.head
            self.head.prev = newNode  # Update the previous head's `prev` pointer
            self.head = newNode       # Move the head to the new node
        self.length += 1

    # Add a new node with value `val` at the tail of the list
    def addAtTail(self, val: int) -> None:
        newNode = Node(val)
        if self.head is None:  # If the list is empty, set the head to newNode
            self.head = newNode
        else:
            currentNode = self.head
            while currentNode.next is not None:  # Traverse to the last node
                currentNode = currentNode.next
            currentNode.next = newNode  # Link the last node to the new node
            newNode.prev = currentNode  # Set the `prev` pointer of the new node
        self.length += 1    

    # Add a new node with value `val` at the given index
    def addAtIndex(self, index: int, val: int) -> None:
        if index < 0 or index > self.length:
            return  # Invalid index
        elif index == 0:
            self.addAtHead(val)  # Insert at the head
        elif index == self.length:
            self.addAtTail(val)  # Insert at the tail
        else:
            newNode = Node(val)
            currentNode = self.head
            for _ in range(index - 1):
                currentNode = currentNode.next  # Traverse to the node just before the index
            newNode.next = currentNode.next
            newNode.prev = currentNode
            currentNode.next.prev = newNode  # Update the next node's `prev` pointer
            currentNode.next = newNode       # Link the current node to the new node
            self.length += 1

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.length:
            return  # Invalid index
        elif index == 0:
            # Deleting the head node
            if self.length == 1:
                self.head = None  # If there's only one element, set head to None
            else:
                self.head = self.head.next  # Move head to the next node
                self.head.prev = None       # Set the new head's `prev` to None
        else:
            currentNode = self.head
            for _ in range(index - 1):
                currentNode = currentNode.next  # Traverse to the node just before the index
            nodeToDelete = currentNode.next
            currentNode.next = nodeToDelete.next  # Link the current node to the next of next
            if nodeToDelete.next is not None:
                nodeToDelete.next.prev = currentNode  # Update the `prev` pointer if not deleting the tail
        self.length -= 1

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)