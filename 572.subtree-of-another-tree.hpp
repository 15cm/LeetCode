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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string preS = preorder(s);
        string preT = preorder(t);
        return preS.find(preT) != string::npos;
    }
    string preorder(TreeNode *node) {
        if(!node)
            return "#";
        return "/" + to_string(node->val) + preorder(node->left) + preorder(node->right);
    }
};
