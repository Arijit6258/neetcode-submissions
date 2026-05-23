class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> astStack;
        for (int asteroid : asteroids) {
            if (asteroid < 0) {
                if (astStack.empty() || astStack.top() < 0) {
                    astStack.push(asteroid);
                } else {
                    while(true) {
                        if (astStack.empty()) {
                            astStack.push(asteroid);
                            break;
                        } 

                        if (astStack.top() > abs(asteroid)) {
                            break;
                        } else if (astStack.top() < 0) {
                            astStack.push(asteroid);
                            break;
                        } else if (astStack.top() > 0 && astStack.top() < abs(asteroid)) {
                            astStack.pop();
                        } else if (astStack.top() > 0 && astStack.top() == abs(asteroid)) {
                            astStack.pop();
                            break;
                        }
                    }
                }
            } else {
                astStack.push(asteroid);
            }
        }

        vector<int> ans;

        while(astStack.size() != 0) {
            ans.push_back(astStack.top());
            astStack.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};