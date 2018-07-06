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
        int n = nums.size(), m = log2(n) + 1;
        vector<vector<int>> dp(n, vector<int>(m+1, -1));
        for(int i = 0; i < n; i++) dp[i][0] = i;
        for(int j = 1; j <= m; j++) {
            for(int i = 0; i + (1 << j) -1 < n; i++) {
                int left = dp[i][j-1], right = dp[i + (1 << (j-1))][j-1];
                dp[i][j] = (nums[left] > nums[right]) ? left : right;
            }
        }
        return buildTree(0, n - 1, dp, nums);
    }
    int queryIndex(int lo, int hi, vector<vector<int>> &dp, vector<int> &nums) {
        int k = log2(hi - lo + 1);
        int left = dp[lo][k], right = dp[hi - (1 << k) + 1][k];
        return nums[left] > nums[right] ? left : right;
    }
    TreeNode *buildTree(int lo, int hi, vector<vector<int>> &dp, vector<int> &nums) {
        if(lo > hi) return NULL;
        int index = queryIndex(lo, hi, dp, nums);
        auto node = new TreeNode(nums[index]);
        node->left = buildTree(lo, index - 1, dp, nums);
        node->right = buildTree(index + 1, hi, dp, nums);
        return node;
    }
};
