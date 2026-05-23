class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        // next greater element -> monotonic decreasing
        stack<int> mono;
        int n = temp.size();
        vector<int> ans(n);
        for (int i = n-1; i >= 0; i--) {
            while(!mono.empty() && temp[i] >= temp[mono.top()]) {
                mono.pop();
            }

            if (mono.empty()) ans[i] = 0;
            else ans[i] = mono.top()-i;

            mono.push(i);
        }

        return ans;
    }
};
