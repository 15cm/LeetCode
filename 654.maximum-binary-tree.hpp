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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(0, nums.size() - 1, nums);
    }
    TreeNode *buildTree(int lo, int hi, vector<int>& nums) {
        if(lo > hi) return NULL;
        int index = lo;
        for(int i = lo + 1; i <= hi; i++) {
            if(nums[i] > nums[index]) index = i;
        }
        auto node = new TreeNode(nums[index]);
        node->left = buildTree(lo, index - 1, nums);
        node->right = buildTree(index + 1, hi, nums);
        return node;
    }
};
