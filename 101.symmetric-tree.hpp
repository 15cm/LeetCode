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
    bool isSymmetric(TreeNode* root) {
        return !root || isEqual(root->left, root->right);
    }
    bool isEqual(TreeNode* x, TreeNode* y) {
        return !x || !y ? !x && !y
            : (x->val == y->val)
            && isEqual(x->left, y->right)
            && isEqual(x->right, y->left);
    }
};
