class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
            while(!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        } else {
            q2.push(x);
            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    
    int pop() {
        int f;
        if (q1.empty()) {
            f = q2.front();
            q2.pop();
        } else {
            f = q1.front();
            q1.pop();
        }

        return f;
    }
    
    int top() {
        if (q1.empty()) {
            return q2.front();
        } else {
            return q1.front();
        }
    }
    
    bool empty() {
        return q1.size() == 0 && q2.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */