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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    int dfs(TreeNode* x, int acc) {
        if(!x) return 0;
        int sum = x->val + acc * 10;
        if(!x->left && !x->right) return sum;
        return dfs(x->left, sum) + dfs(x->right, sum);
    }
};
