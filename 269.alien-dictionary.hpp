class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<int, unordered_set<int>> edges;
        int n = words.size();
        for(string& s: words) {
            for(char c: s) {
                edges[c - 'a'] = unordered_set<int>();
            }
        }
        for(int i = 0; i < n - 1; i++) {
            string& s1 = words[i], &s2 = words[i + 1];
            for(int j = 0; j < min(s1.length(), s2.length()); j++) {
                if(s1[j] != s2[j]) {
                    int idx1 = s1[j] - 'a', idx2 = s2[j] - 'a';
                    if(!edges[idx1].count(idx2)) {
                        edges[idx1].insert(idx2);
                    }
                    break;
                }
            }
        }

        vector<int> vis(26);
        stack<char> topo;
        for(int i = 0; i < 26; i++) {
            if(edges.count(i) && vis[i] == 0) {
                if(!topologicalSort(i, vis, edges, topo)) {
                    stack<char> tmp;
                    topo.swap(tmp);
                    break;
                } 
            }
        }
        string ans;
        while(!topo.empty()) {
            ans.push_back(topo.top());
            topo.pop();
        }
        return ans;
    }
    bool topologicalSort(int u, vector<int>& vis, unordered_map<int, unordered_set<int>>& edges, stack<char>& topo) {
        vis[u] = -1;
        for(char v: edges[u]) {
            if(vis[v] == -1) return false;
            if(vis[v] == 1) continue;
            if(!topologicalSort(v, vis, edges, topo))
                return false;;
        }
        vis[u] = 1;
        topo.push(u + 'a');
        return true;
    }
};
