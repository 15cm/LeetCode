class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return helper(0, s, 0, p, memo);
    }
    bool helper(int i, string& s, int j, string& p, vector<vector<int>>& memo) {
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        int m = s.length(), n = p.length();
        bool res = false;
        if(j == n) res = i == m;
        else {
            bool firstMatch = i < m && (s[i] == p[j] || p[j] == '.');
            if(j + 1 < n && p[j+1] == '*') {
                res = firstMatch && helper(i + 1, s, j, p, memo) || helper(i, s, j + 2, p, memo);
            } else {
                res = firstMatch && helper(i + 1, s, j + 1, p, memo);
            }
        }
        return memo[i][j] = res;
    }
};
