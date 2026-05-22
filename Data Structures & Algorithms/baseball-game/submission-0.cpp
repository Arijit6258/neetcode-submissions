class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> ops;
        for (string& op : operations) {
            if (op == "+") {
                int a = ops.top(); ops.pop();
                int b = ops.top(); 
                ops.push(a);
                ops.push(a+b);
            } else if (op == "C") {
                ops.pop();
            } else if (op == "D") {
                ops.push(ops.top() * 2);
            } else {
                ops.push(stoi(op));
            }
        }

        int sum = 0;
        while(ops.size() != 0) {
            sum += ops.top();
            ops.pop();
        }

        return sum;
    }
};