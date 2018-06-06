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
    string tree2str(TreeNode* t) {
        if(!t) return "";
        stringstream ss;
        dfs(t, ss, true);
        return ss.str();
    }
    void dfs(TreeNode *node, stringstream &ss, bool isRoot) {
        if(!node) {
            ss << "()";
            return;
        }
        if(!isRoot) {
            ss << '(';
        }
        ss << to_string(node->val);
        if(node->left || node->right) {
            dfs(node->left, ss, false);
        }
        if(node->right) {
            dfs(node->right, ss, false);
        }
        if(!isRoot) {
            ss << ')';
        }
    }
};
