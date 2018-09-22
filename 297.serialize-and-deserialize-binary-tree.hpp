/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);
        ss << root->val;
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            for(int i = 0; i < 2; i++) {
                auto p = (i == 0 ? u->left : u->right);
                ss << " ";
                if(p) {
                    q.push(p);
                    ss << p->val;
                } else {
                    ss << "null";
                }
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        stringstream ss(data);
        int val;
        ss >> val;
        auto root = new TreeNode(val);
        queue<TreeNode*> q;
        q.push(root);
        string s;
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            TreeNode *t;
            for(int i = 0; i < 2; i++) {
                auto &p = (i == 0 ? u->left : u->right);
                if(ss >> s) {
                    if(s == "null") t = NULL;
                    else {
                        t = new TreeNode(stoi(s));
                        q.push(t);
                    }
                    p = t;
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
