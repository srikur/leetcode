class MyQueue {

    private Stack<Integer> stack;
    private Stack<Integer> helperStack;

    public MyQueue() {
        stack = new Stack<>();
        helperStack = new Stack<>();
    }
    
    public void push(int x) {
        stack.push(x);
    }
    
    public int pop() {
        while (stack.size() > 1) {
            helperStack.push(stack.pop());
        }
        int retVal = stack.pop();
        while (helperStack.size() > 0) {
            stack.push(helperStack.pop());
        }
        return retVal;
    }
    
    public int peek() {
        while (stack.size() > 1) {
            helperStack.push(stack.pop());
        }
        int retVal = stack.pop();
        stack.push(retVal);
        while (helperStack.size() > 0) {
            stack.push(helperStack.pop());
        }
        return retVal;
    }
    
    public boolean empty() {
        return stack.empty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */