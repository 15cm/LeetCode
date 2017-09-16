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
        list<string> l;
        string s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto x = q.front(); q.pop();
            if(x) {
                s += to_string(x->val) + ",";
                q.push(x->left);
                q.push(x->right);
            } else {
                s += "null,";
            }
        }
        return s.substr(0, s.length() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        stringstream ss(data);
        string s;
        queue<TreeNode*> q;
        getline(ss, s, ',');
        auto root = new TreeNode(stoi(s));
        q.push(root);
        while(getline(ss, s, ',')) {
            auto x = q.front(); q.pop();
            if(x->left = createNode(s)) q.push(x->left);
            if(getline(ss, s, ',')) {
                if(x->right = createNode(s)) q.push(x->right);
            }
        }
        return root;
    }
    TreeNode* createNode(string s) {
        return s == "null" ? NULL : new TreeNode(stoi(s));
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
