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
    bool checkEqualTree(TreeNode* root) {
        if(!root) return false;
        int sum = 0;
        getSum(root, sum);
        bool res = false;
        if(root->left) checkSubtree(root->left, sum, res);
        if(res) return res;
        if(root->right) checkSubtree(root->right, sum, res);
        return res;
    }
    void getSum(TreeNode *node, int &sum) {
        if(!node) return;
        sum += node->val;
        getSum(node->left, sum);
        getSum(node->right, sum);
    }
    int checkSubtree(TreeNode *node, int target, bool &res) {
        int left = 0, right = 0;
        if(node->left) {
            left = checkSubtree(node->left, target, res);
            if(res) return 0;
        }
        if(node->right) {
            right = checkSubtree(node->right, target, res);
            if(res) return 0;
        }
        int val = left + right + node->val;
        if(val * 2 == target) {
            res = true;
        }
        return val;
    }
};
