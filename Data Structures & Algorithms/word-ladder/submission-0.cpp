class Solution {
public:
    bool isAdjacent(string& word1, string& word2) {
        int diffCount = 0;
        for (int i = 0; i < word1.size(); i++) {
            if (word1[i] != word2[i]) diffCount++;
        }

        //cout << word1 << ""

        return diffCount == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // from a word - single character change = adjacent word
        // find the minimum distance --> dijkstra

        queue<string> words;
        words.push(beginWord);
        map<string,bool> encountered;
        encountered[beginWord] = true;
        int distance = 0;

        while(words.size() != 0) {
            int qs = words.size();
            while(qs--) {
                string front = words.front();
                if (front == endWord) return distance+1;
                words.pop();

                for (string& word : wordList) {
                    if (encountered.find(word) == encountered.end() && 
                    isAdjacent(word, front)) {
                        words.push(word);
                        encountered[word] = true;
                    }
                }
            }

            distance++;
        }

        return 0;
    }
};
