class CustomStack:

    def __init__(self, maxSize: int):
        self.stack = list()
        self.stack_size = 0
        self.stack_capacity = maxSize

    def push(self, x: int) -> None:
        if self.stack_size < self.stack_capacity:
            self.stack.append(x)
            self.stack_size += 1

    def pop(self) -> int:
        if self.stack_size != 0:
            self.stack_size -= 1
            return self.stack.pop()
        else:
            return -1

    def increment(self, k: int, val: int) -> None:
        if self.stack_size >= k:
            for i in range(k):
                self.stack[i] += val
        else:
            for i in range(self.stack_size):
                self.stack[i] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)