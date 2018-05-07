struct vector_hash {
    size_t operator() (const vector<int>& v) const {
        size_t hash = 0;
        int mask = 0x7;
        for(int x: v) {
            hash |= x & mask;
            mask <<= 3;
        }
        return hash;
    }
};
class Solution {
    unordered_map<string, unordered_map<vector<int>, int, vector_hash>> memo;
    vector<int> char2index = vector<int>(128);
public:
    int findMinStep(string board, string hand) {
        char2index['R'] = 0;
        char2index['Y'] = 1;
        char2index['B'] = 2;
        char2index['G'] = 3;
        char2index['W'] = 4;
        vector<int> cnts(5);
        for(auto c: hand) cnts[char2index[c]]++;
        return dfs(board, cnts);
    }
    int dfs(string s, vector<int>& cnts) {
        if(s.empty()) return 0;
        if(memo.count(s) && memo[s].count(cnts)) return memo[s][cnts];
        int res = INT_MAX;
        int n = s.size();
        for(int i = 0, cnt = 1; i < n; i++) {
            if(i + 1 < n && s[i] == s[i+1]) cnt++;
            else {
                string s2 = s;
                int rc = -1;
                if(cnt >= 3) {
                    s2.erase(i - cnt + 1, cnt);
                    rc = dfs(s2, cnts);
                } else {
                    int index = char2index[s[i]];
                    if(cnts[index] + cnt >= 3) {
                        s2.erase(i - cnt + 1, cnt);
                        int d = 3 - cnt;
                        cnts[index] -= d;
                        rc = dfs(s2, cnts);
                        if(rc != -1)
                            rc += d;
                        cnts[index] += d;
                    }
                }
                if(rc != -1) {
                    res = min(res, rc);
                }
                cnt = 1;
            }
        }
        return memo[s][cnts] = (res == INT_MAX ? -1 : res);
    }
};
