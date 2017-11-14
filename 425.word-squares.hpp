#include <iostream>
#include <vector>
using namespace std;
struct Node {
    vector<string> words;
    vector<Node*> next;
    Node(): next(vector<Node*>(26, NULL)) {}
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(string& s) {
        auto x = root;
        for(auto c: s) {
            int i = c - 'a';
            if(!x->next[i])
                x->next[i] = new Node();
            x->next[i]->words.push_back(s);
            x = x->next[i];
        }
    }

    vector<string> search(string& s) {
        auto x = root;
        for(auto c: s) {
            int i = c - 'a';
            if(!x->next[i])
                return vector<string>();
            x = x->next[i];
        }
        return x->words;
    }
};

class Solution {
    Trie trie;
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> ans;
        if(words.empty()) return ans;

        for(auto& word: words)
            trie.insert(word);
        int len = words[0].length();
        vector<string> path;
        for(auto& word: words) {
            path.push_back(word);
            dfs(path, len, ans);
            path.pop_back();
        }
        return ans;
    }

    void dfs(vector<string>& path, int len, vector<vector<string>>& ans) {
        if(path.size() == len) {
            ans.push_back(path);
            return;
        }
        int cur = path.size();
        string prefix;
        for(int i = 0; i < cur; i++) {
            prefix.push_back(path[i][cur]);
        }
        for(auto& s: trie.search(prefix)) {
            path.push_back(s);
            dfs(path, len, ans);
            path.pop_back();
        }
    }
};
