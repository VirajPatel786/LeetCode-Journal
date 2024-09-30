class CustomStack:
    """
    Custom stack with fixed size that supports push, pop, and increment operations.

    Attributes:
    stack (list): Internal list to store the elements of the stack.
    stack_size (int): Current size of the stack.
    stack_capacity (int): Maximum capacity of the stack.
    """

    def __init__(self, maxSize: int):
        """
        Initialize the stack with a given maximum size.

        Parameters:
        maxSize (int): The maximum size of the stack.
        """
        self.stack: list[int] = []
        self.stack_size: int = 0
        self.stack_capacity: int = maxSize

    def push(self, x: int) -> None:
        """
        Push an element onto the stack if it's not full.

        Parameters:
        x (int): The element to be pushed onto the stack.
        """
        if self.stack_size < self.stack_capacity:
            self.stack.append(x)
            self.stack_size += 1

    def pop(self) -> int:
        """
        Pop an element from the stack and return it. 
        If the stack is empty, return -1.

        Returns:
        int: The popped element if stack is not empty, otherwise -1.
        """
        if self.stack_size != 0:
            self.stack_size -= 1
            return self.stack.pop()
        else:
            return -1

    def increment(self, k: int, val: int) -> None:
        """
        Increment the bottom k elements of the stack by val. 
        If the stack has fewer than k elements, increment all of them.

        Parameters:
        k (int): The number of elements from the bottom to be incremented.
        val (int): The value to increment by.
        """
        # Increment up to min(k, stack_size) to handle case where stack has fewer than k elements
        limit = min(k, self.stack_size)
        for i in range(limit):
            self.stack[i] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)