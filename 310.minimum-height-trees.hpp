typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef queue<int> QI;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        // Init
        VI ans;
        VVI adj(n);
        QI q;
        VI d(n, -1), pathTo(n);
        for(auto& pr: edges) {
            int u = pr.first, v = pr.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // Find one endpoint of longest path
        int start = 0;
        q.push(0);
        d[0] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            start = u;
            
            for(int v: adj[u]) {
                if(d[v] == -1) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }

        // Find longest path
        int maxd = 0, end = start;
        q = QI();
        fill(d.begin(), d.end(), -1);
        q.push(start);
        d[start] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            maxd = d[u];
            end = u;

            for(int v: adj[u]) {
                if(d[v] == -1) {
                    pathTo[v] = u;
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }

        // Find mid points
        int s = end;
        for(int i = 0; i < maxd / 2; i++) {
            s = pathTo[s];
        }
        ans.push_back(s);
        if(maxd & 1) {
            ans.push_back(pathTo[s]);
        }

        return ans;
    }
};
