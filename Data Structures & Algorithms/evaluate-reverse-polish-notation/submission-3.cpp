class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        set<string> ops = {"+", "-", "*", "/"};

        for(string& token : tokens) {
            if (ops.find(token) == ops.end()) {
                st.push(stoi(token));
            } else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if (token == "+") 
                    st.push(a+b);
                else if (token == "*")
                    st.push(a*b);
                else if (token == "-")
                    st.push(a-b);
                else if (token == "/")
                    st.push(a/b);
            }
        }

        return st.top();
    }
};
