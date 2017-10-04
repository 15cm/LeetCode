/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
typedef UndirectedGraphNode Node;
class Solution {
    unordered_map<int, Node*> mp;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        queue<Node*> q;
        Node *start = new Node(node->label);
        mp[node->label] = start;
        q.push(node);
        while(!q.empty()) {
            Node* u = q.front(); q.pop();
            for(Node *v: u->neighbors) {
                if(!mp.count(v->label)) {
                    Node *w = new Node(v->label);
                    mp[v->label] = w;
                    mp[u->label]->neighbors.push_back(w);
                    q.push(v);
                } else {
                    mp[u->label]->neighbors.push_back(mp[v->label]);
                }
            }
        }
        return start;
    }
};
