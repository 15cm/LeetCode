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
    int rob(TreeNode* root) {
        auto p = robSub(root);
        return max(p.first, p.second);
    }
    pair<int, int> robSub(TreeNode* root) {
        if(!root) return make_pair(0, 0);
        auto pl = robSub(root->left);
        auto pr = robSub(root->right);
        int vNotRub = max(pl.first, pl.second) + max(pr.first, pr.second);
        int vRub = root->val + pl.first + pr.first;
        return make_pair(vNotRub, vRub);
    }
};
