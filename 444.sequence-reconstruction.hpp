class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<unordered_set<int>> adj(n+1);
        vector<int> deg(n+1, -1);
        for(auto& seq: seqs) {
            int m = seq.size();
            if(m > n) return false;
            if(m > 0) {
                int u = seq[0];
                if(u > n) return false;
                if(deg[u] < 0) deg[u] = 0;
            }
            for(int i = 0; i < m-1; i++) {
                int u = seq[i], v = seq[i+1];
                if(v > n) return false;
                if(deg[v] < 0) deg[v] = 0;
                auto& st = adj[u];
                if(!st.count(v)) {
                    deg[v]++;
                    adj[u].insert(v);
                }
            }
        }
        queue<int> q;
        for(int i = 1; i <= n; i++) {
            if(deg[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty()) {
            if(q.size() > 1) return false;
            auto u = q.front();
            q.pop();
            for(auto v: adj[u]) {
                if(--deg[v] == 0) {
                    q.push(v);
                }
            }
            ans.push_back(u);
        }
        return ans == org;
    }
};
