typedef vector<int> VI;
typedef vector<VI> VVI;
class Solution {
public:
    VVI adj;
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        adj = VVI(numCourses);
        for(auto& e: prerequisites) {
            adj[e.second].push_back(e.first);
        }

        VI vis(numCourses);
        list<int> topo;
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i] && !dfs(i, vis, topo)) {
                break;
            }
        }
        return VI(topo.begin(), topo.end());
    }

    bool dfs(int u, VI& vis, list<int>& topo) {
        if(vis[u] == -1) {
            topo.clear();
            return false;
        }
        if(vis[u] == 1) return true;
        vis[u] = -1;
        for(int v: adj[u]) {
            if(!dfs(v, vis, topo))
                return false;
        }
        topo.push_front(u);
        vis[u] = 1;
        return true;
    }
};
