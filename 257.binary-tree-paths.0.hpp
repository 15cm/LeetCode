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
    struct Node {
        TreeNode *tn = NULL;
        list<int> path;
        Node(TreeNode* tn, list<int> path): tn(tn), path(path) {}
    };
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        queue<Node> q;
        q.push(Node(root, list<int> {root->val}));
        while(!q.empty()) {
            Node node = q.front(); q.pop();
            if(!node.tn->left && !node.tn->right) {
                string s;
                auto it = node.path.begin();
                s += to_string(*it);
                for(it++; it != node.path.end(); it++) {
                    s += "->" + to_string(*it);
                }
                ans.push_back(s);
            } else {
                if(node.tn->left) {
                    Node left(node.tn->left, node.path);
                    left.path.push_back(node.tn->left->val);
                    q.push(left);
                }
                if(node.tn->right) {
                    Node right(node.tn->right, node.path);
                    right.path.push_back(node.tn->right->val);
                    q.push(right);
                }
            }
        }
        return ans;
    }
};
