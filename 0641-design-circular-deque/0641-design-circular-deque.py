class MyCircularDeque:
    """
    Circular deque implementation using a fixed-size circular buffer.

    Attributes:
    capacity (int): Maximum number of elements the deque can hold.
    length (int): Current number of elements in the deque.
    front (int): Index pointing to the front of the deque.
    rear (int): Index pointing to the rear of the deque.
    dequeue (list): Fixed-size list to store the elements of the deque.
    """

    def __init__(self, k: int):
        """
        Initializes the deque with a specified capacity.

        Parameters:
        k (int): The maximum capacity of the deque.
        """
        self.capacity = k
        self.dequeue = [-1] * k  # Pre-allocate the circular buffer
        self.front = 0  # Points to the front index
        self.rear = -1  # Points to the rear index (initially no elements)
        self.length = 0  # Current number of elements in the deque

    def insertFront(self, value: int) -> bool:
        """
        Inserts an element at the front of the deque.

        Parameters:
        value (int): The value to insert at the front.

        Returns:
        bool: True if the operation is successful, False if the deque is full.
        """
        if self.isFull():
            return False
        self.front = (self.front - 1 + self.capacity) % self.capacity  # Move front pointer
        self.dequeue[self.front] = value
        self.length += 1
        return True

    def insertLast(self, value: int) -> bool:
        """
        Inserts an element at the rear of the deque.

        Parameters:
        value (int): The value to insert at the rear.

        Returns:
        bool: True if the operation is successful, False if the deque is full.
        """
        if self.isFull():
            return False
        self.rear = (self.rear + 1) % self.capacity  # Move rear pointer
        self.dequeue[self.rear] = value
        self.length += 1
        return True

    def deleteFront(self) -> bool:
        """
        Deletes an element from the front of the deque.

        Returns:
        bool: True if the operation is successful, False if the deque is empty.
        """
        if self.isEmpty():
            return False
        self.front = (self.front + 1) % self.capacity  # Move front pointer
        self.length -= 1
        return True

    def deleteLast(self) -> bool:
        """
        Deletes an element from the rear of the deque.

        Returns:
        bool: True if the operation is successful, False if the deque is empty.
        """
        if self.isEmpty():
            return False
        self.rear = (self.rear - 1 + self.capacity) % self.capacity  # Move rear pointer
        self.length -= 1
        return True

    def getFront(self) -> int:
        """
        Gets the front element of the deque.

        Returns:
        int: The front element, or -1 if the deque is empty.
        """
        if self.isEmpty():
            return -1
        return self.dequeue[self.front]

    def getRear(self) -> int:
        """
        Gets the rear element of the deque.

        Returns:
        int: The rear element, or -1 if the deque is empty.
        """
        if self.isEmpty():
            return -1
        return self.dequeue[self.rear]

    def isEmpty(self) -> bool:
        """
        Checks whether the deque is empty.

        Returns:
        bool: True if the deque is empty, False otherwise.
        """
        return self.length == 0

    def isFull(self) -> bool:
        """
        Checks whether the deque is full.

        Returns:
        bool: True if the deque is full, False otherwise.
        """
        return self.length == self.capacity


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()