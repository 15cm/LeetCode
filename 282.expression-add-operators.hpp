class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if(num.empty()) return ans;
        dfs(num, 0, target, 0, 0, "", ans);
        return ans;
    }
    void dfs(string num, int cur, int target, long eval, long multed, string path, vector<string>& ans) {
        int n = num.size();
        if(cur == n) {
            if(target == eval) ans.push_back(path);
            return;
        }
        for(int i = cur; i < n; i++) {
            if(i != cur && num[cur] == '0') break;
            string s = num.substr(cur, i - cur + 1);
            long val = stol(s);
            if(cur == 0) {
                dfs(num, i + 1, target, val, val, path + s, ans);
            } else {
                dfs(num, i + 1, target, eval + val, val, path + '+' + s, ans);
                dfs(num, i + 1, target, eval - val, -val, path + '-' + s, ans);
                dfs(num, i + 1, target, eval - multed + multed * val, multed * val, path + '*' + s, ans);
            }
        }
    }
};
