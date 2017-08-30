#include <vector>
#include <queue>
#include <list>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        if(wordList.empty()) return ans;

        vector<string> words(wordList);
        words.insert(words.begin(), beginWord);
        int n = words.size();
        int s = 0, t = -1;
        adj = vector<vector<int>>(n);

        for(int i = 0; i < n; i++) {
            if(words[i] == endWord) t = i;
            for(int j = i + 1; j < n; j++)
                if(hasPath(words[i], words[j]))
                    addEdge(i, j);
        }
        if(t == -1) return ans;

        queue<int> q;
        vector<vector<int>> p(n);
        vector<int> d(n);
        vector<bool> vis(n);
        vector<bool> inq(n);
        q.push(0);
        d[0] = 1;
        vis[0] = true;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(u == t) break;
            inq[u] = false;
            for(int v: adj[u])
                if(!vis[v]) {
                    vis[v] = true;
                    d[v] = d[u] + 1;
                    if(!inq[v]) {
                        inq[v] = true;
                        q.push(v);
                        p[v].push_back(u);
                    }
                } else if(d[u] + 1 == d[v] && inq[v]) {
                    p[v].push_back(u);
                }
        }

        buildPath(s, t, list<string>{words[t]}, ans, p, words);
        return ans;
    }
    bool hasPath(const string& s1, const string& s2) {
        int cnt = 0;
        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] != s2[i]) cnt++;
        }
        return cnt == 1;
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void buildPath(int start, int to, const list<string>& path, vector<vector<string>>& ans, const vector<vector<int>> paths, const vector<string>& words) {
        if(to == start) {
            if(!path.empty())
                ans.push_back(vector<string>(path.begin(), path.end()));
        } else {
            for(int from: paths[to]) {
                auto tmp = path;
                tmp.push_front(words[from]);
                buildPath(start, from, tmp, ans, paths, words);
            }
        }
    }
};
