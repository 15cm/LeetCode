#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Trie {
    struct Node {
        bool isEnd;
        vector<Node*> children;
        Node():isEnd(false), children(vector<Node*>(26, NULL)) {}
    };
    Node* root;
public:
    void insert(string s) {
        root = insert(root, 0, s);
    }
    Node* insert(Node* node, int p, string& s) {
        if(!node) node = new Node();
        if(p == s.length()) {
            node->isEnd = true;
            return node;
        }
        int idx = s[p] - 'a';
        node->children[idx] = insert(node->children[idx], p + 1, s);
        return node;
    }

    int find(string s) {
        return find(root, 0, s);
    }

    int find(Node* node, int p, string& s) {
        if(!node) return -1;
        if(node->isEnd) return 0;
        if(p == s.length()) return -1;
        int idx = s[p] - 'a';
        int tmp = find(node->children[idx], p + 1, s);
        return tmp == -1 ? -1 : 1 + tmp;
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
