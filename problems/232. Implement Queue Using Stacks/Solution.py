class MyQueue:
    stack = []
    helperStack = []

    def __init__(self):
        self.stack = []
        self.helperStack = []

    def push(self, x: int) -> None:
        self.stack.append(x)
        return None

    def pop(self) -> int:
        while len(self.stack) > 1:
            self.helperStack.append(self.stack.pop())
        ret = self.stack.pop()
        # self.stack.append(ret)
        while len(self.helperStack) > 0:
            self.stack.append(self.helperStack.pop())
        return ret

    def peek(self) -> int:
        while len(self.stack) > 1:
            self.helperStack.append(self.stack.pop())
        ret = self.stack.pop()
        self.stack.append(ret)
        while len(self.helperStack) > 0:
            self.stack.append(self.helperStack.pop())
        return ret

    def empty(self) -> bool:
        return len(self.stack) == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()