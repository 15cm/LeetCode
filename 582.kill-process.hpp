class Solution {
    unordered_map<int, vector<int>> adj;
    unordered_set<int> vis;
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        for(int i = 0; i < n; i++) {
            adj[ppid[i]].push_back(pid[i]);
        }
        dfs(kill);
        return vector<int>(vis.begin(), vis.end());
    }
    void dfs(int u) {
        if(vis.count(u)) return;
        vis.insert(u);
        if(adj.count(u)) {
          for(int v: adj[u]) {
            dfs(v);
          }
        }
    }
};
