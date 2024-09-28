class MyCircularDeque:
    """
    Circular deque implementation using a list with fixed capacity.
    
    Attributes:
    capacity (int): Maximum number of elements the deque can hold.
    length (int): Current number of elements in the deque.
    dequeue (list): List to store the elements of the deque.
    """

    def __init__(self, k: int):
        """
        Initializes the deque with a specified capacity.
        
        Parameters:
        k (int): The maximum capacity of the deque.
        """
        self.length = 0
        self.capacity = k
        self.dequeue = []

    def insertFront(self, value: int) -> bool:
        """
        Inserts an element at the front of the deque.
        
        Parameters:
        value (int): The value to insert at the front.
        
        Returns:
        bool: True if the operation is successful, False if the deque is full.
        """
        if self.length < self.capacity:  # Check if there's space to insert
            self.dequeue.insert(0, value)
            self.length += 1
            return True
        return False

    def insertLast(self, value: int) -> bool:
        """
        Inserts an element at the rear of the deque.
        
        Parameters:
        value (int): The value to insert at the rear.
        
        Returns:
        bool: True if the operation is successful, False if the deque is full.
        """
        if self.length < self.capacity:  # Check if there's space to insert
            self.dequeue.append(value)
            self.length += 1
            return True
        return False

    def deleteFront(self) -> bool:
        """
        Deletes an element from the front of the deque.
        
        Returns:
        bool: True if the operation is successful, False if the deque is empty.
        """
        if self.length == 0:  # Check if the deque is empty
            return False
        self.dequeue.pop(0)
        self.length -= 1
        return True

    def deleteLast(self) -> bool:
        """
        Deletes an element from the rear of the deque.
        
        Returns:
        bool: True if the operation is successful, False if the deque is empty.
        """
        if self.length == 0:  # Check if the deque is empty
            return False
        self.dequeue.pop()
        self.length -= 1
        return True

    def getFront(self) -> int:
        """
        Gets the front element of the deque.
        
        Returns:
        int: The front element, or -1 if the deque is empty.
        """
        if self.length == 0:
            return -1
        return self.dequeue[0]

    def getRear(self) -> int:
        """
        Gets the rear element of the deque.
        
        Returns:
        int: The rear element, or -1 if the deque is empty.
        """
        if self.length == 0:
            return -1
        return self.dequeue[-1]

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