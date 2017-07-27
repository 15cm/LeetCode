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
    TreeNode *prevNode, *firstNode, *secondNode;
    void recoverTree(TreeNode* root) {
        prevNode = firstNode = secondNode = NULL;
        inOrderTraverse(root);
        int tmp = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = tmp;
    }
    void inOrderTraverse(TreeNode* root) {
        if(root == NULL) return;
        inOrderTraverse(root->left);
        if(prevNode != NULL) {
            if(prevNode->val >= root->val) {
                if(firstNode == NULL) firstNode = prevNode;
                secondNode = root;
            }
        }
        prevNode = root;
        inOrderTraverse(root->right);
    }
};
