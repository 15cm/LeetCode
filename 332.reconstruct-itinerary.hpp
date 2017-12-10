class Solution {
    map<string, priority_queue<string, vector<string>, std::greater<string>>> adj;
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(auto& pr: tickets) {
            adj[pr.first].push(pr.second);
        }
        list<string> ans;
        dfs("JFK", ans);
        return vector<string>(ans.begin(), ans.end());
    }

    void dfs(string u, list<string>& ans) {
        while(!adj[u].empty()) {
            string v = adj[u].top();
            adj[u].pop();
            dfs(v, ans);
        }
        ans.push_front(u);
    }
};
