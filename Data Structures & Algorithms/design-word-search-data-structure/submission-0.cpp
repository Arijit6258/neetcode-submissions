class TrieNode {
    public:
    char currCh;
    bool isEnd;
    vector<TrieNode*> children;

    TrieNode(char ch) {
        this->currCh = ch;
        this->isEnd = false;
        for (int i = 0; i < 26; i++) {
            children.push_back(NULL);
        }
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode('+');
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children[ch-'a'] == NULL) {
                node->children[ch-'a'] = new TrieNode(ch);
            }

            node = node->children[ch-'a'];
        }

        node->isEnd = true;
    }
    
    bool search(TrieNode* node, string word, int ind) {
        if (node == nullptr) return false;
        if (ind == word.size()) return node->isEnd;

        char ch = word[ind];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] == NULL) continue;
                if (search(node->children[i], word, ind+1)) return true;
            }
        } else {
            return search(node->children[ch-'a'], word, ind+1);
        }

        return false;
    }

    bool search(string word) {
        TrieNode* node = root;
        return search(root, word, 0);
    }
};
