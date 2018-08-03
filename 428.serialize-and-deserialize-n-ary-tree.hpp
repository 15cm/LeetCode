/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        stringstream ss;
        serializeHelper(root, ss);
        return ss.str();
    }

    void serializeHelper(Node *node, stringstream &ss) {
        if(!node) {
            ss << "# ";
            return;
        }
        ss << node->val << " " << node->children.size() << " ";
        for(auto child: node->children) {
            serializeHelper(child, ss);
        }
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
    Node *deserializeHelper(stringstream &ss) {
        string s;
        ss >> s;
        if(s == "#") {
            return NULL;
        }
        auto node = new Node(stoi(s), {});
        ss >> s;
        int n = stoi(s);
        for(int i = 0; i < n; i++) {
            node->children.push_back(deserializeHelper(ss));
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
