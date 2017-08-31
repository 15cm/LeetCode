class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        auto isPalindrome = getIsPalindrome(s);
        vector<int> f(n + 1);
        for(int i = 0; i <= n; i++) {
            f[i] = i;
            for(int j = 0; j < i; j++)
                if(isPalindrome[j][i - 1])
                    f[i] = min(f[i], f[j] + 1);
        }
        return f[n] - 1;
    }
    vector<vector<bool>> getIsPalindrome(const string& s) {
        int n = s.length();
        vector<vector<bool>> f(n, vector<bool>(n));
        for(int i = 0; i < n; i++) f[i][i] = true;
        for(int i = 0; i < n - 1; i++) f[i][i + 1] = s[i] == s[i + 1];
        for(int step = 2; step < s.length(); step++)
            for(int i = 0; i + step < s.length(); i++) {
                int j = i + step;
                f[i][j] = f[i + 1][j - 1] && s[i] == s[j];
            }
        return f;
    }
};
