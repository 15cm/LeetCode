class Solution {
public:
    string encode(string s) {
        int n = s.size();
        if(n <= 4) return s;
        vector<vector<string>> dp(n, vector<string>(n));
        for(int l = 1; l <= n; l++) {
            for(int i = 0, j = i + l - 1; j < n; i++, j++) {
                auto& cur = dp[i][j];
                string t = s.substr(i, l);
                cur = t;
                if(l <= 4) continue;

                int patlen = kmp(t);
                if(patlen != -1) {
                    auto next = to_string(t.size() / patlen) + "[" + dp[i][i + patlen - 1] + "]";
                    if(next.size() < cur.size()) {
                        cur = next;
                    }
                }

                for(int k = i; k < j; k++) {
                    auto& left = dp[i][k], &right = dp[k+1][j];
                    if(left.size() + right.size() < cur.size()) {
                        cur = left + right;
                    }
                }
            }
        }
        return dp[0][n-1];
    }
    int kmp(const string& s) {
        int n = s.size();
        vector<int> fail(n);
        for(int i = 0, j = -1; i < n; i++, j++) {
            fail[i] = j;
            while(j >= 0 && s[i] != s[j])
                j = fail[j];
        }
        int len = fail[n-1] + 1;
        if(len == 0 || s[len-1] != s[n-1] ) return -1;
        int patlen = n - len;
        return n % patlen == 0 ? patlen : -1;
    }
};
