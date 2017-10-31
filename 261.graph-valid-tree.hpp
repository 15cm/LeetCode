class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& pr: edges) {
            int u = pr.first, v = pr.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n);

        if(!dfs(0, -1, vis, adj)) return false;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) return false;
        }
        return true;
    }
    bool dfs(int u, int parent, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[u] = true;
        for(int v: adj[u]) {
            if(v != parent && vis[v] || !vis[v] && !dfs(v, u, vis, adj)) return false;
        }
        return true;
    }
};
