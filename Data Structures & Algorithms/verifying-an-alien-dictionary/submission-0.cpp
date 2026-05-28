class Solution {
public:
    map<char,char> lexicoOrder;

    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); i++) {
            lexicoOrder[order[i]] = i+'a';
        }

        for (string& word : words) {
            for (int i = 0; i < word.size(); i++) {
                word[i] = lexicoOrder[word[i]];
            }
        }

        //bool isLexicoSorted = true;

        for (int i = 0; i < words.size()-1; i++) {
            if (words[i] > words[i+1]) {
                return false;
            }
        }

        return true;
    }
};