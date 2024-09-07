class Node:
    def __init__(self, val=None):
        self.val = val  # The value stored in the node
        self.prev = None  # Pointer to the previous node
        self.next = None  # Pointer to the next node

class MyLinkedList:
    def __init__(self):
        # Create dummy head and tail nodes
        self.head = Node()  # Dummy head node
        self.tail = Node()  # Dummy tail node

        # Initially, link head and tail to each other
        self.head.next = self.tail
        self.tail.prev = self.head

        self.length = 0  # Number of elements in the list (excluding dummy nodes)

    # Get the value of the node at the given index
    def get(self, index: int) -> int:
        if index < 0 or index >= self.length:
            return -1  # Invalid index, return -1

        current = self.head.next  # Start from the first real node
        for _ in range(index):
            current = current.next
        return current.val

    # Add a node with value `val` at the head (index 0)
    def addAtHead(self, val: int) -> None:
        new_node = Node(val)

        # Insert new_node right after the dummy head
        first_real_node = self.head.next
        new_node.next = first_real_node
        new_node.prev = self.head

        self.head.next = new_node
        first_real_node.prev = new_node

        self.length += 1

    # Add a node with value `val` at the tail
    def addAtTail(self, val: int) -> None:
        new_node = Node(val)

        # Insert new_node right before the dummy tail
        last_real_node = self.tail.prev
        new_node.next = self.tail
        new_node.prev = last_real_node

        last_real_node.next = new_node
        self.tail.prev = new_node

        self.length += 1

    # Add a node with value `val` at the given index
    def addAtIndex(self, index: int, val: int) -> None:
        if index < 0 or index > self.length:
            return  # Invalid index, do nothing

        if index == 0:
            self.addAtHead(val)  # Special case: Insert at the head
        elif index == self.length:
            self.addAtTail(val)  # Special case: Insert at the tail
        else:
            new_node = Node(val)

            # Traverse to the node before the insertion point
            current = self.head.next
            for _ in range(index - 1):
                current = current.next

            # Insert new_node between current and current.next
            next_node = current.next
            new_node.next = next_node
            new_node.prev = current

            current.next = new_node
            next_node.prev = new_node

            self.length += 1

    # Delete the node at the given index
    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.length:
            return  # Invalid index, do nothing

        # Traverse to the node to delete
        current = self.head.next
        for _ in range(index):
            current = current.next

        # Update pointers to remove current node
        prev_node = current.prev
        next_node = current.next

        prev_node.next = next_node
        next_node.prev = prev_node

        self.length -= 1

    # Display list (for debugging purposes)
    def display(self):
        current = self.head.next
        elements = []
        while current != self.tail:
            elements.append(current.val)
            current = current.next
        print("List:", elements)

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)