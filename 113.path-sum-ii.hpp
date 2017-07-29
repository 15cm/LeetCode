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
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum, vector<int>());
        return ans;
    }
    void dfs(TreeNode* root, int sum, vector<int> path) {
        if(!root) return;
        path.push_back(root->val);
        int sumLeft = sum - root->val;
        if(!root->left && !root->right && sumLeft == 0) ans.push_back(path);
        else {
            dfs(root->left, sumLeft, path);
            dfs(root->right, sumLeft, path);
        }
    }
};
