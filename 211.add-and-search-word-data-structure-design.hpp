struct Node {
    bool isEnd = false;
    Node* children[26] = {NULL};
};

class WordDictionary {
    Node* root = NULL;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* x = root;
        for(char c: word) {
            int idx = ctoi(c);
            if(!x->children[idx]) x->children[idx] = new Node();
            x = x->children[idx];
        }
        x->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(0, word, root);
    }
    bool search(int cur, string& word, Node* node) {
        if(cur == word.length())
            return node->isEnd;
        if(word[cur] == '.') {
            for(int i = 0; i < 26; i++) {
                if(node->children[i] && search(cur + 1, word, node->children[i])) return true;
            }
        } else {
            int idx = ctoi(word[cur]);
            if(node->children[idx])
                return search(cur + 1, word, node->children[idx]);
        }
        return false;
    }
    int ctoi(char c) {
        return c - 'a';
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
