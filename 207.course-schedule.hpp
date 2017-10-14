class Solution {
public:
    vector<vector<int>> adj;
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        adj = vector<vector<int>>(numCourses);
        for(auto& e: prerequisites) {
            adj[e.first].push_back(e.second);
        }
        vector<int> vis(numCourses);
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(!dfs(i, vis))
                    return false;
            }
        }
        return true;
    }
    bool dfs(int u, vector<int>& vis) {
        if(vis[u] == -1) return false;
        if(vis[u] == 1) return true;
        vis[u] = -1;
        for(int v: adj[u]) {
            if(!dfs(v, vis))
                return false;
        }
        vis[u] = 1;
        return true;
    }
};
