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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int hl = 0, hr = 0;
        for(auto l = root; l; l = l->left) hl++;
        for(auto r = root; r; r = r->right) hr++;
        if(hl == hr) return (1 << hl) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
