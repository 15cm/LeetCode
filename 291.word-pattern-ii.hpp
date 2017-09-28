class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, int> p2i;
        unordered_map<string, int> s2i;
        return dfs(0, 0, p2i, s2i, pattern, str);
    }
    bool dfs(int curP, int curS, unordered_map<char, int>& p2i, unordered_map<string, int>& s2i,  string& pattern, string& str) {
        int n = pattern.size(), m = str.size();
        if(curP == n || curS == m) return curP ==n && curS == m;
        bool res = false;
        char pkey = pattern[curP];
        int pval = p2i[pkey];
        for(int i = 1; curS + i <= m; i++) {
            string skey = str.substr(curS, i);
            int sval = s2i[skey];
            if(sval != pval) continue;
            p2i[pkey] = s2i[skey] = curP + 1;
            res |= dfs(curP + 1, curS + i, p2i, s2i, pattern, str);
            p2i[pkey] = pval;
            s2i[skey] = sval;
        }
        return res;
    }
};
