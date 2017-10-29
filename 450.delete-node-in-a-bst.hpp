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
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if(!root->right) return root->left;
            if(!root->left) return root->right;
            auto x = root;
            root = min(root->right);
            root->right = deleteMin(x->right);
            root->left = x->left;
        }
        return root;
    }
    TN* min(TN* node) {
        if(!node->left) return node;
        return min(node->left);
    }

    TN* deleteMin(TN* node) {
        if(!node->left) return node->right;
        node->left = deleteMin(node->left);
        return node;
    }
};
