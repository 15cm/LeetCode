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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        inorder(root, sum);
        return root;
    }
    void inorder(TreeNode *node, int &sum) {
        if(!node) return;
        inorder(node->right, sum);
        node->val += sum;
        sum = node->val;
        inorder(node->left, sum);
    }
};
