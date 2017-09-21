class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty()) return 0;
        int n = s.length(), cnt = n;
        vector<vector<bool>> f(n ,vector<bool>(n));
        for(int i = 0; i < n; i++) f[i][i] = true;
        for(int i = 1; i < n; i++)
            if(f[i-1][i] = (s[i-1] == s[i]))
                cnt++;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 2; j < n; j++) {
                if(f[i][j] = (s[i] == s[j]) && f[i+1][j-1]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
