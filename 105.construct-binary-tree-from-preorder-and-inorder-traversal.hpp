/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef TreeNode TN;
typedef vector<int> VI;
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0, preorder, 0, inorder.size() - 1, inorder);
    }
    TN* helper(int preLo, VI& preorder, int inLo, int inHi, VI& inorder) {
        if(preLo >= preorder.size() || inLo > inHi) return NULL;
        TN* x = new TN(preorder[preLo]);
        int inIdx = inLo;
        for(; inIdx <= inHi && inorder[inIdx] != x->val; inIdx++);
        x->left = helper(preLo + 1, preorder, inLo, inIdx - 1, inorder);
        x->right = helper(preLo + inIdx - inLo + 1, preorder, inIdx + 1, inHi, inorder);
        return x;
    }
};
