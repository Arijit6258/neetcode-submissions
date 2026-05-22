class Node {
    public:
    char character;
    bool isEnd; // is this node is end of an word?
    vector<Node*> children;
    
    Node(char ch) {
        character = ch;
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children.push_back(NULL);
        }
    }
};

class PrefixTree {
public:
    Node* root;

    PrefixTree() {
        root = new Node('-');
    }
    
    /*
        - --> d --> o --> g (end = true)
    */

    void insert(string word) {
        Node* node = root; 
        for (char ch : word) {
            Node* next = node->children[ch-'a'];
            if (next == NULL) {
                next = new Node(ch);
                node->children[ch-'a'] = next;
            }

            node = next;
        }

        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;
        int ind = 0;
        while(node != NULL && ind < word.size()) {
            node = node->children[word[ind]-'a'];
            ind++;
        }

        return node != NULL && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        int ind = 0;
        while(node != NULL && ind < prefix.size()) {
            //cout << node->character << endl;
            node = node->children[prefix[ind]-'a'];
            ind++;
        }

        return node != NULL;
    }
};
