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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<double> nums;
        inorder(root, nums);
        int right = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int left = right - 1;
        vector<int> ans(k);
        for(int i = 0; i < k; i++) {
            if(left < 0) ans[i] = nums[right++];
            else if(right == nums.size()) ans[i] = nums[left--];
            else {
                double d1 = abs(nums[left] - target), d2 = abs(nums[right] - target);
                if (d1 < d2) ans[i] = nums[left--];
                else ans[i] = nums[right++];
            }
        }
        return ans;
    }
    void inorder(TreeNode* node, vector<double>& res) {
        if(!node) return;
        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }
};
