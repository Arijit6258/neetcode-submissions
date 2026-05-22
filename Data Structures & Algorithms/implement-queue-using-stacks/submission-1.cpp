class MyQueue {
public:
    stack<int> primaryStack, secondaryStack;
    MyQueue() {
        
    }
    
    void push(int x) {
        //secondaryStack.push(x);
        while(!primaryStack.empty()) {
            secondaryStack.push(primaryStack.top());
            primaryStack.pop();
        }

        primaryStack.push(x);

        while(!secondaryStack.empty()) {
            primaryStack.push(secondaryStack.top());
            secondaryStack.pop();
        }

        //swap(primaryStack, secondaryStack);
    }
    
    int pop() {
        int t = primaryStack.top();
        primaryStack.pop();
        return t;
    }
    
    int peek() {
        return primaryStack.top();
    }
    
    bool empty() {
        return primaryStack.empty();
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