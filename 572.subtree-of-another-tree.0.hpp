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
        if(!t) return !s;
        return dfs(s, t);
    }
    bool isEqual(TreeNode *x, TreeNode *y) {
        if(!x) return !y;
        if(!y) return !x;
        return x->val == y->val && isEqual(x->left, y->left) && isEqual(x->right, y->right);
    }
    bool dfs(TreeNode *node, TreeNode *root) {
        return node && (isEqual(node, root) || dfs(node->left, root) || dfs(node->right, root));
    }
};
