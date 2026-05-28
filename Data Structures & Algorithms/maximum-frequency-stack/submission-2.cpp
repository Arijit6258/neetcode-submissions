class compare {
    public:
    bool operator()(vector<int>& p1, vector<int>& p2) {
        if (p1[1] < p2[1]) return true;
        else if (p1[1] == p2[1]) {
            if (p1[2] < p2[2]) return true;
            else return false;
        } else return false;
    }
};

class FreqStack {
public:
    // el, freq, pos
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;
    unordered_map<int,int> freq;
    int pos = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        pq.push({val,freq[val],pos});
        pos++;
    }
    
    int pop() {
        int f = pq.top()[0];
        pq.pop();
        freq[f]--;
        return f;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */