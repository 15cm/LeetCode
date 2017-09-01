/**
 * Definition for undirected graph.
 *  struct UndirectedGraphNode {
 *  int label;
 *  vector<UndirectedGraphNode *> neighbors;
 *  UndirectedGraphNode(int x) : label(x) {};
 };
 */
class Solution {
public:
    unordered_map<int, UndirectedGraphNode *> mp;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return node;
        if(mp.find(node->label) == mp.end()) {
            UndirectedGraphNode *x = new UndirectedGraphNode(node->label);
            mp[node->label] = x;
            for(auto& nb: node->neighbors) {
                x->neighbors.push_back(cloneGraph(nb));
            }
            return x;
        } else {
            return mp[node->label];
        }
    }
};
