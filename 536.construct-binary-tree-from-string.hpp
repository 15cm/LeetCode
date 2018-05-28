/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* str2tree(string s) {
        if(s.empty()) return NULL;
        int pos = 0;
        return parse(pos, s);
    }
    TreeNode *parse(int &p, const string& s) {
        string acc;
        TreeNode *node = NULL;
        int n = s.length();
        while(p < n) {
            char c = s[p++];
            if(c == '(' || c == ')') {
                if(!node) {
                    int val = stoi(acc);
                    node = new TreeNode(val);
                }
                if(c == '(') {
                    if(!node->left) {
                        node->left = parse(p, s);
                    } else {
                        node->right = parse(p, s);
                    }
                } else {
                    return node;
                }
            } else {
                acc.push_back(c);
            }
        }
        if(!node) {
            int val = stoi(acc);
            node = new TreeNode(val);
        }
        return node;
    }
};
