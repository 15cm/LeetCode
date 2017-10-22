class Solution {
    vector<list<int>> edgeTo;
    vector<vector<int>> adj;
    int s, t;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        s = 0, t = -1;
        int V = wordList.size() + 1;
        adj = vector<vector<int>>(V);
        edgeTo = vector<list<int>>(V);
        for(int i = 0; i < wordList.size(); i++) {
            int v = i + 1;
            if(diff(beginWord, wordList[i]) == 1) {
                addEdge(s, v);
            }
            if(diff(endWord, wordList[i]) == 0) {
                t = v;
            }
            for(int j = i + 1; j < wordList.size(); j++) {
                int vj = j + 1;
                if(diff(wordList[i], wordList[j]) == 1) {
                    addEdge(v, vj);
                }
            }
        }
        if(t == -1) return vector<vector<string>>();

        list<int> l;
        vector<bool> vis(V);
        vector<bool> inQ(V);
        l.push_front(s);
        inQ[s] = true;
        vis[s] = true;
        bool reached = false;

        while(!l.empty()) {
            int sz = l.size();
            while(sz--) {
                int u = l.back(); l.pop_back();
                if(u == t) {
                    reached = true;
                    break;
                }
                for(int v: adj[u]) {
                    if(!vis[v]) {
                        edgeTo[v].push_back(u);
                        if(!inQ[v]) {
                            inQ[v] = true;
                            l.push_front(v);
                        }
                    }
                }
            }
            if(reached) break;
            for(int u: l) {
                vis[u] = true;
            }
        }

        vector<vector<string>> ans;
        list<int> path;
        getPath(t, path, ans, beginWord, wordList);
        return ans;
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int diff(string& s1, string& s2) {
        if(s1.length() != s2.length()) return -1;
        int n = s1.length();
        int i = 0;
        while(i < n) {
            if(s1[i] != s2[i]) break;
            i++;
        }
        if(i == n) return 0;
        for(int j = i + 1; j < n; j++)
            if(s1[j] != s2[j]) return -1;
        return 1;
    }
    void getPath(int u, list<int>& path, vector<vector<string>>& ans, string& beginWord, vector<string>& words) {
        if(u == s) {
            vector<string> tmp {beginWord};
            for(int id: path) {
                tmp.push_back(words[id - 1]);
            }
            ans.push_back(tmp);
            return;
        }
        path.push_front(u);
        for(int v: edgeTo[u]) {
            getPath(v, path, ans, beginWord, words);
        }
        path.pop_front();
    }
};
