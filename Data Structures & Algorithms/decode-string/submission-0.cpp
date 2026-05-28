class Solution {
public:
    int stoi(string& s) {
        return s[0]-'0';
    }

    string decodeString(string s) {
        // process the string left to right.
        // keep pushing the characters inside a stack
        // once i hit a ] -> reprocess the chars / string in stack
        // until i hit a [ -> post that process the numeric value and create a repeated string and push the 
        // result back to stack.

        deque<string> buffer;
        string current = "";
        for (char& ch : s) {
            //cout << ch << endl;
            if (ch == ']') {
                string accumulate = current;
                current = "";
                while(buffer.back() != "[") {
                    accumulate = buffer.back() + accumulate;
                    buffer.pop_back();
                }

                buffer.pop_back(); // remove [

                // process the numeric value
                int power = 1;
                int frequency = 0;
                //cout << buffer.back() << endl;

                while(!buffer.empty() && (buffer.back()[0] <= '9' && buffer.back()[0] >= '0')) {
                    frequency += (power*stoi(buffer.back()));
                    power *= 10;
                    buffer.pop_back();
                }

                string final = "";
                while(frequency != 0) {
                    final += accumulate;
                    frequency--;
                }

                buffer.push_back(final);
            } else if (ch == '[') {
                //buffer.push_back(current);
                // = "";
                buffer.push_back(current+ch);
            } else if (ch <= '9' && ch >= '0') {
                //cout << current << endl;
                if (current != "") {
                    buffer.push_back(current);
                    current = "";
                }

                buffer.push_back(string(1, ch));
            } else {
                current += ch;
            }
        }

        if (current != "") buffer.push_back(current);

        string output = "";

        while(!buffer.empty()) {
            output += buffer.front();
            buffer.pop_front();
        }
        
        return output;
    }
};