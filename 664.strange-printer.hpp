class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        if(n == 0) return 0;
        vector<vector<int>> f(n, vector<int>(n));
        for(int l = 0; l < n; l++) {
            for(int i = 0; i + l < n; i++) {
                int j = i + l;
                f[i][j] = 1 + (i < j ? f[i+1][j] : 0);
                for(int k = i+1; k <= j; k++) {
                    if(s[i] == s[k]) {
                        f[i][j] = min(f[i][j], f[i][k-1] + (k < j ? f[k+1][j] : 0));
                    }
                }
            }
        }
        return f[0][n-1];
    }
};
