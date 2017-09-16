class Trie {
private:
    static const int R = 26;
    struct Node {
        bool isEnd = false;
        Node* children[R] = {NULL};
        Node() {}
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto x = root;
        for(auto&& c: word) {
            int i = charToIndex(c);
            if(!x->children[i])
                x->children[i] = new Node();
            x = x->children[i];
        }
        x->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto x = root;
        for(auto&& c: word) {
            int i = charToIndex(c);
            if(!x->children[i]) return false;
            x = x->children[i];
        }
        return x->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto x = root;
        for(auto&& c: prefix) {
            int i = charToIndex(c);
            if(!x->children[i]) return false;
            x = x->children[i];
        }
        return true;
    }

    int charToIndex(char c) {
        return c - 'a';
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
