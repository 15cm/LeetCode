struct Node {
    bool is_end;
    Node* next[26];
    Node() {
        is_end = false;
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};

class Trie {
    Node *root;
public:
    Trie() {
        root = new Node();
    }

    void insert(const string &s) {
        auto x = root;
        for(char c: s) {
            auto &p = x->next[c - 'a'];
            if(!p) p = new Node();
            x = p;
        }
        x->is_end = true;
    }

    bool query(const string &s) {
        return query(root, s, 0, true);
    }
private:
    bool query(Node* node, const string &s, int p, bool can_magic) {
        int n = s.size();
        if(p == n) {
            return node->is_end && !can_magic;
        }
        for(int i = 0; i < 26; i++) {
            auto next_node = node->next[i];
            if(!next_node) continue;
            int id = s[p] - 'a';
            if(id == i) {
                if(query(next_node, s, p + 1, can_magic))
                    return true;
            } else {
                if(can_magic && query(next_node, s, p + 1, false))
                    return true;
            }
        }
        return false;
    }
};
class MagicDictionary {
    Trie trie;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto &s: dict)
            trie.insert(s);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return trie.query(word);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
