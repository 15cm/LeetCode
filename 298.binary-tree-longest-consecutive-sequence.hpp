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
    struct Node {
        TN *cur, *parent;
        int len;
        Node(TN *cur, TN *parent, int len): cur(cur), parent(parent), len(len) {}
    };
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<Node> q;
        q.push(Node(root, NULL, 0));
        while(!q.empty()) {
            Node node = q.front(); q.pop();
            TN *cur = node.cur, *parent = node.parent;
            int len = node.len;
            int d = !parent ? 1 : cur->val == parent->val + 1 ? len + 1 : 1;
            ans = max(ans, d);
            if(cur->left) {
                q.push(Node(cur->left, cur, d));
            }
            if(cur->right) {
                q.push(Node(cur->right, cur, d));
            }
        }
        return ans;
    }
};
