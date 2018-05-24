class Trie {
    struct Node {
        int cnt = 0;
        Node *next[26] = {NULL};
        Node() {}
    };

    Node *root;

public:
    Trie() {
        root = new Node();
    }

    void insert(const string &s) {
        auto x = root;
        int n = s.size();
        for(int i = 1; i < n; i++) {
            int idx = s[i] - 'a';
            if(!x->next[idx])
                x->next[idx] = new Node();
            x->cnt++;
            x = x->next[idx];
        }
    }

    int firstUnique(const string &s) {
        auto x = root;
        int n = s.size();
        for(int i = 1; i < n; i++) {
            if(x->cnt == 1) return i - 1;
            x = x->next[s[i] - 'a'];
        }
        return n - 1;
    }

    void clear(Node *node) {
        if(!node) return;
        for(int i = 0; i < 26; i++) {
            clear(node->next[i]);
        }
        delete node;
    }

    ~Trie() {
        clear(root);
    }
};

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        vector<string> ans(n);
        unordered_map<string, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[abbrev(dict[i], 0)].push_back(i);
        }

        for(const auto &pr: mp) {
            Trie trie;
            auto &group = pr.second;
            for(int idx: group) {
                const auto &s = dict[idx];
                trie.insert(s);
            }

            for(int idx: group) {
                const auto &s = dict[idx];
                ans[idx] = abbrev(s, trie.firstUnique(s));
            }
        }

        return ans;
    }

    string abbrev(const string &s, int i) {
        int n = s.size();
        if(n - i <= 3) return s;
        return s.substr(0, i + 1) + to_string(n - i - 2) + s[n-1];
    }
};
