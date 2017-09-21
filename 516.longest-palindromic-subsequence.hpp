class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty()) return 0;
        int n = s.length();
        vector<vector<int>> f(n, vector<int>(n));
        for(int i = n - 1; i >= 0; i--) {
            f[i][i] = 1;
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j])
                    f[i][j] = f[i+1][j-1] + 2;
                else
                    f[i][j] = max(f[i][j-1], f[i+1][j]);
            }
        }
        return f[0][n-1];
    }
};
