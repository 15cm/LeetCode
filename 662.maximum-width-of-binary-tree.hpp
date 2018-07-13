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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        vector<pair<TreeNode *, int>> lvl, tlvl;
        int ans = 0;
        lvl.emplace_back(root, 1);
        while(!lvl.empty()) {
            tlvl.clear();
            ans = max(ans, lvl.back().second - lvl.begin()->second + 1);
            for(auto &pr: lvl) {
                auto node = pr.first;
                int idx = pr.second;
                if(node->left) tlvl.emplace_back(node->left, idx * 2);
                if(node->right) tlvl.emplace_back(node->right, idx * 2 + 1);
            }
            lvl.swap(tlvl);
        }
        return ans;
    }
};
