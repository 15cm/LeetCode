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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return pathSumFrom(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int pathSumFrom(TreeNode* node, int sum) {
        if(!node) return 0;
        int rem = sum - node->val;
        return !rem + pathSumFrom(node->left, rem) + pathSumFrom(node->right, rem);
    }
};
