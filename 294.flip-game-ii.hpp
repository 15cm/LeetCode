class Solution {
    unordered_map<string, bool> memo;
public:
    bool canWin(string s) {
        int n = s.length();
        string t(n, '-');
        memo[t] = false;
        for(int i = 0; i < n; i++) {
            t[i] = '+';
            memo[t] = false;
            for(int j = i + 2; j < n; j++) {
                t[j] = '+';
                memo[t] = false;
                t[j] = '-';
            }
            t[i] = '-';
        }
        return dfs(s);
    }
    bool dfs(string& s) {
        if(memo.count(s)) {
            return memo[s];
        }
        bool res = false;
        for(int i = 1; i < s.length(); i++) {
            if(s[i-1] == '+' && s[i] == '+') {
                s[i-1] = s[i] = '-';
                if(!dfs(s)) {
                    res = true;
                    s[i-1] = s[i] = '+';
                    break;
                }
                s[i-1] = s[i] = '+';
            }
        }
        return memo[s] = res;
    }
};
