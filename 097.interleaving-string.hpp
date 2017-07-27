class Solution {
public:
    unordered_map<string, bool> mp;
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if(n1 + n2 != n3) return false;
        if(s1.empty()) return s2 == s3;
        if(s2.empty()) return s1 == s3;
        vector<vector<bool>> f(n1 + 1, vector<bool>(n2 + 1, false));
        for(int i = 0; i < n1; i++)
            f[i][n2] = s1.substr(i) == s3.substr(n2 + i);
        for(int i = 0; i < n2; i++)
            f[n1][i] = s2.substr(i) == s3.substr(n1 + i);
        f[n1][n2] = true;
        for(int i = n1 - 1; i >= 0; i--)
            for(int j = n2 - 1; j >= 0; j--)
                f[i][j] = (s1[i] == s3[i + j] && f[i + 1][j])
                    || (s2[j] == s3[i + j] && f[i][j + 1]);
        return f[0][0];
    }
};
