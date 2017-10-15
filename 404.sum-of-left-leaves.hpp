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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, false, sum);
        return sum;
    }
    void helper(TreeNode *node, bool isLeft, int& sum) {
        if(!node) return;
        if(!node->left && !node->right && isLeft) sum += node->val;
        helper(node->left, true, sum);
        helper(node->right, false, sum);
    }
};
