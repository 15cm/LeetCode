class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> degree;

        for(auto& s: words)
            for(auto& c: s)
                degree[c] = 0;

        int n = words.size();
        for(int i = 0; i < n - 1; i++) {
            string& s = words[i], &t = words[i+1];
            for(int j = 0; j < min(s.length(), t.length()); j++) {
                if(s[j] != t[j]) {
                    if(!adj[s[j]].count(t[j])) {
                        adj[s[j]].insert(t[j]);
                        degree[t[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for(auto& pr: degree) {
            if(pr.second == 0) q.push(pr.first);
        }
        string ans;
        while(!q.empty()) {
            char u = q.front(); q.pop();
            ans.push_back(u);
            if(adj.count(u)) {
                for(char v: adj[u]) {
                    degree[v]--;
                    if(degree[v] == 0) q.push(v);
                }
            }
        }
        return ans.length() == degree.size() ? ans : "";
    }
};
