class Solution {
public:
    string simplifyPath(string path) {
        string current;
        stack<string> folder;
        for (int i = 0; i <= path.size(); i++) {
            char ch = path[i];
            if (path[i] == '/' || i == path.size()) {
                if (current == ".." && !folder.empty()) folder.pop();
                if (current != "" && current != "." && current != "..") folder.push(current);
                
                current = "";
            } else {
                current += ch;
            }
        }

        stack<string> reverse;
        
        while(folder.size() != 0) {
            reverse.push(folder.top());
            folder.pop();
        }

        string ans = "/";
        while(!reverse.empty()) {
            ans += reverse.top() + "/";
            reverse.pop();
        }

        return ans.size() > 1 ? ans.substr(0, ans.size()-1) : ans;
    }
};