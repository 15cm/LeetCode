class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        list<string> l;
        auto isPalindrome = getIsPalindrome(s);
        dfs(-1, l, isPalindrome, ans, s);
        return ans;
    }
    vector<vector<bool>> getIsPalindrome(const string& s) {
        int n = s.length();
        vector<vector<bool>> f(n, vector<bool>(n));
        for(int i = 0; i < n; i++)
            f[i][i] = true;
        for(int i = 0; i < n - 1; i++)
            f[i][i + 1] = s[i] == s[i + 1];
        for(int len = 2; len < s.length(); len++)
            for(int i = 0; i + len < s.length(); i++)
                f[i][i + len] = f[i + 1][i + len - 1] && s[i] == s[i + len];
        return f;
    }
    void dfs(int cur, list<string>& pts, const vector<vector<bool>>& isPalindrome, vector<vector<string>>& ans, const string& s) {
        if(cur == s.length() - 1) {
            ans.push_back(vector<string>(pts.begin(), pts.end()));
        }
        for(int i = 1; i + cur < s.length(); i++) {
            if(isPalindrome[cur + 1][cur + i]) {
                pts.push_back(s.substr(cur + 1, i));
                dfs(cur + i, pts, isPalindrome, ans, s);
                pts.pop_back();
            }
        }
    }
};
