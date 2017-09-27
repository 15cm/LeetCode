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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* succ = NULL;
        while(root) {
            if(p->val < root->val) {
                succ = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return succ;
    }
};
