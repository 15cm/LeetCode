class Solution {
public:
    vector<vector<int>> adj;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int V = wordList.size() + 1;
        adj = decltype(adj)(V);
        int s = 0, t;
        for(int i = 0; i < n; i++) {
            if(wordList[i] == endWord) t = i + 1;
            if(hasPath(beginWord, wordList[i]))
                addPath(0, i + 1);
            for(int j = 0; j < n; j++)
                if(i != j && hasPath(wordList[i], wordList[j]))
                    addPath(i + 1, j + 1);
        }

        queue<int> q;
        vector<bool> vis(V);
        vector<int> d(V);
        d[s] = 1;
        vis[s] = true;
        q.push(s);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(u == t) return d[u];
            for(auto v: adj[u])
                if(!vis[v]) {
                    vis[v] = true;
                    d[v] = d[u] + 1;
                    q.push(v);
                }
        }
        return 0;
    }
    bool hasPath(const string& s1, const string& s2) {
        int cnt = 0;
        for(int i = 0; i < s1.length(); i++)
            if(s1[i] != s2[i]) cnt++;
        return cnt <= 1;
    }
    void addPath(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};
