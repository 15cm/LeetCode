class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if(k == 0) return ans;
        list<int> path;
        dfs(1, 9, k, path, n, ans);
        return ans;
    }
    void dfs(int cur, int n, int k, list<int>& path, int target, vector<vector<int>>& ans) {
        if(k == 0 && target == 0) {
            ans.push_back(vector<int>(path.begin(), path.end()));
        }
        if(k == 0 || target == 0 || cur > n) return;
        dfs(cur + 1, n, k, path, target, ans);
        if((target -= cur) < 0) return;
        path.push_back(cur);
        dfs(cur + 1, n, k - 1, path, target, ans);
        path.pop_back();
    }
};
