struct Node {
    bool isEnd = false;
    vector<Node*> next;
    Node(): next(vector<Node*>(26, NULL)) {}
};

class Trie {
    Node* root = NULL;
public:
    Trie() {
        root = new Node();
    }
    void insert(const string& s) {
        auto x = root;
        for(char c: s) {
            int i = c - 'a';
            if(!x->next[i]) {
                x->next[i] = new Node();
            }
            x = x->next[i];
        }
        x->isEnd = true;
    }

    bool search(const string& s) {
        return search(0, s, root);
    }

    bool search(int p, const string& s, Node* node) {
        if(!node) return false;
        if(p == s.length()) return node->isEnd;
        if(s[p] == '*') {
            for(auto x: node->next) {
                if(search(p+1, s, x))
                    return true;
            }
        } else {
            return search(p+1, s, node->next[s[p]-'a']);
        }
        return false;
    }
};

class Solution {
    Trie trie;
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        int n = target.length();
        for(auto& s: dictionary) {
            if(s.length() == n)
                trie.insert(s);
        }
        string path(n, '*');
        string ans;
        int minLen = n+1;
        dfs(0, path, target, minLen, ans);
        return abbrev(ans);
    }
    void dfs(int p, string& path, string& target, int& minLen, string& ans) {
        int n = path.length();
        int curLen = abbrevLen(path);
        if(curLen < minLen && !trie.search(path)) {
            ans = path;
            minLen = curLen;
        }
        for(int i = p; i < n; i++) {
            path[i] = target[i];
            dfs(i+1, path, target, minLen, ans);
            path[i] = '*';
        }
    }
    int abbrevLen(const string& s) {
        int len = 0;
        for(int i = 0; i < s.length();) {
            if(s[i] != '*') {
                i++;
                len++;
            } else {
                int j = 0;
                while(s[i+j] == '*') j++;
                len ++;
                i += j;
            }
        }
        return len;
    }
    string abbrev(const string& s) {
        string t;
        for(int i = 0; i < s.length();) {
            if(s[i] != '*') {
                t.push_back(s[i++]);
            } else {
                int j = 0;
                while(s[i+j] == '*') j++;
                t += to_string(j);
                i += j;
            }
        }
        return t;
    }
};
