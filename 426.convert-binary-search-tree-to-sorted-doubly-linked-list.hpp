/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
    Node *prev = NULL, *head = NULL;
public:
    Node* treeToDoublyList(Node* root) {
        inorder(root);
        if(head) {
            head->left = prev;
            prev->right = head;
        }
        return head;
    }
    void inorder(Node *node) {
        if(!node) return;
        inorder(node->left);
        if(!prev) {
            head = node;
        } else {
            prev->right = node;
            node->left = prev;
        }
        prev = node;
        inorder(node->right);
    }
};
