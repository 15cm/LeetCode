/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef stack<TreeNode*> STN;
typedef stack<int> SI;
typedef TreeNode TN;
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        int n = nums.size();
        STN nodeStack;
        SI leftStack, rightStack;
        TN* root = new TN(0);
        nodeStack.push(root);
        leftStack.push(0);
        rightStack.push(n-1);
        while(!nodeStack.empty()) {
            TN* node = nodeStack.top(); nodeStack.pop();
            int left = leftStack.top(); leftStack.pop();
            int right = rightStack.top(); rightStack.pop();
            int mid = left + (right - left) / 2;
            node->val = nums[mid];
            if(left <= mid - 1) {
                TN* leftNode = new TN(0);
                node->left = leftNode;
                nodeStack.push(leftNode);
                leftStack.push(left);
                rightStack.push(mid - 1);
            }
            if(right >= mid + 1) {
                TN* rightNode = new TN(0);
                node->right = rightNode;
                nodeStack.push(rightNode);
                leftStack.push(mid + 1);
                rightStack.push(right);
            }
        }
        return root;
    }
};
