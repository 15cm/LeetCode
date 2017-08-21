class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        int f[n+1][m+1];
        for(int i = 1; i <= n; i++) f[i][0] = 0;
        for(int i = 0; i <= m; i++) f[0][i] = 1;
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j++)
                f[i][j] = s[j-1] == t[i-1] ? f[i-1][j-1] + f[i][j-1] : f[i][j-1];
        return f[n][m];
    }
};
