class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // if we consider i and j - two indexes.
        // rectangle formed in that range will have area = min ht * (j-i);

        int n = heights.size();
        vector<int> nseLeft(n, -1);
        stack<int> nse;
        for (int i = 0; i < n; i++) {
            while(!nse.empty()) {
                if (heights[nse.top()] < heights[i]) {
                    nseLeft[i] = nse.top();
                    break;
                }
                nse.pop();
            }

            nse.push(i);
        }

        while(!nse.empty()) {
            nse.pop();
        }

        vector<int> nseRight(n, n);

        for (int i = n-1; i >= 0; i--) {
            while(!nse.empty()) {
                if (heights[nse.top()] < heights[i]) {
                    nseRight[i] = nse.top();
                    break;
                }

                nse.pop();
            }

            nse.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            // << i << " " << nseRight[i] << " " << nseLeft[i] << endl;
            maxArea = max(maxArea, heights[i]*(nseRight[i]-nseLeft[i]-1));
        }

        return maxArea;
    }
};
