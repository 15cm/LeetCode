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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(0, preorder.size() - 1, preorder, 0, inorder.size() - 1, inorder);
    }
    TreeNode* build(int lp, int rp, vector<int>& preorder, int li, int ri, vector<int>& inorder) {
        if(lp > rp) return NULL;
        int rootVal = preorder[lp];
        int rootIndexInorder = li;
        while(rootIndexInorder <= ri && inorder[rootIndexInorder] != rootVal) rootIndexInorder++;
        int lsz = rootIndexInorder - li;
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(lp + 1, lp + lsz, preorder, li, rootIndexInorder - 1, inorder);
        root->right = build(lp + lsz + 1, rp, preorder, rootIndexInorder + 1, ri, inorder);
        return root;
    }
};
