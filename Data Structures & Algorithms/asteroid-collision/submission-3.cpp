class Solution {
public:
    vector<int> asteroidCollision(vector<int> asteroids) {
        int top = -1;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            if (top == -1) {
                asteroids[top+1] = asteroids[i];
                top++;
            } else if (asteroids[i] < 0 && asteroids[top] < 0) {
                asteroids[top+1] = asteroids[i];
                top++;
            } else if (asteroids[i] < 0 && asteroids[top] > 0) {
                while(true) {
                    if (top == -1 || asteroids[top] < 0) {
                        asteroids[top+1] = asteroids[i];
                        top++;
                        break;
                    } else if (asteroids[top] < abs(asteroids[i])) {
                        top--;
                    } else if (asteroids[top] == abs(asteroids[i])) {
                        top--;
                        break;
                    } else {
                        break;
                    } 
                }
            } else {
                asteroids[top+1] = asteroids[i];
                top++;
            }
        }

        vector<int> ans;
        for (int i = 0; i <= top; i++) {
            ans.push_back(asteroids[i]);
        }

        return ans;
    }
};