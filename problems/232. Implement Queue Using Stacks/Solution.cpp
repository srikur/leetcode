class MyQueue {
private:
    std::stack<int> myStack;
    std::stack<int> helperStack;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        myStack.push(x);
    }
    
    int pop() {
        while (myStack.size() > 1) {
            helperStack.push(myStack.top());
            myStack.pop();
        }
        int retVal = myStack.top();
        myStack.pop();
        while (helperStack.size() > 0) {
            myStack.push(helperStack.top());
            helperStack.pop();
        }
        return retVal;
    }
    
    int peek() {
        while (myStack.size() > 1) {
            helperStack.push(myStack.top());
            myStack.pop();
        }
        int retVal = myStack.top();
        while (helperStack.size() > 0) {
            myStack.push(helperStack.top());
            helperStack.pop();
        }
        return retVal;
    }
    
    bool empty() {
        return myStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */