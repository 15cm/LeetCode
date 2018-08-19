class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int src = 0, dst = -1;
        int n = wordList.size() + 1;
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            string &s = (i == 0 ? beginWord : wordList[i - 1]);
            if(s == endWord) dst = i;
            for(int j = i + 1; j < n; j++) {
                string &t = wordList[j - 1];
                if(hasPath(s, t)) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        if(dst == -1) return {};

        vector<int> dist(n, -1);
        vector<vector<int>> path(n);
        queue<int> q;
        int d = 0;

        q.push(src);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int cur = q.front(); q.pop();
                for(int next: adj[cur]) {
                    if(dist[next] == -1 || d < dist[next]) {
                        dist[next] = d;
                        path[next].push_back(cur);
                        q.push(next);
                    } else if(d == dist[next]) {
                        path[next].push_back(cur);
                    }
                }
            }
            d++;
        }

        auto ans = getPaths(dst, src, path, beginWord, wordList);
        for(auto &path: ans)
            reverse(path.begin(), path.end());
        return ans;
    }
    bool hasPath(string &s, string &t) {
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                for(int j = i + 1; j < n; j++)
                    if(s[j] != t[j]) return false;
                return true;
            }
        }
        return false;
    }
    vector<vector<string>> getPaths(int cur, int end, vector<vector<int>> &path, string &beginWord, vector<string> &words) {
        if(cur == end) {
            return {{beginWord}};
        }
        vector<vector<string>> res;
        for(int p: path[cur]) {
            for(auto path: getPaths(p, end, path, beginWord, words)) {
                vector<string> tmp {words[cur - 1]};
                tmp.insert(tmp.end(), path.begin(), path.end());
                res.push_back(tmp);
            }
        }
        return res;
    }
};
