class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustedBy(n+1);
        vector<int> trusting(n+1);
        
        for (int i = 0; i < trust.size(); i++) {
            trustedBy[trust[i][1]]++;
            trusting[trust[i][0]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (trustedBy[i] == n-1 && trusting[i] == 0)
                return i;
        }

        return -1;
    }
};