/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *prev = NULL, *p = head;
        if(!head) {
            head = new Node(insertVal, NULL);
            head->next = head;
        } else if(head == head->next) {
            head->next = new Node(insertVal, head);
        } else {
            while(true) {
                prev = p;
                p = p->next;
                if(p->val <= prev->val) {
                    if((insertVal < p->val) == (insertVal < prev->val)) break;
                } else {
                    if(prev->val <= insertVal && insertVal <= p->val) break;
                }
            }
            auto x = new Node(insertVal, p);
            prev->next = x;
        }
        return head;
    }
};
