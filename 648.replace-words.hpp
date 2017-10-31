#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Trie {
    struct Node {
        int val;
        vector<Node*> children;
        Node():val(-1), children(vector<Node*>(26, NULL)) {}
    };
    Node* root;
public:
    void insert(string s) {
        root = insert(root, 0, s);
    }
    Node* insert(Node* node, int p, string& s) {
        if(!node) node = new Node();
        if(p == s.length()) {
            node->val = p;
            return node;
        }
        int idx = s[p] - 'a';
        node->children[idx] = insert(node->children[idx], p + 1, s);
        return node;
    }

    int find(string s) {
        Node* x = find(root, 0 , s);
        return x ? x->val : -1;
    }

    Node* find(Node* node, int p, string& s) {
        if(!node) return NULL;
        if(node->val != -1 || p == s.length()) return node;
        int idx = s[p] - 'a';
        return find(node->children[idx], p + 1, s);
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie trie;
        for(auto& s: dict) {
            trie.insert(s);
        }
        istringstream is(sentence);
        ostringstream os;
        string s;
        while(is >> s) {
            int len = trie.find(s);
            if(len != -1) {
                os << s.substr(0, len) << " ";
            } else {
                os << s << " ";
            }
        }
        string ans = os.str();
        return ans.substr(0, ans.length() - 1);
    }
};
