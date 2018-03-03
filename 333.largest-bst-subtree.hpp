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
    struct Box {
        bool isNull;
        int minValue;
        int maxValue;
        bool isBST;
        int size;
        Box(bool isNull, int minv, int maxv, bool isBST, int size): isNull(isNull), minValue(minv), maxValue(maxv), isBST(isBST), size(size) {}
    };
    int ans = 0;
public:
    int largestBSTSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
    Box helper(TreeNode* node) {
        if(!node) return Box(true, -1, -1, true, 0);
        auto left = helper(node->left);
        auto right = helper(node->right);

        if((left.isNull || left.isBST && node->val > left.maxValue) && (right.isNull || right.isBST && node->val < right.minValue)) {
            int sz = left.size + right.size + 1;
            ans = max(ans, sz);
            return Box(false, left.isNull ? node->val : left.minValue, right.isNull ? node->val : right.maxValue, true, sz);
        } else {
            return Box(false, -1, -1, false, 0);
        }
    }
};
