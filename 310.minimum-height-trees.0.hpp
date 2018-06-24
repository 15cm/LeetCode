class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1) return {0};
        vector<unordered_set<int>> adj(n);
        for(auto &e: edges) {
            adj[e.first].insert(e.second);
            adj[e.second].insert(e.first);
        }
        vector<int> nodes;
        for(int i = 0; i < n; i++) {
            if(adj[i].size() == 1) {
                nodes.push_back(i);
            }
        }
        vector<int> tnodes;
        while(n > 2) {
            n -= nodes.size();
            tnodes.clear();
            for(auto u: nodes) {
                for(auto v: adj[u]) {
                    adj[v].erase(u);
                    if(adj[v].size() == 1) {
                        tnodes.push_back(v);
                    }
                }
            }
            tnodes.swap(nodes);
        }
        return nodes;
    }
};
