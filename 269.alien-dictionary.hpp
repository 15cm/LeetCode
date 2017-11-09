class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<set<int>> adjtmp(26);
        vector<bool> alphabet(26);
        for(auto& word: words)
            for(char& c: word)
                alphabet[c - 'a'] = true;
        for(int i = 0; i < words.size() - 1; i++) {
            string& s = words[i], &t = words[i+1];
            for(int p = 0; p < min(s.length(), t.length()); p++) {
                if(s[p] != t[p]) {
                    adjtmp[s[p] - 'a'].insert(t[p] - 'a');
                    break;
                }
            }
        }

        vector<vector<int>> adj(26);
        for(int i = 0; i < 26; i++) {
            adj[i] = vector<int>(adjtmp[i].begin(), adjtmp[i].end());
        }

        list<char> topo;
        vector<int> vis(26);
        for(int i = 0; i < 26; i++) {
            if(alphabet[i] && !vis[i])
                if(!topoSort(i, topo, vis, adj)) {
                    topo.clear();
                    break;
                }
        }
        return string(topo.begin(), topo.end());
    }

    bool topoSort(int u, list<char>& topo, vector<int>& vis, vector<vector<int>>& adj) {
        vis[u] = -1;
        for(int v: adj[u]) {
            if(vis[v] == -1 || !vis[v] && !topoSort(v, topo, vis, adj))
                return false;
        }
        vis[u] = 1;
        topo.push_front(u + 'a');
        return true;
    }
};
