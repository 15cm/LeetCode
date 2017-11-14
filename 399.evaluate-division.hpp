struct Edge {
    string to;
    double val;
    Edge(string to, double val): to(to), val(val) {}
};

class Solution {
    unordered_map<string, vector<Edge>> adj;
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        for(int i = 0; i < equations.size(); i++) {
            auto &u = equations[i].first, &v = equations[i].second;
            double val = values[i];
            adj[u].push_back(Edge(v, val));
            adj[v].push_back(Edge(u, 1/val));
        }
        vector<double> ans;
        for(auto& pr: queries) {
            unordered_set<string> vis;
            double res = -1;
            if(adj.count(pr.first)) {
                dfs(pr.first, pr.second, 1, vis, res);
            }
            ans.push_back(res);
        }
        return ans;
    }
    bool dfs(string u, string& dst, double path, unordered_set<string>& vis, double& res) {
        if(u == dst) {
            res = path;
            return true;
        }
        vis.insert(u);
        if(adj.count(u)) {
            for(auto& edge: adj[u]) {
                string& v = edge.to;
                double val = edge.val;
                if(!vis.count(v) && dfs(v, dst, path * val, vis, res))
                    return true;
            }
        }
        return false;
    }
};
