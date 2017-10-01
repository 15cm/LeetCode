class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs("", ans, n, n, 0);
        return ans;
    }
    void dfs(string path, vector<string>& ans, int left, int right, int cnt) {
        if(left == 0 && right == 0) ans.push_back(path);
        if(cnt > 0 && right > 0) dfs(path + ')', ans, left, right - 1, cnt - 1);
        if(left > 0) dfs(path + '(', ans, left - 1, right, cnt + 1);
    }
};
