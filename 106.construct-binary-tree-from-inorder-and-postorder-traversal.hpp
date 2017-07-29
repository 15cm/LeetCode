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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(0, postorder.size() - 1, postorder, 0, inorder.size() - 1, inorder);
    }
    TreeNode* build(int lp, int rp, vector<int>& postorder, int li, int ri, vector<int>& inorder) {
        if(lp > rp) return NULL;
        int rootVal = postorder[rp];
        int rootIndexInorder = li;
        while(rootIndexInorder <= ri && inorder[rootIndexInorder] != rootVal) rootIndexInorder++;
        int lsz = rootIndexInorder - li;
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(lp, lp + lsz - 1, postorder, li, rootIndexInorder - 1, inorder);
        root->right = build(lp + lsz, rp - 1, postorder, rootIndexInorder + 1, ri, inorder);
        return root;
    }
};
