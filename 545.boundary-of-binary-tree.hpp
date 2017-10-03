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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return vector<int>();
        list<int> left, right, leaves;
        if(!root) return vector<int>();
        if(!root->left && !root->right) return vector<int> {root->val};
        left.push_back(root->val);
        if(root->left) dfsLeft(root->left, left);
        if(root->right) dfsRight(root->right, right);
        dfsLeaves(root, leaves);
        left.splice(left.end(), leaves);
        left.splice(left.end(), right);
        return vector<int>(left.begin(), left.end());
    }
    void dfsLeft(TreeNode *node, list<int>& left) {
        if(!node->left && !node->right) return;
        left.push_back(node->val);
        if(node->left) dfsLeft(node->left, left);
        else dfsLeft(node->right, left);
    }
    void dfsRight(TreeNode *node, list<int>& right) {
        if(!node->left && !node->right) return;
        right.push_front(node->val);
        if(node->right) dfsRight(node->right, right);
        else dfsRight(node->left, right);
    }
    void dfsLeaves(TreeNode *node, list<int>& leaves) {
        if(!node->left && !node->right) leaves.push_back(node->val);
        if(node->left) dfsLeaves(node->left, leaves);
        if(node->right) dfsLeaves(node->right, leaves);
    }
};
