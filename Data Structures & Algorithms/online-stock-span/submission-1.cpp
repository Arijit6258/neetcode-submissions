class StockSpanner {
public:
    int index;
    stack<pair<int,int>> span;
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        while(!span.empty() && span.top().first <= price) {
            span.pop();
        }

        int sp;
        if (span.empty()) {
            sp = index+1;
        } else {
            sp = index-span.top().second;
        }

        span.push({price,index});
        index++;
        return sp;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */